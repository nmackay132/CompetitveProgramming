/*
******Solved******
UVa 216

Problem Type:
dp, traveling salesman
*/
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <limits>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;

const int  MAX_INT = std::numeric_limits<int>::max();
const int  MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int  NEG_INF = -1000000000;

#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI acos(0)*2.0
#define EPS 1.0e-9
#define are_equal(a,b)fabs(a-b)<EPS
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

struct point{ // use when points are integers
	int x, y;
	point() { x = y = 0; }
	point(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (point other) const {	// override less than operator
		if (x != other.x)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point other) const {
		return (x == other.x && y == other.y);
	}
};

typedef pair<int, double> id;

int N;
vector<point> points;
double dist[10][10];
double memo[10][(1 << 10)];
id trace[10][(1 << 10)];


double tsp(int pos, int mask) {
	if (mask == (1 << N) - 1) {
		//printf("finished\n");
		return 0;
	}

	if (memo[pos][mask] != -1) return memo[pos][mask];

	double min = INF;
	int nxt = -1;
	//printf("pos=%d mask=%d\n", pos, mask);
	for (int i = 0; i < N; i++) {
		if (((1 << i) & mask) == 0) {

			double calc = dist[pos][i] + tsp(i, mask | (1 << i)) + 16;
			if (calc < min) {
				min = calc;
				nxt = i;
			}
		}
	}
	trace[pos][mask].first = nxt;
	trace[pos][mask].second = dist[pos][nxt];
	//printf("memo[%d][%d]=%d\n", pos, mask, min);
	return memo[pos][mask] = min;
}

int main(){
	int C = 1;
	while (scanf("%d", &N), N) {
		int x, y;
		points.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x, &y);
			points.push_back(point(x, y));
		}

		MEM(dist, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = hypot(points[i].x-points[j].x, points[i].y-points[j].y);
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < (1<<10); j++) {
				memo[i][j] = -1;
			}
		}

		double min = INF;
		int beg = -1;
		for (int i = 0; i < N; i++) {
			double calc = tsp(i, (1 << i));
			if (calc < min) {
				beg = i;
				min = calc;
			}
		}

		printf("**********************************************************\n");
		printf("Network #%d\n", C++);
		int nxt = beg;
		int mask = 1 << beg;
		int c = 1;
		while (c < N) {
			int curr = nxt;
			id temp = trace[nxt][mask];
			double d = temp.second;
			point currp = points[curr];
			nxt = temp.first;
			point nxtp = points[nxt];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", currp.x, currp.y, nxtp.x, nxtp.y, d+16);
			c++;
			mask = (1 << nxt) | mask;
		}

		printf("Number of feet of cable required is %.2lf.\n", min);
	}

	return 0;
}	
