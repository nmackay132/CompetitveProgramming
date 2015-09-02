/*
*****Solved*****
UVa 524

Problem Type:
Recursive backstracking
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

bitset<32> isprime;
int set[17];
bitset<17> used;
int N;
int C = 1;

bool valid(int n, int ind){
	for (int i = 0; i < ind; i++) {
		if (set[i] == n)
			return false;
	}
	return true;
}

void btrack(int n, int ind){
	if (ind == N){
		if (!isprime[1 + set[ind - 1]]) return;
		for (int i = 0; i < N; i++) {
			if (i == 0)
				printf("%d", set[i]);
			else
				printf(" %d", set[i]);
		}
		printf("\n");
	}

	for (int i = 2; i <= N; i++) {
		int m = n + i;
		if (valid(i, ind) && isprime[m]){
			//printf("ind=%d i=%d\n", ind, i);
			set[ind] = i;
			btrack(i, ind+1);
		}
	}
}

int main(){
	int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
	for (int i = 0; i < 11; i++) {
		isprime[primes[i]] = 1;
	}
	memset(&used, 0, sizeof(set));
	while (scanf("%d", &N)==1){
		set[0] = 1;
		if (C > 1) printf("\n");

		printf("Case %d:\n", C++);
		btrack(1, 1);
	}

	return 0;
}	
