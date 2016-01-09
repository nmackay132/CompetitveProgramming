/*

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

#define sc scanf
#define pf printf
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

int input[100][22];
map<ii, vi> dicc;
map<ii, int> rdicc;
vii nodes;

const int UNVISITED = -1;
vi dfs_num, dfs_low, S, visited;
int dfsNumCounter;
int scc[50];
bool possible;

void tarjanSSC(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumCounter++;  //dfs_low[u] <= dfs_num[u]
	S.push_back(u);		//  stores u in a vector based on order of visitation
	visited[u] = 1;
	for (int j = 0; j < (int)dicc[nodes[u]].size(); j++) {
		int v = dicc[nodes[u]][j];
		if (dfs_num[v] == UNVISITED)
			tarjanSSC(v);
		if (visited[v])			// condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if (dfs_low[u] == dfs_num[u]) {		//  if this is a root (start) of an SCC
		//printf("SCC %d", ++numSCC);
		while (1) {
			MEM(scc, 0);
			int v = S.back(); S.pop_back();
			ii n = nodes[v];
			if (scc[25 - n.first] || scc[25 - n.first]) {
				possible = false;
			}
			scc[25 + n.first] = true; scc[25 + n.second] = true;
			visited[v] = 0;
			//printf(" %d", v);
			if (u == v) break;
		}
		printf("\n");
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int rings, runes;
		dicc.clear();
		scanf("%d %d", &rings, &runes);
		for (int i = 0; i < runes; i++) {
			for (int j = 0; j < rings; j++) {
				scanf("%d", &input[i][j]);
			}
		}
		int V = 0; nodes.assign(2000, ii());
		for (int i = 0; i < runes; i++) {
			for (int j = 0; j < rings; j++) {
				if (dicc.count(ii(input[i][j], 0)) == 0) {
					ii node = ii(-input[i][j], 0);
					dicc[node] = vi();
					rdicc[node] = V;
					nodes[V] = node;
					V++;
				}
				for (int k = 0; k < rings; k++) {
					for (int l = k+1; l < rings; l++) {
						if (j == k || j == l) continue;
						ii node = ii(input[i][k], input[i][l]);
						if (rdicc.count(node) == 0) {
							rdicc[node] = V;
							nodes[V] = node; V++;
						}
						dicc[ii(-input[i][j], 0)].push_back(rdicc[node]);
					}
				}
			}
		}
		possible = true;
		dfs_low.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
		dfsNumCounter = 0;
		for (int i = 0; i < V; i++) {
			if (dfs_num[i] == UNVISITED)
				tarjanSSC(i);
		}

		if (possible) {
			printf("RUNES SATISFIED!\n");
		}
		else {
			printf("RUNES UNSATISFIABLE! TRY ANOTHER GATE!\n");
		}
	}

	return 0;
}	
