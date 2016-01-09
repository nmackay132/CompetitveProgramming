/*


Problem Type:

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
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
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

int N;

int main(){
	while (scanf("%d", &N), N > -1) {

		int sum = 0;
		int n = N;
		vi div;
		for (int i = 1; i*i <= N; i++) {
			if (N%i == 0) {
				sum += i;
				int d = N / i;
				if (d != i) {
					div.push_back(i);
					sum += d;
					div.push_back(N / i);
				}
			}
		}
		sort(div.begin(), div.end());
		//printf("sum = %d\n", sum);
		if (sum == 2*N) {
			printf("%d = ", N);
			for (int i = 0; i < div.size()-1; i++) {
				if (i == 0) printf("%d", div[i]);
				else printf(" + %d", div[i]);
			}
			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", N);
		}
			
	}

	return 0;
}	
