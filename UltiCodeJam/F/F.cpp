/*
*****Solved*****

Problem Type:
dp, coin change variant
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

int N;
vector<ll> powOf3;
ll dp[30][12000];

ll comp(ll pos, ll val) {
	if (val == 0) return 1;
	if (pos >= powOf3.size()) return 0;
	if (val < 0) return 0;
	if (dp[pos][val] != -1) return dp[pos][val];

	return dp[pos][val] = comp(pos, val - powOf3[pos]) + comp(pos + 1, val);
}


int main(){
	for (int i = 1; i <= 21; i++) {
		powOf3.push_back((ll)pow(i, 3));
	}

	while (scanf("%d", &N) == 1) {

		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 12000; j++) {
				dp[i][j] = -1;
			}
		}

		ll ans = comp(0, N);

		printf("%ld\n", ans);
	}

	return 0;
}
