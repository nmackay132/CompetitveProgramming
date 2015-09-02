/*
*****Solved*****
UVa 10341

Problem Type:
binary search, bisection
*/
/*
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

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI acos(0)*2.0
#define eps 1.0e-9
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
int p, q, r, s, t, u;

double f(double x){
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF){
		double lo = 0, hi = 1, x = 0;
		//printf("result = %f\n", result);
		double result = -1;
		
		while (fabs(hi-lo) > eps){
			x = (lo + hi) / 2;
			//printf("x= %f\n", x);
			result = f(x);
			//printf("result = %f\n", result);
			//if (are_equal(result, 0)) break;
			if (result > 0)
				lo = x;
			else
				hi = x;
		}
		if (f(1) > 0 && f(0) > 0)
			printf("No solution\n");
		else if (f(1) <0 && f(0) < 0)
			printf("No solution\n");
		else
			printf("%.4lf\n", x);
	}

	return 0;
}

/*
0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1


0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1
0 0 0 0 0 0
1 -20 3 -20 -5 6
2 -20 3 -20 -5 6
3 -20 3 -20 -5 6
4 -20 3 -20 -5 6
5 -20 3 -20 -5 6
6 -20 3 -20 -5 6
3 -4 1 -3 -2 5
6 -11 8 -20 -3 1
4 -4 4 -4 -4 5
17 -6 2 -8 -1 3
16 -1 12 -2 -12 4
4 -9 10 -2 -4 8
4 -15 19 0 -5 6
*/