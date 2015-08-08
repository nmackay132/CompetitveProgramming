/*
*****Solved*****
UVa 108

Problem Type:
Maximum 2D Range Sum
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

int G[105][105];

int main(){
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	{
			scanf("%d", &G[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	{
			if (i > 0) G[i][j] += G[i - 1][j];
			if (j > 0) G[i][j] += G[i][j - 1];
			if (i > 0 && j > 0) G[i][j] -= G[i - 1][j - 1];
		}
	}

	int max = -INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = i; k < N; k++) {
				for (int m = j; m < N; m++) {
					if (i == k && j == m) continue;
					int sum = G[k][m];
					if (i > 0) sum -= G[i - 1][m];
					if (j > 0) sum -= G[k][j - 1];
					if (i > 0 && j > 0) sum += G[i - 1][j - 1];
					max = MAX(max, sum);
				}
			}
		}
	}

	printf("%d\n", max);

	return 0;
}	
