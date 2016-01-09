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

pair<int, ii > arr[1000010];

int main(){
	scanf("%d", &N);
	int a;
	
	for (int i = 0; i < 1000010; i++) {
		arr[i] = make_pair(0, ii(-1, -1));
	}

	int max = 1;
	int maxNum = -1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);

		if (a > maxNum) maxNum = a;

		if (arr[a].first == 0) {
			arr[a].first++;
			arr[a].second.first = i;
			arr[a].second.second = i;
		}
		else {
			arr[a].first++;
			arr[a].second.second = i;
			if (arr[a].first > max) max = arr[a].first;
		}
	}
	
	int lt = -1, rt = -1;
	int minLen = INF;
	for (int i = 0; i <= maxNum; i++) {
		if (arr[i].first == max) {
			int l = arr[i].second.first;
			int r = arr[i].second.second;
			if (r - l < minLen) {
				lt = l;
				rt = r;
				minLen = r - l;
			}
		}
	}

	printf("%d %d\n", lt+1, rt+1);

	return 0;
}	
