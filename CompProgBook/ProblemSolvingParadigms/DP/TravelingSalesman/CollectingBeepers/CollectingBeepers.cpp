/*
*****Solved*****
UVa 10496

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

int W, H, N;
int dist[12][12];
point start;
vector<point> points;
int memo[12][(1 << 12)];

int tsp(int pos, int mask) {
	if (mask == (1 << points.size()) - 1) return dist[pos][0];
	if (memo[pos][mask] != -1) return memo[pos][mask];
	int min = INF;
	for (int i = 0; i < points.size(); i++) {
		if ( ((1<<i) & mask) == 0) {
			min = MIN(min, dist[pos][i] + tsp(i, mask | (1 << i) ));
		}
	}
	return memo[pos][mask] = min;
}

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		points.clear();
		scanf("%d %d", &W, &H);
		scanf("%d %d", &start.x, &start.y);
		points.push_back(start);
		scanf("%d", &N);
		int x, y;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x, &y);
			points.push_back(point(x, y));
		}

		MEM(dist, 0);
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < (1<<12); j++) {
				memo[i][j] = -1;
			}
		}
		for (int i = 0; i < points.size(); i++) {
			for (int j = 0; j < points.size(); j++) {
				dist[i][j] = abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y);
			}
		}

		int ans = tsp(0, 1);
		printf("The shortest path has length %d\n", ans);
	}

	return 0;
}	
