/*
*****Solved*****
UVa 11456

Problem Type:
longest increasing subsequence (LIS)
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

//int LP[2005];
//int FP[2005];

bool compare(int a, int b){ //opposite of normal compare
	return a >= b;
}

int main(){
	
	int T; scanf("%d", &T);
	while (T--){
		int A[2005];
		int L[2005];
		int LIS[2005];
		int F[2005];
		int LDS[2005];

		int N; scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", A + i);
		}
			
		int lis = 0;
		int lds = 0;
		for (int i = N - 1; i >= 0; i--) {
			int posL = lower_bound(L, L + lis, A[i]) - L;
			int posF = upper_bound(F, F + lds, A[i], compare) - F;
			L[posL] = A[i];
			F[posF] = A[i];
			if (posL == lis) lis++;
			if (posF == lds) lds++;
			LIS[i] = posL + 1;
			LDS[i] = posF + 1;
		}

		int maxSum = 0;
		int sum;
		for (int i = 0; i < N; i++) {
			//printf("i=%d LDS=%d LIS=%d\n", i, LDS[i], LIS[i]);
			sum = LDS[i] + LIS[i] - 1;
			maxSum = MAX(sum, maxSum);
		}

		printf("%d\n", maxSum);
	}


	return 0;
}	
