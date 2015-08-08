/*
*****Solved*****
UVa 11207

Problem Type:
geometry, divide quadrilateral into 4 squares
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



int main(){
	int N;
	while (scanf("%d", &N), N){
		int a, b;
		double max = -INF;
		int maxI = -1;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &a, &b);
			double big, sm;
			big = MAX(a, b);
			sm = MIN(a, b);
			double x = sm / 2.0;
			if (big / sm >= 4){
				x = sm;
			}
			double y = big / 4;
			if (y <= sm && y > x)
				x = y;
			if (x > max){
				max = x;
				maxI = i;
			}
		}
		
		printf("%d\n", maxI);

	}

	return 0;
}	
