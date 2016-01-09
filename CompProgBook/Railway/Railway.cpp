/*
*****Solved*****
UVa 10263

Problem Type:
geometry, intersecting lines
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

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

//convert 2 points to vector a->b
vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}

//scale a vector v by s
vec scale(vec v, double s){
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b){
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}

// calc distance between two points
double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

// returns the distance from p to the line segment ab defined by two points a and b
// ok if a == b
// the closest point is stored in the 4th parameter by reference
double distToLineSegment(point p, point a, point b, point &c){
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


int main(){
	double mx, my; int N;
	while (scanf("%lf", &mx) == 1){
		scanf("%lf", &my);
		scanf("%d", &N);
		point M = point(mx, my);
		vector<point> points;
		for (int i = 0; i < N+1; i++) {
			double x, y; scanf("%lf %lf", &x, &y);
			points.push_back(point(x,y));
		}

		point minP;
		double minDist = INF;
		for (int i = 0; i < points.size()-1; i++) {
			point p;
			double d = distToLineSegment(M, points[i], points[i+1], p);
			if (d < minDist){
				minDist = d;
				minP = p;
			}
		}

		printf("%.4lf\n", minP.x);
		printf("%.4lf\n", minP.y);
	}

	return 0;
}	
