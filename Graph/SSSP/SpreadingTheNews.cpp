/*
*****Solved*****
UVa 924

Problem Type:
graph, bfs
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

int V;
vector<vi> AdjList;
vi dist;
vi boomDays;
int maxIn = -1;
int big = 0;

void bfs(int start){
	queue<int> q; dist[start] = 0;
	boomDays[dist[start]]++;
	q.push(start);
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i < (int)AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			if (dist[v] == INF){
				dist[v] = dist[u] + 1;
				boomDays[dist[v]]++;
				if (boomDays[dist[v]] > big){
					big = boomDays[dist[v]];
					maxIn = dist[v];
				}
				q.push(v);
			}
		}
	}
}

int main(){
	scanf("%d", &V);
	AdjList.assign(V, vi());
	for (int i = 0; i < V; i++)	{
		int n; scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int v; scanf("%d", &v);
			AdjList[i].push_back(v);
		}
	}
	int t; scanf("%d", &t);
	while (t--){
		int start; scanf("%d", &start);
		dist.assign(V, INF);
		boomDays.assign(V, 0);
		big = 0, maxIn = -1;
		bfs(start);

		if (AdjList[start].size()== 0 || maxIn == -1) printf("0\n");
		else printf("%d %d\n", big, maxIn);
	}


	return 0;
}

/*
6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5




5
2 3 4
0
0
0
0
5
0
1
2
3
4




5
2 1 2
2 3 4
1 0
1 4
0
1
3
*/