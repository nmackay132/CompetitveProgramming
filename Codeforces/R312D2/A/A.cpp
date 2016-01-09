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
	scanf("%d", &N);
	vii left, right;
	int x, a;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &a);
		if (x < 0) {
			left.push_back(ii(-x, a));
		}
		else {
			right.push_back(ii(x, a));
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	int min = MIN(left.size(), right.size());

	int count = 0;
	if (left.size() < right.size()) {
		for (int i = 0; i < min+1; i++) {
			count += right[i].second;
		}
		for (int i = 0; i < min; i++) {
			count += left[i].second;
		}
	}
	else if(right.size() < left.size()){
		for (int i = 0; i < min + 1; i++) {
			count += left[i].second;
		}
		for (int i = 0; i < min; i++) {
			count += right[i].second;
		}
	}
	else {
		for (int i = 0; i < min; i++) {
			count += right[i].second;
			count += left[i].second;
		}
	}

	printf("%d\n", count);

	return 0;
}	
