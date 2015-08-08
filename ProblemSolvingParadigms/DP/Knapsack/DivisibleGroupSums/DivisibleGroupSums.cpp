/*
*****Solved*****
UVa 10616

Problem Type:
dp, knapsack
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
const int maxN = 205;
const int maxM = 12;
const int maxD = 22;
int N, D;
long memo[maxN][maxM][maxD];
vi nums;

int negMod(int a, int b){

	if (a < 0){
		int c = a  % b;
		return b + c;
	}

	return a % b;
}

long comp(int pos, int count, long sum){
	int mod = negMod(sum, D);
	if (count == 0 && mod == 0) return 1;
	if (pos == N || count == 0) return 0;

	if (memo[pos][count][mod] != -1) return memo[pos][count][mod];

	long ans = comp(pos + 1, count, mod) + comp(pos + 1, count - 1, (mod + negMod(nums[pos], D)));

	return memo[pos][count][mod] = ans;
}

int main(){
	int Q; int C = 1;
	while (scanf("%d %d", &N, &Q), N || Q){
		nums.clear();
		for (int i = 0; i < N; i++) {
			int a; scanf("%d", &a);
			nums.push_back(a);
		}
		printf("SET %d:\n", C++);

		for (int i = 0; i < Q; i++)	{
			memset(&memo, -1, sizeof(memo));
			int M; scanf("%d %d", &D, &M);
			long ans = comp(0, M, 0);
			
			printf("QUERY %d: %ld\n", i + 1, ans);
		}
	}

	return 0;
}	
