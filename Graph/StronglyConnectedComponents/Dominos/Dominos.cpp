/*
*****Solved*****
UVa 11504

Problem Type:
scc
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
const int UNVISITED = -1;
int N, M;
vi low, num, S, visited, sccnum;
//vector<bool> visited;
int dfsNumCounter, numSCC;
vector<vi> g, incoming;

bool hasIncomingOutOfScc(int u) {
	for (int i = 0; i < incoming[u].size(); i++) {
		int v = incoming[u][i];
		if (low[v] != low[u])
			return true;
	}
	return false;
}

int SCC(int u) {
	low[u] = num[u] = dfsNumCounter++;
	visited[u] = 1;
	S.push_back(u);
	//printf("u=%d\n", u);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (num[v] == UNVISITED) {
			SCC(v);
		}
		if (visited[v] == 1) {
			low[u] = MIN(low[u], low[v]);
		}
	}
	if (num[u] == low[u]) {
		bool count = true;
		while (true) {
			int v = S.back(); S.pop_back();
			visited[v] = false;
			count = count && !hasIncomingOutOfScc(v);
			if (u == v) break;
		}
		if (count) {
			//printf("u=%d\n", u);
			numSCC++;
		}
	}
}


int main(){
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		int a, b;
		g.assign(N + 1, vi());
		incoming.assign(N + 1, vi());
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			incoming[b].push_back(a);
		}

		low.assign(N + 1, -1); num.assign(N + 1, UNVISITED);
		visited.assign(N + 1, 0); dfsNumCounter = 0;
		numSCC = 0; S.clear();
		for (int i = 1; i <= N; i++) {
			if (num[i] == UNVISITED) {
				SCC(i);
			}
		}

		printf("%d\n", numSCC);
	}

	return 0;
}	
