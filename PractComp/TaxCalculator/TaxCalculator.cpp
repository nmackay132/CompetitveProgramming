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



int main(){
	int T, C = 1;
	scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int tax = 0;
		int m = n;
		if (m <= 180000) {
			printf("Case %d: 0\n", C++);
			continue;
		}
		m -= 180000;
		if (m <= 300000) {
			tax += (int)ceil(m * 0.1);
			if (tax < 2000) tax = 2000;
			printf("Case %d: %d\n", C++, tax);
			continue;
		}
		tax += 30000;
		m -= 300000;
		if (m <= 400000) {
			tax += (int)ceil(m * 0.15);
			printf("Case %d: %d\n", C++, tax);
			continue;
		}
		tax += 60000;
		m -= 400000;
		if (m <= 300000) {
			tax += (int)ceil(m * 0.2);
			printf("Case %d: %d\n", C++, tax);
			continue;
		}
		tax += 60000;
		m -= 300000;

		tax += (int)ceil(m * 0.25);
		printf("Case %d: %d\n", C++, tax);
	}

	return 0;
}	
