/*
*****Solved*****
UVa 11413

Problem Type:
binary search
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

int N, M;
vi milk;

bool fill(int index, int c, int count) {
	if (count > M) return false;
	bool result = true;
	int sum = 0;
	for (int i = index; i < N; i++) {
		if (sum + milk[i] <= c) {
			sum += milk[i];
		}
		else {
			result &= fill(i, c, count + 1);
			break;
		}
	}
	return result;
}

int main(){
	while (scanf("%d %d", &N, &M) == 2) {
		milk.clear();
		int m;
		int min = -1, sum = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &m);
			milk.push_back(m);
			sum += m;
			min = MAX(min, m);
		}

		int ans = -1;
		int hi = sum+1, lo = min, mid;
		while (lo < hi) {
			mid = (hi + lo) / 2;
			if (fill(0, mid, 1)) {
				ans = mid;
				hi = mid;
			}
			else {
				lo = mid+1;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}	
