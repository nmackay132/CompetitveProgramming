/*
*****Solved*****
UVa 10503

Problem Type:
recursive backtracking
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
vii doms;
bitset<14> used;
ii Start;
ii End;
ii set[14];

bool btrack(int ind, int prv) {
	if (ind == N && prv == End.first /*|| prv == End.second)*/){
		//for (int i = 0; i < N; i++) {
		//	printf("%d-%d ", set[i].first, set[i].second);
		//}
		//printf("\n");
		return true;
	}
	if (ind == N) return false;

	bool result = false;
	for (int i = 0; i < M; i++) {
		ii d = doms[i];
		if (d.first == prv && !used[i]){
			used[i] = true;
			set[ind] = d;
			result = result || btrack(ind + 1, d.second);
			used[i] = false;
		}
		if (d.second == prv && !used[i]){
			used[i] = true;
			set[ind] = d;
			result = result || btrack(ind + 1, d.first);
			used[i] = false;
		}
	}
	return result;
}

int main(){

	while (scanf("%d", &N), N){
		doms.clear();
		scanf("%d", &M);
		scanf("%d %d", &Start.first, &Start.second);
		scanf("%d %d", &End.first, &End.second);

		for (int i = 0; i < M; i++) {
			ii d; scanf("%d %d", &d.first, &d.second);
			doms.push_back(d);
		}

		used.reset();
		bool ans = btrack(0, Start.second);// || btrack(0, Start.second);
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}	
