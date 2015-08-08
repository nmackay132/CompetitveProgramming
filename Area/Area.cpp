/*
*****Solved*****
UVa 10589

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
#define EPS 1.0e-10
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

double dist(point p1, point p2){
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int insideCircle(point p, point c, int r){
	double dx = p.x - c.x, dy = p.y - c.y;
	double Euc = dx * dx + dy * dy, rSq = r * r;
	return rSq - Euc > EPS ? 0 : fabs(Euc - rSq) < EPS ? 1 : 2; // inside=0/border=1/outside=2
}

int main(){
	int N;
	double a;
	while (scanf("%d %lf", &N, &a) && N){
		double x, y;

		int M = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &x, &y);
			point p = point(x, y);
			point cA = point(0, 0);
			point cB = point(a, 0);
			point cC = point(a, a);
			point cD = point(0, a);

			double comp = a*a;

			if (dist(p, cA) <= comp && dist(p, cB) <= comp && dist(p, cC) <= comp && dist(p, cD) <= comp)
				M++;
			//if (insideCircle(p, cA, a) <= 1 && insideCircle(p, cB, a) <= 1 && insideCircle(p, cC, a) <= 1 && insideCircle(p, cD, a) <= 1){
			//	M++;
			//}
		}
		//printf("M=%d a=%d\n", M, a);

		double ans = (M*a*a) / N;
		printf("%.5lf\n", ans);


	}

	return 0;
}	
