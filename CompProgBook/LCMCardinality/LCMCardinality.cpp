/*
*****Solved*****
UVa 10892

Problem Type:
number theory, lcm
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


int main(){
	int N;
	while (scanf("%d", &N), N){
		//int factorCount = 0;
		vi factors;
		for (int i = 2; i <= (int) sqrt(N); i++) {
			if (N % i == 0){
				int fact = N / i;
				factors.push_back(i);
				if (i != fact)
					factors.push_back(fact);
			}
		}

		int cardinality = 2 + factors.size();
		for (int i = 0; i < factors.size(); i++) {
			for (int j = i; j < factors.size(); j++) {
				if (lcm(factors[i], factors[j]) == N){
					cardinality++;
				}
			}
		}

		if (N > 1)
			printf("%d %d\n", N, cardinality);
		else
			printf("1 1\n");
	}

	return 0;
}	
