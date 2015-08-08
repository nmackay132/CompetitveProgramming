/*
UVa 166

Problem Type:
dp, coin change
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

vi coins;
int dp[125][710];
int dp2[125][710];
int memo[125][710];
int val[] = { 5, 10, 20, 50, 100, 200 };

//int comp(int pos, int m) {
//	if (pos >= coins.size()) return INF;
//	if (m < 0) return INF;
//	if (m == 0) return 0;
//	if (memo[pos][m] != -1) return memo[pos][m];
//	int ans = INF;
//	ans = MIN(ans, comp(pos, ))
//}

int main(){
	int a;
	while (true) {
		coins.clear();
		int sum = 0;
		for (int i = 0; i < 6; i++) {
			cin >> a;
			sum += a;
			for (int j = 0; j < a; j++) {
				coins.push_back(val[i]);
			}
		}
		if (sum == 0)break;

		double g;
		cin >> g;
		int goal = (int) (g * 100);

		for (int i = 0; i < coins.size(); i++) {
			for (int j = 0; j <= 500; j++) {
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i < coins.size(); i++) {
			dp[i][0] = 0;
			dp[i][coins[i]] = 1;	
		}
		for (int i = 1; i < coins.size(); i++) {
			for (int m = 0; m <= 500; m++) {
				bool changed = false;
				if (m >= coins[i] && dp[i][m] > dp[i - 1][m - coins[i]] ){
					dp[i][m] = MIN(dp[i - 1][m + coins[i]] + 1, dp[i - 1][m - coins[i]] + 1);
					changed = true;
				}
				else if (dp[i][m] > dp[i - 1][m + coins[i]]) {
					dp[i][m] = dp[i - 1][m + coins[i]] + 1;
					changed = true;
				}
				if(!changed) {
					dp[i][m] = dp[i - 1][m];
				}
			}
		}

		int min = INF;
		for (int i = 0; i < coins.size(); i++) {
			min = MIN(min, dp[i][goal]);
		}

		printf("%3d\n", min);
	}

	return 0;
}	
