/*

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

#define sc scanf
#define pf printf
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

int N, S;
//vi coins;
int coins[12];

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &S); 
		for (int i = 0; i < N; i++) {
			int a;
			scanf("%d", &a);
			coins[i] = a;
		}

		int max = -INF;
		for (int i = 1; i < (1<<N); i++) {
			int sum = 0;
			int count = 0;
			int min = INF;
			for (int j = 0; j < N; j++) {
				if (i & (1 << j)) {
					sum += coins[j];
					count++;
					min = MIN(min, coins[j]);
				}
			}
			if (sum >= S && min > sum - S) {
				max = MAX(max, count);
			}
		}
		cout << max << endl;
	}

	return 0;
}	
