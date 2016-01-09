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
const int INF = 2100000000;
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
	scanf("%d", &N);

	vi cities;
	for (int i = 0; i < N; i++) {
		//ll c; scanf("%ld", &c);
		int c; cin >> c;
		cities.push_back(c);
	}

	for (int i = 0; i < N; i++) {
		int left = INF, right = INF;
		int c = cities[i];
		int max = 0;
		if (i > 0) {
			left = abs(c - cities[i - 1]);
			max = MAX(max, abs(c-cities[0]));
		}
		if (i < N - 1) {
			right = abs(c-cities[i + 1]);
			max = MAX(max, abs(c-cities[N - 1]));
		}
		int min = MIN(left, right);
		//printf("%ld %ld\n", min, max);
		cout << min << " " << max << endl;

	}

	return 0;
}	
