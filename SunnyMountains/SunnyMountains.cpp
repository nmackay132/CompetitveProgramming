/*
*****Solved*****
UVa 920

Problem Type:
geometry, line intersection
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
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

// coefficiants of ax + by + c = 0
struct line {
	double a, b, c;
	line() { a = 0, b = 1, c = 0; } // default is x-axis
	line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

struct point{ // use when points are doubles
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {	// override less than operator
		if (fabs(x - other.x) > EPS)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point other) const{
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

// the answer is stored in the third parameter by reference
void pointsToLine(point p1, point p2, line &l){
	if (p1.x - p2.x == 0){
		l.a = 1.0;  l.b = 0.0;  l.c = -p1.x;
	}
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

// calc distance between two points
double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areIntersect(line l1, line l2, point &p){
	if (areParallel(l1, l2)) return false; // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return true;
}

vector<point> points;

int main(){

	int T;
	scanf("%d", &T);
	while (T--){
		int N; scanf("%d", &N);
		points.clear();
		for (int i = 0; i < N; i++)	{
			int x, y; scanf("%d %d", &x, &y);
			point p = point(x, y);
			points.push_back(p);
		}
		sort(points.rbegin(), points.rend()); // sort in ascending order
		//for (int i = 0; i < N; i++) {
		//	printf("(%d %d) ", points[i].x, points[i].y);
		//}
		//printf("\n");

		double total = 0;
		point maxYPoint = point(0, 0);
		for (int i = 1; i < N; i++) {
			if (points[i].y <= maxYPoint.y) continue;

			line horizontal = line(0, 1, -maxYPoint.y); // horizontal line
			line l1;
			pointsToLine(points[i - 1], points[i], l1);
			point crossPoint;
			if (areIntersect(horizontal, l1, crossPoint)){
				total += dist(crossPoint, points[i]);
				maxYPoint = points[i];
			}
		}

		printf("%.2lf\n", total);
	}

	return 0;
}

/*
2
11
1100 1200
0 500
1400 100
600 600
2800 0
400 1100
1700 600
1500 800
2100 300
1800 700
2400 500
2
0 1000
1000 0
*/