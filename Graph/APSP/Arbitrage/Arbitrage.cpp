/*
UVa 104

Problem Type:
floyd warshall's
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

double AdjMat[32][32][32];
int p[32][32][32];

void showPath(int a, int b, int s) {
	if (p[a][b][s] == -1) {
		printf("%d %d", a + 1, b + 1);
		return;
	}
	showPath(a, p[a][b][s], s - 1);
	printf(" %d", b + 1);
}

int main(){
	int N;
	while (scanf("%d", &N) == 1) {
		MEM(AdjMat, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) AdjMat[i][j][1] = 1;
				else {
					scanf("%lf", &AdjMat[i][j][1]);
				}
			}
		}
		
		MEM(p, -1);

		// Floyd Warshall's
		bool find = false;
		for (int s = 2; s <= N && !find; s++) {
			for (int k = 0; k < N; k++) {
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						if (AdjMat[i][j][s] < AdjMat[i][k][s - 1] * AdjMat[k][j][1]) {
							AdjMat[i][j][s] = AdjMat[i][k][s - 1] * AdjMat[k][j][1];
							p[i][j][s] = k;
						}
					}
				}
			}
			for (int i = 0; i < N && !find; i++) {
				if (AdjMat[i][i][s] >= 1.01) {
					showPath(i, i, s);
					printf("\n");
					find = true;
				}
			}
		}
		if (!find) {
			printf("no arbitrage sequence exists\n");
		}

	}

	return 0;
}	
