/*
*****Solved*****
UVa 567

Problem Type:
APSP (All Pairs Shortest Path)
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

int AdjMat[21][21];

int main(){

	int n;
	int C = 1;
	while (true){
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				if (i == j) AdjMat[i][j] = 0;
				else AdjMat[i][j] = INF;
			}
		}

		for (int i = 1; i <= 19; i++) {
			if (scanf("%d", &n) == -1) return 0;
			for (int j = 0; j < n; j++) {
				int m; scanf("%d", &m);
				AdjMat[i][m] = 1;
				AdjMat[m][i] = 1;
			}
		}

		for (int k = 1; k <= 20; k++) {
			for (int i = 1; i <= 20; i++) {
				for (int j = 1; j <= 20; j++) {
					AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
				}
			}
		}

		printf("Test Set #%d\n", C++);
		int Q; scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%2d to %2d: %d\n", a, b, AdjMat[a][b]);
		}
		printf("\n");
	}
	return 0;
}	