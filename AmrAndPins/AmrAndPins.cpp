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

//int main(){
//	ll r, x, y, xx, yy;
//	double dist;
//	scanf("%lld%lld%lld%lld%lld", &r, &x, &y, &xx, &yy);
//	dist = sqrt((double)((x - xx)*(x - xx) + (y - yy)*(y - yy)));
//	printf("%lld\n", (ll)ceil(dist / (2 * r)));
//	return 0;
//}

int main(){

	double r, x1, y1, x2, y2;
	//scanf("%ld %ld %ld %ld %ld", &r, &x1, &y1, &x2, &y2);
	cin >> r >> x1 >> y1 >> x2 >> y2;
	double dist = sqrt((double) (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	if (x1 == x2 && y1 == y2){
		printf("0\n");
	}
	else{
		ll x = (ll) ceil(dist / (2.0 * r));
		//printf("%ld\n", x);
		cout << x << "\n";
	}
	return 0;
}