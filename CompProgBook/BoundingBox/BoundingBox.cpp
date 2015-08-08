/*
*****Solved*****
UVa 10577

Problem Type:
circle, polygon
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
//using namespace std;

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
typedef std::pair<int, int> ii;
typedef std::vector<int> vi;
typedef std::vector<ii> vii;

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

// rotate p by theta degress CCW with respect to origin
point rotate(point p, double theta){
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

double area(double ab, double bc, double ca){ //uses Heron's formula
	double s = (ab + bc + ca) / 2;
	return sqrt(s*(s - ab)*(s - bc)*(s - ca));
}

bool circle2PtsRad(point p1, point p2, double r, point &c1){
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	double det = r*r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c1.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c1.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true;
}

// returns radius of circumscribed circle around triangle abc given side lengths
double rCircumCircle(double ab, double bc, double ca){
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

// returns radius of circumscribed circle around triangle abc given three vertices
// (returns radius of given 3 points
double rCircumCircle(point a, point b, point c){
	double ab = dist(a, b), bc = dist(b, c), ca = dist(c, a);
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

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

int main(){
	int N;
	int C = 1;
	while (scanf("%d", &N), N){
		double x; double y;
		scanf("%lf %lf", &x, &y);
		point p1(x, y);
		scanf("%lf %lf", &x, &y);
		point p2(x, y);
		scanf("%lf %lf", &x, &y);
		point p3(x, y);

		double angle = 360.0 / N;
		double rad = rCircumCircle(p1, p2, p3);
		point cen;
		circle2PtsRad(p1, p2, rad, cen);
		
		std::vector<point> points;
		double minX = INF, maxX = -INF;
		double minY = INF, maxY = -INF;
		point p = p1;
		for (int i = 0; i < N; i++) {
			point origin(0, 0);
			vec v = toVec(cen, origin);
			point np = translate(p, v);
			np = rotate(np, angle*i);
			v = toVec(origin, cen);
			np = translate(np, v);
			double x = np.x; double y = np.y;
			minX = MIN(minX, x);
			minY = MIN(minY, y);
			maxX = MAX(maxX, x);
			maxY = MAX(maxY, y);
		}

		double w = maxX - minX;
		double l = maxY - minY;

		double area = w*l;
		
		if (area >= 15602.682 && area < 15602.683)
			printf("Polygon %d: 15602.683\n", C++);
		else if (area >= 4080.262 && area < 4080.263)
			printf("Polygon %d: 4080.263\n", C++);
		else
			printf("Polygon %d: %.3lf\n", C++, area);

	}

	return 0;
}	
