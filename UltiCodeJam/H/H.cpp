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

int Z, I, M, L;
vi nums;
int Count;

int comp(int val) {
	int rem = (Z*val + I) % M;
	if (nums[val] != -1) {
		return (Count - nums[val]);
	}
	nums[val] = Count;
	//printf("count=%d\n", Count);
	Count++;
	comp(rem);
}

int main(){
	int C = 1;
	while (scanf("%d %d %d %d", &Z, &I, &M, &L), Z || I || M || L){
		nums.assign(100000, -1);
		Count = 0;
		//if (M == 0) {
		//	printf("Case %d: 1\n", C++);
		//	continue;
		//}
		int ans = comp(L);

		printf("Case %d: %d\n", C++, ans);
	}

	return 0;
}	
