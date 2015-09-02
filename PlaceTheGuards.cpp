/*
*****Solved*****

Problem Type:
graph, bipartite graph check
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

int V, E;
vector<vii> AdjList;
vi visited;

int bipartiteCheck(int s){
	int count0 = 1, count1 = 0;
	queue<int> q; q.push(s);
	vi color(V, INF);  color[s] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		visited[u] = 1;
		for (int i = 0; i < AdjList[u].size(); i++) {
			ii v = AdjList[u][i];
			if (u == v.first) continue;
			if (color[v.first] == INF) {
				color[v.first] = 1 - color[u];
				if (1 - color[u] == 0) count0++;
				else count1++;
				q.push(v.first);
			}
			else if (color[v.first] == color[u]) {
				return -1;
			}
		}
	}
	int min = min(count0, count1);
	if (min == 0) return max(count0, count1);
	return min;
}

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &V, &E);
		AdjList.assign(V, vii());
		for (int i = 0; i < E; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(ii(v,0));
			AdjList[v].push_back(ii(u, 0));
		}
		visited.assign(V, INF);
		int minCount = 0;
		for (int i = 0; i < V; i++) {
			if (visited[i] == INF){
				int num = bipartiteCheck(i);
				if (num == -1) { 
					minCount = -1;
					break; 
				}
				minCount += num;
			}

		}
		printf("%d\n", minCount);
	}

	return 0;
}

/*
3
4 2
0 1
2 3
5 5
0 1
1 2
2 3
0 4
3 4
5 3
0 1
0 2
0 3

1
4 3
2 0
2 1
2 3
*/