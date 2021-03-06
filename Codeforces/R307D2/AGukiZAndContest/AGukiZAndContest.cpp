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



int main(){

	int N;
	scanf("%d", &N);
	vi nums;
	vi orig;
	int a;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		nums.push_back(a);
		orig.push_back(a);
	}

	sort(nums.rbegin(), nums.rend());

	for (int i = 0; i < N; i++) {
		int a = orig[i];
		for (int j = 0; j < N; j++) {
			int b = nums[j];
			if (a == b) {
				printf("%d", j + 1);
				break;
			}
		}
		if (i != N - 1) {
			printf(" ");
		}
	}
	printf("\n");

	
	return 0;
}	
