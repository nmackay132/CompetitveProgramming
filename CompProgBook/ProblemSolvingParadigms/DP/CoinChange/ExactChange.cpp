/*
*****Solved*****
UVa 11517

Problem Type:
dp, coin change
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

#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
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

vi coin;
int dp[101][20010];

int comp(int pos, int val){
	if (val == 0) return 0;
	if (pos >= coin.size()) return INF;
	if (val < 0) return INF;
	if (dp[pos][val] > -1) return dp[pos][val];
	int min = MIN(comp(pos + 1,val), comp(pos + 1, val - coin[pos]) + 1);
	//dp[val] = min;
	//printf("min = %d val = %d dp[val] = %d\n", min, val, dp[val]);
	return dp[pos][val] = min;
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		int M; scanf("%d", &M);
		int N; scanf("%d", &N);
		coin.clear();
		for (int i = 0; i < N; i++) {
			int c; scanf("%d", &c);
			coin.push_back(c);
		}

		memset(dp, -1, sizeof dp);
		int count = 0;
		while (true){
			count = comp(0, M);
			if (count < INF) {
				//printf("count = %d M = %d\n", count, M);
				break;
			}
			M++;
		}
		printf("%d %d\n", M, count);
	}

	return 0;
}

/*
1
13 5
9 5 2 3 3


1
1400
3
500
1000
2000
*/