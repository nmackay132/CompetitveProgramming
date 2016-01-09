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

int AdjMat[110][110];

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		int N, K, M;
		scanf("%d %d %d", &N, &K, &M);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				AdjMat[i][j] = INF;
			}
		}

		for (int i = 0; i < M; i++) {
			int u, v, d;
			scanf("%d %d %d", &u, &v, &d);
			AdjMat[u][v] = d;
			AdjMat[v][u] = d;
		}


		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					AdjMat[i][j] = MIN(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
				}
			}
		}

		int max = 0;
		ii p;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (max < AdjMat[i][j]) {
					max = AdjMat[i][j];
					p = ii(i, j);
				}
			}
		}
		printf("max=%d from %d to %d\n", max, p.first, p.second);
		printf("%d\n", max / (K));
	}

	return 0;
}	
