/*


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
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
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


int main(){
	scanf("%d %d", &N, &K);

	vector<vi> g;
	g.assign(K + 1, vi());
	int a, maxExp = 0, inc = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);

		int exp = 0;
		if (a%K != 0) continue;
		while (true) {
			if (a < K) {
				g[a].push_back(exp);
				break;
			}
			else if (K == 1) {
				g[a].push_back(g.size());
				maxExp = MAX(maxExp, g.size());
				break;
			}
			else {
				a /= K;
				exp++;
				maxExp = MAX(maxExp, exp);
			}
		}
	}

	int count = 0;
	for (int i = 1; i <= K; i++) {
		vi e(maxExp + 1, 0);
		vi p(maxExp + 1, 0);
		for (int j = 0; j < g[i].size(); j++) {
			int exp = g[i][j];

			if (exp > 0 && p[exp-1] == 0) {
				p[exp] += e[exp-1];
			}
			else {
				p[exp] += p[exp - 1];
			}

			e[exp]++;

		}

		for (int j = 2; j < p.size(); j++) {
			if (e[j - 1] > 0 && e[j-2] > 0)
				count += p[j];
		}
	}

	printf("%d\n", count);

	return 0;
}	
