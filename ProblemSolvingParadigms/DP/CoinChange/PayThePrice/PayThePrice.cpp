/*
UVa 10313

Problem Type:

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

vi inputs;
int dp[310][310]; // dp[pos][val]

int main(){
	while (true) {
		string line; getline(cin, line);
		stringstream ss; ss.str(line);
		int n; inputs.clear();
		while (ss >> n) {
			inputs.push_back(n);
		}
		int limit = limit = inputs[inputs.size() - 1];

		MEM(dp, 0);
		dp[0][0] = 1;
		for (int i = 0; i < inputs[0]; i++) {
			dp[i][0] = 0;
			dp[0][i] = 0;
			dp[i][1] = 1;
			dp[i][i] = 1;
		}

		for (int v = 0; v < inputs[0]; v++) {
			for (int c = 0; c < inputs[0]; c++) {
				for (int k = 0; k <= c; k++) {
					dp[v][c] += dp[v - k][c - k];
				}
			}
		}
	}

	return 0;
}	
