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

#define mp make_pair
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



int main(){

	int N; cin >> N;
	int min1, max1, min2, max2, min3, max3;
	cin >> min1 >> max1 >> min2 >> max2 >> min3 >> max3;
	int a = 0, b = 0, c = 0;
	N -= min1 + min2 + min3;
	a += min1; b += min2; c += min3;
	if (N >= max1 - a) {
		N -= max1 - a;
		a = max1;
	}
	else {
		a += N;
		goto finish;
	}

	if (N >= max2 - b) {
		N -= max2 - b;
		b = max2;
	}
	else {
		b += N;
		goto finish;
	}

	if (N >= max3 - c) {
		N -= max3 - c;
		c = max3;
	}
	else {
		c += N;
		goto finish;
	}

finish:
	printf("%d %d %d\n", a, b, c);
	return 0;
}	
