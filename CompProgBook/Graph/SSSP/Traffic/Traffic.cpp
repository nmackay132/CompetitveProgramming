/*
*****Solved*****
UVa 10449

Problem Type:
graph, Bellman Ford's
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
vector<vii> AdjList;
int junctions[210];
const int VISITED = 1;
int been[210];
int visitedFromCycle[210];

void dfs1(int u) {
	been[u] = VISITED;
	for (int i = 0; i < AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (!been[v.first]) {
			dfs1(v.first);
		}
	}
}

void dfs2(int u) {
	visitedFromCycle[u] = VISITED;
	for (int i = 0; i < AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (!visitedFromCycle[v.first])
			dfs2(v.first);
	}
}

int main(){
	int C = 1;
	while (scanf("%d", &N) == 1) {
		int a;
		for (int i = 1; i <= N; i++) {
			scanf("%d", &a);
			junctions[i] = a;
		}
		
		scanf("%d", &M);
		int u, v;
		AdjList.assign(N + 1, vii());
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(ii(v, (int) pow(junctions[v]-junctions[u], 3)));
		}

		MEM(been, 0);
		dfs1(1);

		bool modified = true;
		vi dist(N+1, INF); dist[1] = 0;
		for (int i = 0; i < N && modified; i++) {
			modified = false;
			for (int u = 1; u <= N; u++) {
				for (int j = 0; j < AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
					if (dist[u] < INF && dist[v.first] > dist[u] + v.second) {
						dist[v.first] = dist[u] + v.second;
						modified = true;
					}
				}
			}
		}

		modified = true;
		MEM(visitedFromCycle, 0);
		for (int i = 0; i < N && modified; i++) {
			modified = false;
			for (int u = 1; u <= N; u++) {
				for (int i = 0; i < AdjList[u].size(); i++) {
					ii v = AdjList[u][i];
					if (dist[u] < INF && dist[v.first] > dist[u] + v.second) {
						modified = true;
						dfs2(v.first);
					}
				}
			}
		}

		printf("Set #%d\n", C++);
		int Q; scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			int u;
			scanf("%d", &u);
			if (dist[u] < 3 || dist[u] >= INF || visitedFromCycle[u])
				printf("?\n");
			else
				printf("%d\n", dist[u]);
		}
	}

	return 0;
}	
