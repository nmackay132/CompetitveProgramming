/*
*****Solved*****
UVa 10765

Problem Type:
graph, articulation points, connected components
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

const int VISITED = 1;
const int UNVISITED = 0;
int N, M;
vector<vi> AdjList;
int dfs_root, rootChildren;
int dfs_num[10010];
int dfs_low[10010];
vi dfs_parent;
int dfsNumCounter;
int visited[10010];
int been[10010];
int pigeonCounter;
vii articulationPoints;
bool markedPoint[10010];
bool isArtPoint[10010];

void dfs(int u) {
	been[u] = VISITED;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!been[v]) {
			dfs(v);
		}
	}
}

// count connected components around articulation node
void getArtPoints(int u) {
	MEM(been, UNVISITED);
	pigeonCounter = 0;
	been[u] = VISITED;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int x = AdjList[u][i];
		if (!been[x]) {
			pigeonCounter++;
			dfs(x);
		}
	}
	articulationPoints.push_back(ii(pigeonCounter, -u));
	isArtPoint[u] = true;
}

void articulationPoint(int u) {
	dfs_num[u] = dfs_low[u] = dfsNumCounter++;
	visited[u] = VISITED;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (visited[v] == UNVISITED) {
			dfs_parent[v] = u;
			if (u == dfs_root) rootChildren++;
			articulationPoint(v);

			if (dfs_low[v] >= dfs_num[u] && !markedPoint[u]) {
				getArtPoints(u);
				markedPoint[u] = true;
			}
			dfs_low[u] = MIN(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u]) {
			dfs_low[u] = MIN(dfs_low[u], dfs_num[v]);
		}
	}
}

int main(){
	while (scanf("%d %d", &N, &M), N || M) {
		AdjList.assign(N, vi());
		int u, v;
		while (scanf("%d %d", &u, &v), u != -1 || v != -1) {
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		articulationPoints.clear();
		MEM(visited, 0);
		MEM(dfs_num, 0);
		MEM(dfs_low, 0);
		dfs_parent.assign(N, 0);
		MEM(markedPoint, false);
		MEM(isArtPoint, false);
		for (int a = 0; a < N; a++) {
			if (!visited[a]) {
				rootChildren = 0; dfs_root = a;
				articulationPoint(a);
				if (rootChildren > 1 && !markedPoint[a]) {
					getArtPoints(a);
				}
			}
		}

		sort(articulationPoints.rbegin(), articulationPoints.rend());

		//add non-articulation points to list
		for (int i = 0; i < N; i++) {
			if (!isArtPoint[i]) {
				articulationPoints.push_back(ii(1, -i));
			}
		}

		for (int i = 0; i < M; i++) {
			ii u = articulationPoints[i];
			printf("%d %d\n", -u.second, u.first); //vertex, pigeonCounter
		}
		printf("\n");
	}

	return 0;
}	
