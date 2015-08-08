/*
*****Solved*****
UVa 315

Problem type:
graph, find articulation points
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
vi articulation_vertex, dfs_parent;
int rootChildren, dfsRoot;

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int i = 0; i < AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (dfs_num[v.first] == UNVISITED) {
			dfs_parent[v.first] = u;
			if (u == dfsRoot) rootChildren++;

			articulationPointAndBridge(v.first);

			if (dfs_low[v.first] >= dfs_num[u])
				articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		}
		else if (v.first != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
	}

}

int main(){

	int N;
	while (scanf("%d", &N), N){
		AdjList.assign(N, vii());
		while (true){
			int v;
			cin >> v;
			if (v == 0) break;
			string edges;
			getline(cin, edges);
			stringstream ss; ss.str(edges);
			int u;
			while (ss >> u){
				AdjList[v - 1].push_back(ii(u - 1, 0));
				AdjList[u - 1].push_back(ii(v - 1, 0));
			}
		}

		dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0);
		dfs_parent.assign(N, 0); articulation_vertex.assign(N, 0);
		dfsNumberCounter = 0;
		for (int i = 0; i < N; i++)	{
			if (dfs_num[i] == UNVISITED) {
				dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
			}
		}
		int countArticulationPoints = 0;
		for (int i = 0; i < N; i++)	{
			if (articulation_vertex[i])
				countArticulationPoints++;
		}
		printf("%d\n", countArticulationPoints);
		
	}
	return 0;
}

/*
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0
*/