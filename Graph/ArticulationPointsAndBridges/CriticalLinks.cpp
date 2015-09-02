/*
*****Solved*****
UVa 796

Problem type:
graph, articulation bridges
*/
/*
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
using namespace std;

const int  MAX_INT = std::numeric_limits<int>::max();
const int  MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int  NEG_INF = -1000000000;

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

#define UNVISITED -1

vector<vii> AdjList;
vi dfs_low, dfs_num;
int dfsNumberCounter;
vector<vi> articulation_bridge;
vi dfs_parent;
int rootChildren, dfsRoot;
int bridgeCounter;

void articulationBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int i = 0; i < (int)AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (dfs_num[v.first] == UNVISITED) {
			dfs_parent[v.first] = u;
			//if (u == dfsRoot) rootChildren++;

			articulationBridge(v.first);

			if (dfs_low[v.first] > dfs_num[u]) {
				articulation_bridge[u].push_back(v.first);
				bridgeCounter++;
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		}
		else if (v.first != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
	}
}

int main(){

	int N;
	while (scanf("%d", &N) == 1) {

		AdjList.assign(N, vii());
		REP(N) {
			int v, servers;
			scanf("%d (%d)", &v, &servers);
			REP(servers) {
				int u; scanf("%d", &u);
				AdjList[v].push_back(ii(u, 0));
				AdjList[u].push_back(ii(v, 0));
			}
		}

		dfs_low.assign(N, 0); dfs_num.assign(N, UNVISITED);
		articulation_bridge.assign(N, vi()); 
		dfs_parent.assign(N, 0);
		dfsNumberCounter = 0;
		bridgeCounter = 0;
		for (int i = 0; i < N; i++) {
			if (dfs_num[i] == UNVISITED){
				dfsRoot = i; rootChildren = 0;
				articulationBridge(i);
			}
		}

		printf("%d critical links\n", bridgeCounter);
		vii pairs;
		for (int i = 0; i < N; i++) {
			if (articulation_bridge[i].size() > 0)
				for (int j = 0; j < (int) articulation_bridge[i].size(); j++) {
					if (i < articulation_bridge[i][j])
						pairs.push_back(ii(i, articulation_bridge[i][j]));
					else
						pairs.push_back(ii(articulation_bridge[i][j], i));
					//printf("%d %d\n", i, articulation_bridge[i][j]);
				}
		}
		sort(pairs.begin(), pairs.end());
		for (int i = 0; i < pairs.size(); i++) {
			printf("%d - %d\n", pairs[i].first, pairs[i].second);
		}
		printf("\n");
	}
	return 0;
}

/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)
0


8
0 (3) 2 6 7
1 (1) 6
2 (2) 0 6
3 (1) 4
4 (2) 3 5
5 (1) 4
6 (3) 0 1 2
7 (1) 0

6
0 (1) 4
1 (2) 2 3
2 (3) 1 4 5
3 (1) 1
4 (2) 0 2
5 (1) 2
*/