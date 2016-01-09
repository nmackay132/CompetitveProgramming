/*
*****Solved*****
UVa 11838

Problem Type:
graph, SCC
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
const int UNVISITED = -1;
vector<vi> g;
vi num, lo, S, visited;
int numCounter, numSCC;

void SCC(int u) {
	num[u] = lo[u] = numCounter++;
	visited[u] = 1; S.push_back(u);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (num[v] == UNVISITED)
			SCC(v);
		if (visited[v])
			lo[u] = MIN(lo[u], lo[v]);
	}

	if (lo[u] == num[u]) {
		numSCC++;
		while (true) {
			int v = S.back();  S.pop_back();
			visited[v] = 0;
			if (u == v) break;
		}
	}
}

int main(){
	while (scanf("%d %d", &N, &M), N || M) {
		g.assign(N+1, vi());
		int u, v, w;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &w);
			g[u].push_back(v);
			if (w == 2) g[v].push_back(u);
		}

		num.assign(N + 1, UNVISITED); lo.assign(N + 1, 0); visited.assign(N + 1, 0);
		S.clear();
		numCounter = numSCC = 0;
		for (int i = 1; i <= N; i++) {
			if (num[i] == UNVISITED)
				SCC(i);
		}

		if (numSCC == 1) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}

	}

	return 0;
}	
