/*
*****Solved*****
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

int N;

int main(){
	vii nums;
	vi orig;
	vector<bool> noUse;
	vector<bool> used;
	scanf("%d", &N);
	int a;
	noUse.assign(N + 1, false);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		nums.push_back(ii(a,i));
		orig.push_back(a);
		if (a > 0 && a <= N)
			noUse[a] = true;
	}
	used.assign(N + 1, false);

	sort(nums.begin(), nums.end());
	int p = 1; int i = 0;
	while (noUse[p]) {
		p++;
	}

	while (i < N) {
		//printf("nums[i].first=%d\n", nums[i].first);
		if (nums[i].first == p) {
			used[p] = true;
		}
		else if (nums[i].first > 0 && nums[i].first <= N && !used[nums[i].first]) {
			used[nums[i].first] = true;
		}
		else {
			orig[nums[i].second] = p;
			used[p] = true;
		}
		while (used[p] || noUse[p]) {
			p++;
		}
		//printf("p=%d\n", p);
		i++;
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) printf("%d", orig[i]);
		else {
			printf(" %d", orig[i]);
		}
	}

	return 0;
}	
