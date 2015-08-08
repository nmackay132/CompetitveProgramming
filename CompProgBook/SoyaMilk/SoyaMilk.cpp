/*
*****Solved*****
UVa 11909

Problem Type:
geometry, triangles
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



int main(){
	double l, w, h, theta;
	while (scanf("%lf %lf %lf %lf", &l, &w, &h, &theta) == 4){
		double x = l*tan(DEG_to_RAD(theta));
		double boxVol = l*w*h;

		double triVol;
		//printf("x= %lf\n", x);
		if (x <= h){
			triVol = l*x / 2 * w;
			//printf("triVol %lf\n", triVol);
			printf("%.3lf mL\n", boxVol - triVol);
		}
		else{
			x = h*tan(PI / 2 - DEG_to_RAD(theta));
			double ansVol = x * h / 2 * w;
			printf("%.3lf mL\n", ansVol);
		}
	}

	return 0;
}	
