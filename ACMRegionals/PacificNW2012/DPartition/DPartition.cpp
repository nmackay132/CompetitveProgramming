/*
*****Solved*****

Problem Type:
geometry
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

#define sc scanf
#define pf printf
#define mp make_pair
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define MEM(arr,val) memset(arr,val, sizeof arr)
#define REP(n) int decrement = n;while(decrement--)
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
#define are_equal(a,b) fabs(a-b)<EPS
#define LS(b) (b& (-b)) // Least significant bit
#define DEG_to_RAD(a) ((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

int N;
double W, H;

struct point{ // use when points are doubles
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {	// override less than operator
		if (fabs(x - other.x) > EPS)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

int main() {
	while (scanf("%d %lf %lf", &N, &W, &H), N || W || H) {
		vector<point> points;
		double x, y;
		point mid(W / 2, H / 2);
		vector<pair<double, int> > angles;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &x, &y);
			points.push_back(point(x, y));
			angles.push_back(mp(atan2(y - mid.y, x - mid.x) + PI, i));
		}

		if (N == 2) {
			printf("%d %d\n", (int)points[0].x, (int)points[1].y);
			continue;
		}

		sort(angles.begin(), angles.end());

		/*printf("angles=\n");
		for (int i = 0; i < angles.size(); i++) {
			printf("%lf\n", angles[i].first);
		}*/


		int first = -1;
		for (int i = 0; i < N; i++) {
			double st = angles[i].first;
			double end = st + PI;
			if (end >= 2 * PI)
				end -= 2 * PI;
			double a1 = angles[(i + N / 2 - 1 + N) % N].first;
			double a2 = angles[(i + N / 2 + N) % N].first;
			//printf("first=%lf\nend=%lf\n", first, end);
			if (st < end) {
				if ((a1 >= st && a1 <= end) && (a2 >= end || a2 <= st) ) {
					first = i;
					break;
				}
			}
			else {
				if ((a1 >= st || a1 <= end) && (a2 >= end && a2 <= st)) {
					first = i;
					break;
				}
			}
		}

		//printf("first=%d\n", first);
		for (int i = 0; i < N/2; i++) {
			int pi = angles[(first + i) % N].second;
			//printf("pi=%d\n", pi);
			printf("%d %d\n", (int)points[pi].x, (int)points[pi].y);
		}

	}

	return 0;
}
