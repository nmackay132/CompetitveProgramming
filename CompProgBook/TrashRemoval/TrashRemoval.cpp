/*
*****Solved*****
UVa 1111

Problem Type:
geometry, polygons, convex hull
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

int N;

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

// calc distance between two points
double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

struct line{
	double a, b, c;
	line() {
		a = b = c = 0.0;
	}
	line(point p1, point p2) {
		if (are_equal(p1.x, p2.x)) {
			a = 1.0;
			b = 0.0;
			c = -p1.x;
		}
		else {
			a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
			b = 1.0;
			c = -(double)(p1.x*a) - p1.y;
		}
	}
};

// the answer is stored in the third parameter by reference
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) {
		l.a = 1.0;  l.b = 0.0;  l.c = -p1.x;
	}
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

//convert 2 points to vector a->b
vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
	return v.x * v.x + v.y * v.y;
}

// returns angle aob in radians
double angle(point a, point o, point b) {
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

// returns cross product of vec a and vec b
double cross(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

//scale a vector v by s
vec scale(vec v, double s) {
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// returns the distance from p to the line defined by 2 points a & b
// a & b must be different
// the closest point is stored in the 4th parameter (by reference)
double distToLine(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

// returns the distance from p to the line segment ab defined by two points a and b
// ok if a == b
// the closest point is stored in the 4th parameter by reference
double distToLineSegment(point p, point a, point b, point &c) {
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

point pivot(0, 0);
bool angleCmp(point a, point b) {		// angle sorting method
	if (collinear(pivot, a, b))					// special case
		return dist(pivot, a) < dist(pivot, b);	// check which one is closer
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;		// compare two angles
}

// finding Convex Hull of set of points
vector<point> CH(vector<point> P) {			// the content of P may be reshuffled
	int i, j, n = (int)P.size();
	if (n <= 3) {
		if (!(P[0] == P[n - 1])) P.push_back(P[0]);		// safeguard from corner case
		return P;
	}

	// first, find P0 = point with lowest Y and if tie: rightmost X
	int P0 = 0;
	for (int i = 1; i < n; i++) {
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	}

	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;		// swap P[P0] with P[0]

	// second, sort point by angle w.r.t. pivot P0
	pivot = P[0];									// use this global variable as reference
	sort(++P.begin(), P.end(), angleCmp);			// we do not sort P[0]

	//third, the ccw tests
	vector<point> S;
	S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]);	// initial S
	i = 2;											// then we check the rest
	while (i < n) {
		j = (int)S.size() - 1;
		if (ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]);		// left turn , accept
		else S.pop_back();			// or pop the top of S until we have a left turn
	}
	return S;
}

int main(){
	int C = 1;
	while (scanf("%d", &N), N) {
		vector<point> P;
		int x, y;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x, &y);
			P.push_back(point((double) x, (double) y));
		}
		
		vector<point> S = CH(P);

		double min = INF;
		for (int i = 1; i < S.size(); i++) {
			double max = 0;
			for (int j = 0; j < S.size(); j++) {
				point t;
				double dist = distToLine(S[j], S[i], S[i - 1], t);
				max = MAX(max, dist);
			}
			min = MIN(min, max);
		}

		printf("Case %d: %.2lf\n", C++, min);
	}

	return 0;
}	
