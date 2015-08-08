/*
*****Solved*****
UVa 10684

Problem Type:
Max 1D Range Sum
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



int main(){
	int N;
	while (scanf("%d", &N), N){
		int sum = 0;
		int maxSum = -INF;
		for (int i = 0; i < N; i++)	{
			int n; scanf("%d", &n);
			if (sum < 0){
				sum = 0;
			}
			sum += n;
			maxSum = MAX(maxSum, sum);
		}

		if (maxSum <= 0)
			printf("Losing streak.\n");
		else{
			printf("The maximum winning streak is %d.\n", maxSum);
		}
	}
	return 0;
}	
