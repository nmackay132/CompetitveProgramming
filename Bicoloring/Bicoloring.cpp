/*
*****Solved*****
UVa 10004

Problem Type:
graph, bipartite
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

vector<vi> AdjList;
vi Color;
vi Visited;

int main(){
	int V, E;
	while (scanf("%d", &V), V) {
		scanf("%d", &E);
		AdjList.assign(V, vi());
		Visited.assign(V, 0);
		
		for (int i = 0; i < E; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		Color.assign(V, -1);
		bool bipartite = true;
		queue<int> q; q.push(0);
		Color[0] = 0;
		int c = 0;
		while (!q.empty() && bipartite) {
			int u = q.front(); q.pop();
			Visited[u] = 1;
			c = 1 - c;
			for (int i = 0; i < AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				if (Color[v] == Color[u]) {
					bipartite = false;
					break;
				} 
				else if(!Visited[v]){
					Color[v] = 1 - Color[u];
					q.push(v);
				}
			}
		}

		if (bipartite)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

	return 0;
}	
