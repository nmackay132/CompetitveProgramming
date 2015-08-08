/*
*****Solved*****
UVa 10986

Problem Type:
graph, djikstra's
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

vector<vii> AdjList;

int main(){
	int N, C = 1;
	scanf("%d", &N);
	while (N--){
		int V, E, S, T;
		scanf("%d %d %d %d", &V, &E, &S, &T);
		AdjList.assign(V, vii());
		for (int i = 0; i < E; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			AdjList[u].push_back(ii(v, w));
			AdjList[v].push_back(ii(u, w));
		}

		vi dist; dist.assign(V, INF); dist[S] = 0;
		priority_queue<ii> pq; pq.push(ii(0, S));
		while (!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = -front.first, u = front.second;
			if (d > dist[u]) continue;
			for (int i = 0; i < (int) AdjList[u].size(); i++) {
				ii v = AdjList[u][i];
				if (dist[u] + v.second < dist[v.first]) {
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(-dist[v.first], v.first));
				}
			}
		}

		if (dist[T] >= INF)
			printf("Case #%d: unreachable\n", C++);
		else
			printf("Case #%d: %d\n", C++, dist[T]);
	}

	return 0;
}

/*
3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1
*/