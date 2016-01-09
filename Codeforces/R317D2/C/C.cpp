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

int a, b, c, L;

bool isValid(int a1, int b1, int c1) {
	if (a1 + b1 <= c1)
		return false;
	if (a1 + c1 <= b1)
		return false;
	if (b1 + c1 <= a1)
		return false;
	return true;
}

ll comp(int x, int y, int z) {
	int val = 0;
	if (isValid(x, y, z)) val++;
}

int main(){
	scanf("%d %d %d %d", &a, &b, &c, &L);
	vi arr;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	sort(arr.begin(), arr.end());
	a = arr[0];
	b = arr[1];
	c = arr[2];
	int count = 0;
	//if (isValid(a, b, c)) {
	//	count++;
	//}
	for (int i = 0; i <= L && isValid(a, b, c); i++) {
		a += i;
		L -= i;
		for (int j = 0; j <= L && isValid(a, b, c); j++) {
			b += j;
			L -= j;
			for (int k = 0; k <= L && isValid(a, b, c); k++) {
				count++;			
				c += k;
				L -= k;
			}
		}
	}
	printf("%d\n", count);

	return 0;
}	
