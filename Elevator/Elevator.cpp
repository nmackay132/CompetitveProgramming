/*
*****Solved*****
UVa 11834

Problem Type:
Geometry, Quadrilateral
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

int W, L, R1, R2;

int main(){

	while (scanf("%d %d %d %d", &W, &L, &R1, &R2), W || L || R1 || R2){
		double x = MAX(R1, R2);
		double y = MIN(R1, R2);
		double d = sqrt((x + y)*(x + y) - (x - y)*(x - y));

		double bigSide = MAX(L, W);
		double smallSide = MIN(L, W);
		if (smallSide < 2 * x){
			printf("N\n"); continue;
		}

		double p = smallSide - x - y;
		double hyp = hypot(bigSide, smallSide);
		double v = x + y + x*sqrt(2) + y*sqrt(2);
		if (hyp >= v){
			printf("S\n"); continue;
		}

		double r = sqrt((x + y)*(x + y) - p*p) + x + y;
		if (bigSide >= r){
			printf("S\n"); continue;
		}
		printf("N\n");
		
	}
	return 0;
}	
