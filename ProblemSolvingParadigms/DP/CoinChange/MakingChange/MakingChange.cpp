/*
*****Solved******
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
const int MAXVAL = 850;
vi coins;
int dp[MAXVAL];
int val[] = { 5, 10, 20, 50, 100, 200 };

int main() {
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
		int goal = (int)(g * 100 + 0.5);

		for (int i = 0; i < MAXVAL; i++) {
			dp[i] = INF;
		}
		dp[0] = 0;
		for (int i = 0; i < coins.size(); i++) {
			for (int m = MAXVAL; m >= coins[i]; m -= 5) {
				if (dp[m] > dp[m - coins[i]] + 1) {
					dp[m] = dp[m - coins[i]] + 1;
				}
			}
		}

		//for (int i = 0; i < MAXVAL; i+=5) {
		//	if (i % 100 == 0) printf("\ni=%d\n", i);
		//	printf("%11d ", dp[i]);
		//}
		//printf("\n");

		int min = dp[goal];
		for (int i = goal; i < MAXVAL; i+=5) {
			int gap = i-goal;
			int j = 5;
			int count = 0;
			while (gap > 0) {
				if (gap >= val[j]) {
					count++;
					gap -= val[j];
				}
				else {
					j--;
				}
			}
			if (min > dp[i] + count) {
				min = dp[i] + count;
			}
		}

			printf("%3d\n", min);
	}

	return 0;
}

