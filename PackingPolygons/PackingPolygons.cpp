/*
*****Solve*****
UVa 10005

Problem Type:
geometry, circles
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

bool circle2PtsRad(point p1, point p2, double r, point &c1){
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	double det = r*r / d2 - 0.25;
	if (det < 0.0) return false;
	double h = sqrt(det);
	c1.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
	c1.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
	return true;
}

// calc distance between two points
double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

bool inCircle(double r, point cnt, point p){
	double d = dist(cnt, p);
	return are_equal(r, d) || d < r;
}

int main(){

	int N; 
	while (scanf("%d", &N), N){

		vector<point> points;
		for (int i = 0; i < N; i++) {
			double x, y;
			scanf("%lf %lf", &x, &y);
			points.push_back(point(x,y));
		}
		double R; scanf("%lf", &R);

		if (points.size() == 1){
			printf("The polygon can be packed in the circle.\n");
			continue;
		}
		bool possible = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)	{
				if (i == j) continue;
				point c1;
				if (!circle2PtsRad(points[i], points[j], R, c1)){
					//printf("d1 %lf\n", dist(c1, points[i]));
					//printf("d2 %lf\n", dist(c1, points[j]));
					i = N; break;
				}

				bool canFit = true;
				for (int k = 0; k < N; k++) {
					if (k == i || k == j) continue;
					if (!inCircle(R, c1, points[k])){
						//printf("%lf\n", dist(c1, points[k]));
						canFit = false; break;
					}
				}
				if (canFit){
					possible = true;
					i = N; break;
				}

			}
		}

		if (possible)
			printf("The polygon can be packed in the circle.\n");
		else
			printf("There is no way of packing that polygon.\n");
	}

	return 0;
}	
