/*
*****Solved*****
UVa 481

Problem Type:
longest increasing subsequence (lis) o(nlogn) solution
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

int L[1000000];
int L_ID[1000000];
int P[1000000];
int A[1000000];

void print(int i){
	if (i == -1) return;
	print(P[i]);
	printf("%d\n", A[i]);
}

int main(){

	int i = 0;
	int lis = 0, lis_end = 0;
	while (scanf("%d", A+i) != EOF){
		int pos = lower_bound(L, L + lis, A[i]) - L;
		//int val = A[i];
		L[pos] = A[i];
		L_ID[pos] = i;
		P[i] = pos > 0 ? L_ID[pos - 1] : -1;
		if (pos == lis){
			lis++;
			lis_end = i;
		}
		i++;
	}

	printf("%d\n-\n", lis);
	print(lis_end);	
	
	return 0;
}	
