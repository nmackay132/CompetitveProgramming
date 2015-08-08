/*
*****Solved*****
UVa 10557

Problem Type:
graph, SSSP, Bellman's Ford
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
const int UNVISITED = 0;
const int VISITED = 1;

vector<vii> AdjList;
int N;
int visited[110];
int been[110];

void dfs1(int u) {
	been[u] = VISITED;
	for (int i = 0; i < AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (!been[v.first])
			dfs1(v.first);
	}
}

bool dfs2(int u) {
	visited[u] = VISITED;
	if (u == N) {
		return true;
	}
	for (int i = 0; i < AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (!visited[v.first] && dfs2(v.first)) {
			return true;
		}
	}
	return false;
}

int main(){
	while (scanf("%d", &N), N!=-1) {
		int w, n, u;

		AdjList.assign(N + 1, vii());
		int i = 1;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &w, &n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &u);
				AdjList[i].push_back(ii(u, -w));
			}
		}

		if (N == 1) {
			printf("winnable\n");
			continue;
		}

		//mark what vertices can be visited
		MEM(been, 0);
		dfs1(1);

		//Bellman Ford's
		vi dist(N + 1, INF); dist[1] = 0;
		bool modified = true;
		for (int i = 0; i < N && modified; i++) {
			modified = false;
			for (int u = 1; u <= N; u++) {
				for (int j = 0; j < AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
					if (100 > dist[u] + v.second && dist[u] + v.second < dist[v.first]) {
						dist[v.first] = dist[u] + v.second;
						modified = true;
					}
				}
			}
		}

		//check for negative cycle
		modified = true;
		bool reachableCycle = false;
		for (int i = 0; i < N && modified; i++) {
			modified = false;
			for (int u = 0; u < N; u++) {
				for (int j = 0; j < AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
					if (100 > dist[u] + v.second && dist[v.first] > dist[u] + v.second) {		// if this is still possible then negative cycle exists
					/*	printf("u=%d, v=%d\n", u, v.first);
						printf("\tdist[u]=%d, dist[v]=%d\n", dist[u], dist[v.first]);*/
						MEM(visited, 0);
						//printf("\t\tbeen[v]=%d\n", been[v.first]);
						if (dfs2(v.first) && been[v.first]) {
							reachableCycle = true;
						}
						modified = true;
					}
				}
			}
		}

		//printf("dist=%d\n", dist[N]);
		if (reachableCycle)
			printf("winnable\n");
		else if (dist[N] < 100) {
			printf("winnable\n");
			//printf("=%d\n", energy);
		}
		else
			printf("hopeless\n");

	}

	return 0;
}	
