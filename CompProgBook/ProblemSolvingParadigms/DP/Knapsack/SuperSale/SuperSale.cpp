/*
*****Solved*****
UVa 10130

Problem Type:
dp, knapsack, topdown solution
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

int N, G;
int P[1010], W[1010];
int dp[1010][35]; //dp[weight]


int main(){
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &P[i], &W[i]);
		}

		MEM(dp, 0);

		for (int i = 1; i <= N; i++) {
			for (int w = 1; w <= 30; w++) {
				if (w >= W[i]) {
					dp[i][w] = MAX(dp[i-1][w], dp[i-1][w - W[i]] + P[i]);
				}
				else {
					dp[i][w] = dp[i - 1][w];
				}
			}
		}

		scanf("%d", &G);
		int sum = 0;
		for (int i = 0; i < G; i++) {
			int w; scanf("%d", &w);
			sum += dp[N][w];
		}

		pf("%d\n", sum);
	}

	return 0;
}	
