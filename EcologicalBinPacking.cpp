/*
*****Solved*****
UVa 102

Problem Type:
easy permutations
*/
/*
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
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

long B[3], G[3], C[3];
string config[] = { "BGC", "BCG", "GBC", "GCB", "CBG", "CGB"};

int main(){
	 
	while (scanf("%ld %ld %ld %ld %ld %ld %ld %ld %ld", &B[0], &B[1], &B[2], &G[0], &G[1], &G[2], &C[0], &C[1], &C[2]) == 9){
		int arr[] = { 0, 1, 2 };

		long sum_B = B[0] + B[1] + B[2];
		long sum_G = G[0] + G[1] + G[2];
		long sum_C = C[0] + C[1] + C[2];

		string s;

		long min = INF;
		int i = 0;
		do{
			long cost = sum_B - B[arr[0]] + sum_G - G[arr[1]] + sum_C - C[arr[2]];

			if (cost < min || (cost == min && config[i] < s)) {
				min = cost;
				s = config[i];
			}
			i++;

		} while (next_permutation(arr, arr + 3));

		cout << s << " " << min << "\n";
	}

	return 0;
}

/*
1 2 3 4 5 6 7 8 9
5 10 5 20 10 5 10 20 10
*/
