/*
*****Solved*****
UVa 990

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

int T, W, N;
vii treasure;
int memo[35][1010];
vii taken;

int comp(int pos, int time) {
	if (time < 0) return -INF;
	if (pos >= treasure.size()) return 0;
	if (memo[pos][time] != -1) return memo[pos][time];

	int max = MAX(treasure[pos].second + comp(pos+1, time - W*3*treasure[pos].first), comp(pos+1, time) );

	return memo[pos][time] = max;
}

void getTaken(int pos, int time) {
	if (time < 0 || pos >= treasure.size()) return;
	//printf("memo[%d][%d]=%d comp()=%d\n", pos, time, memo[pos][time], comp(pos + 1, time - W * 3 * treasure[pos].first + treasure[pos].second));
	if (memo[pos][time] == comp(pos + 1, time - W * 3 * treasure[pos].first)+treasure[pos].second) {
		taken.push_back(ii(treasure[pos].first, treasure[pos].second));
		getTaken(pos + 1, time - W * 3 * treasure[pos].first);
	}
	else {
		getTaken(pos + 1, time);
	}
}

int main(){
	int C = 0;
	while (scanf("%d %d", &T, &W) == 2) {
		if (C++) printf("\n");
		taken.clear(); treasure.clear();
		for (int i = 0; i < 35; i++) {
			for (int j = 0; j < 1010; j++) {
				memo[i][j] = -1;
			}
		}

		scanf("%d", &N);
		ii t;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &t.first, &t.second);
			treasure.push_back(t);
		}

		int ans = comp(0, T);

		printf("%d\n", ans);

		getTaken(0, T);
		printf("%d\n", taken.size());
		for (int i = 0; i < taken.size(); i++) {
			printf("%d %d\n", taken[i].first, taken[i].second);
		}
	}

	return 0;
}	
