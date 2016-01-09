/*
*****Solved*****
bfs
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
int cnt[100010], vis[100010], steps[100010];

int main(){
	scanf("%d", &N);

	int x;
	vi nums;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &x);

		queue<ii> q;

		q.push(ii(x, 0));
		while (!q.empty()) {
			int a = q.front().first;
			int count = q.front().second;
			q.pop();
			if (a > 100002) continue;
			if (vis[a] == i) continue;

			vis[a] = i;
			cnt[a]++;
			steps[a] += count;

			q.push(ii(a*2, count + 1));
			q.push(ii(a/2, count + 1));
		}

	}

	int min = INF;
	for (int i = 0; i < 100010; i++) {
		if (cnt[i] == N) {
			if (steps[i] < min) {
				min = steps[i];
			}
		}
	}

	printf("%d\n", min);


	return 0;
}	
