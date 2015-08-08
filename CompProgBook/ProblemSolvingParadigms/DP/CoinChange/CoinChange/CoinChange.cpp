/*
*****Solved*****
UVa 674

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
int coins[] = { 1, 5, 10, 25, 50 };
ll memo[5][10000];

ll comp(int pos, ll val) {
	if (val == 0) return 1;
	if (pos >= 5 || val < 0) return 0;
	if (memo[pos][val] != -1) return memo[pos][val];
	ll sum  = comp(pos, val - coins[pos]) + comp(pos + 1, val);

	return memo[pos][val] = sum;
}

int main(){
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10000; j++) {
			memo[i][j] = -1;
		}
	}
	comp(0, 7489);

	while (scanf("%d", &N) == 1) {

		printf("%ld\n", comp(0, N));

	}

	return 0;
}	
