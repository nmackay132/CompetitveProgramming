/*
*****Solved*****
UVa 247

Problem Type:
graph, strongly connected components
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
#include <set>
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
const int VISITED = 1;
const int UNVISITED = -1;

int N, M;
vi dfs_num, dfs_low, S, visited;
vector<vi> AdjList;
int dfsNumberCounter;
map<string, int> dicc;
map<int, string> rdicc;
//map<ii, bool> edges;
set<ii> edges;
int numSCC;

void SCC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		//printf("u=%d v=%d\n",u,v);
		if (dfs_num[v] == UNVISITED)
			SCC(v);
		if (visited[v]) 
			dfs_low[u] = MIN(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]) {
		int count = 1;
		//printf("\t%d\n", ++numSCC);
		while (true) {
			int v = S.back(); S.pop_back();
			visited[v] = 0;
			if (count == 1) {
				cout << rdicc[v];
			}
			else {
				cout << ", " << rdicc[v];
			}
			count++;
			if (u == v) break;
		}
		printf("\n");
	}
}

int main(){
	int C = 1;
	while (cin >> N >> M, N || M) {
		if (C > 1) printf("\n");
		int V = 0;
		string a, b;
		AdjList.assign(N, vi());
		dicc.clear(); rdicc.clear(); edges.clear();
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			if (!dicc.count(a)) {
				dicc[a] = V;
				rdicc[V] = a;
				V++;
			}
			if (!dicc.count(b)) {
				dicc[b] = V;
				rdicc[V] = b;
				V++;
			}
			ii e = ii(dicc[a], dicc[b]);
			if (!edges.count(e)) {
				AdjList[dicc[a]].push_back(dicc[b]);
				edges.insert(e);
			}
		}

		numSCC = 0;
		dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0), visited.assign(N, 0);
		dfsNumberCounter = 0; S.clear();
		printf("Calling circles for data set %d:\n", C++);
		for (int i = 0; i < N; i++) {
			if (dfs_num[i] == UNVISITED) {
				SCC(i);
			}
		}
	}

	return 0;
}	
