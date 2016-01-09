/*
*****Solved*****

Problem Type:
dp
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

const int MAXH = 1000010;
ll dp[MAXH];
ll bricks[3];

int main(){

	ll H, base_size, top_size;
	while (cin >> H >> base_size >> top_size) {
		if (top_size > base_size) {

		}
		cin >> bricks[0] >> bricks[1] >> bricks[2];
		MEM(dp, -1);
		dp[0] = 0;
		for (int h = 1; h <= H; h++) {
			ll max_size = top_size + (H - h) * (base_size - top_size) / H;
			for (int i = 0; i < 3; i++) {
				if (h - bricks[i] < 0) continue;
				if (dp[h - bricks[i]] < 0) continue;
				ll numBricks = (max_size / bricks[i])*(max_size / bricks[i]);
				ll vol = numBricks * bricks[i] * bricks[i] * bricks[i] + dp[h-bricks[i]];
				dp[h] = MAX(dp[h], vol);
			}
		}
		ll best = -1;
		for (int i = 1; i <= H; i++) {
			best = MAX(best, dp[i]);
		}

		printf("%ld\n", best);

	}

	return 0;
}	
