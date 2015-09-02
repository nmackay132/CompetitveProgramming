/*
*****Solved*****
UVa 12455

Problem Type:
greedy, complete search
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
	int T; scanf("%d", &T);
	while (T--){
		int len, n; scanf("%d", &len);
		scanf("%d", &n);
		vi bars;
		for (int i = 0; i < n; i++) {
			int b; scanf("%d", &b);
			bars.push_back(b);
		}

		bool possible = false;
		for (int i = 0; i < (1 << n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if ((1 << j) & i){
					sum += bars[j];
				}
			}
			if (sum == len){
				possible = true;
				break;
			}
		}
		if (possible)
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}	
