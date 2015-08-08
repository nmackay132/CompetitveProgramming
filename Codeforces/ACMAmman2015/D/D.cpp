/*

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

int N, K;
int str[1010];
int memo[1010][1010][3][2];

int comp(int pos, int k, int prv, int alt) {
	if (pos >= N) return 0;
	if (memo[pos][k][prv][alt] != -1) return memo[pos][k][prv][alt];
	int newAlt = alt;
	if (str[pos] == str[prv]) newAlt = 0;
	if (k == 0) {
		if (newAlt) return INF;
		else {
			return memo[pos][k][prv][alt] = comp(pos + 1, K, 2, 1) + 1;
		}
	}
	int min = MIN(comp(pos + 1, K, 2, 1) + 1, comp(pos + 1, k - 1, str[pos], newAlt));
	return memo[pos][k][prv][alt] = min;
}

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		string line; getline(cin, line);
		getline(cin, line);
		for (int i = 0; i < N; i++) {
			str[i] = line[i] - '0';
		}
		//for (int i = 0; i < N; i++) {
		//	printf("%d", str[i]);
		//}
		//printf("\n");
		MEM(memo, -1);
		int ans = comp(0, K, 2, 1);
		printf("%d\n", ans);
	}

	return 0;
}	
