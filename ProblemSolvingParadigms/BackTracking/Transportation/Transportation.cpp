/*
*****Solved*****
UVa 301

Problem Type:
backtracking
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

#define mp make_pair
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

typedef pair<ii, int> iii;

int N, Stops, M;
int station[8];
vector<iii> orders;
int profit, maxProfit;

void btrack(int p, int profit) {
	maxProfit = MAX(maxProfit, profit);
	if (p == orders.size()) return;

	int u = orders[p].first.first;
	int v = orders[p].first.second;
	int w = orders[p].second;

	bool fits = true;
	for (int i = u; i < v && fits; i++) {
		fits = (station[i] >= w);
	}

	if (fits) {
		//take order
		for (int i = u; i < v; i++) {
			station[i] -= w;
		}
		profit += (v - u)*w;
		btrack(p + 1, profit);
		profit -= (v - u)*w;
		for (int i = u; i < v; i++) {
			station[i] += w;
		}
	}
	btrack(p + 1, profit);
}

int main(){

	while (scanf("%d %d %d", &N, &Stops, &M), N || Stops || M) {
		orders.clear();
		for (int i = 0; i < M; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			orders.push_back(iii(ii(u, v), w));
		}

		sort(orders.begin(), orders.end());
		for (int i = 0; i < Stops; i++) {
			station[i] = N;
		}

		maxProfit = 0, profit = 0;
		btrack(0, 0);

		pf("%d\n", maxProfit);
	}

	return 0;
}	
