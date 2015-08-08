/*
*****Solved*****
UVa 11152

Problem Type:
geometry, triangles and circles
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

// calc distance between two points
double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

// returns area of triangle given lengths of three sides
double area(double ab, double bc, double ca){ //uses Heron's formula
	double s = (ab + bc + ca) / 2;
	return sqrt(s*(s - ab)*(s - bc)*(s - ca));
}

// returns radius of inscribed circle in triangle abc given side lengths
double rInCircle(double ab, double bc, double ca){
	return area(ab, bc, ca) / (0.5*(ab + bc + ca));
}

// returns radius of circumscribed circle around triangle abc given side lengths
double rCircumCircle(double ab, double bc, double ca){
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}


int main(){
	double a, b, c;
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3){
		double theta = acos((a*a + b*b - c*c) / (2 * a*b));
		//printf("theta=%lf\n", theta);
		//printf("acos(0)=%lf\n", (a*a + b*b - c*c) / (2 * a*b));
		double dy = b*sin(theta);
		double dx = sqrt(b*b - dy*dy);
		point z(dx, dy);
		point y(a, 0);
		point x(0, 0);
		point ctr;
		double rad = rInCircle(a, b, c);
		//printf("rad=%lf\n", rad);
		double redArea = PI*rad*rad;
		double triArea = area(a, b, c);
		rad = rCircumCircle(a, b, c);
		double bigCircle = PI*rad * rad;
		double yellowArea = bigCircle - triArea;
		double purpleArea = triArea - redArea;
		printf("%.4lf %.4lf %.4lf\n", yellowArea, purpleArea, redArea);
	}


	return 0;
}	
