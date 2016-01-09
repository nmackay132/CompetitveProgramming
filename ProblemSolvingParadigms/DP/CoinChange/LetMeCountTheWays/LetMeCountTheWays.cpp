/*
*****Solved*****
UVa 357

Problem Type:
coin change, dp, bottom up
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

#define sc scanf
#define pf printf
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
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
const int MAX_SIZE= 30010;
int N;
int coins[] = { 1, 5, 10, 25, 50 };
int dp[MAX_SIZE];

int main(){
	MEM(dp, 0);
	dp[0] = 1;
	//for (int m = 1; m < MAX_SIZE; m++) {
	//	for (int c = 0; c < 5; c++) {
	//		if (m - coins[c] >= 0) {
	//			dp[m] += dp[m - coins[c]];
	//		}
	//	}
	//}

	for (int c = 0; c < 5; c++) {
		for (int m = coins[c]; m <= 30000; m++) {
			dp[m] += dp[m - coins[c]];
		}
	}

	while (scanf("%d", &N)==1) {
		if (dp[N]==1)
			printf("There is only 1 way to produce %d cents change.\n", dp[N]);
		else
			printf("There are %d ways to produce %d cents change.\n", dp[N], N);
	}

	return 0;
}	
