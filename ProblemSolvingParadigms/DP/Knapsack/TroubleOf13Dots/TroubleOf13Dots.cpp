/*
*****Solved*****
UVa 10819

Problem Type:
dp, knapsack
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

int M, N;
vii nums;
int memo[101][10205];

int comp(int pos, int mon){
	if (mon > M && M < 1800) return -INF;
	if (mon > M + 200) return -INF;
	if (pos == N) { 
		if (mon > M && mon <= 2000)
			return -INF;
		return 0; 
	}
	if (memo[pos][mon] != -1) return memo[pos][mon];
	int result = MAX(comp(pos+1, mon), comp(pos+1, mon + nums[pos].first) + nums[pos].second);
	return memo[pos][mon] = result;
}

int main(){
	while (scanf("%d %d", &M, &N) == 2){
		nums.clear();
		for (int i = 0; i < N; i++) {
			int p, f; scanf("%d %d", &p, &f);
			nums.push_back(ii(p, f));
		}
		memset(&memo, -1, sizeof(memo));
		int ans;
		if (M > 2000)
			ans = comp(0, 0);
		else
			ans = comp(0, 0);

		printf("%d\n", ans);
	}

	return 0;
}	
