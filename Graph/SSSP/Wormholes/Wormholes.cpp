/*
*****Solved*****
UVa 558

Problem Type:
graph, sssp, bellmanford's, detect negative cycle
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

vector<vii> AdjList;

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		AdjList.assign(N, vii());
		for (int i = 0; i < M; i++) {
			int x, y, w;
			scanf("%d %d %d", &x, &y, &w);
			AdjList[x].push_back(ii(y,w));
		}

		vi dist(N, INF); dist[0] = 0;
		bool modified = true;
		for (int i = 0; i < N && modified; i++) {
			modified = false;
			for (int u = 0; u < N; u++) {
				for (int j = 0; j < AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
					if (dist[u] + v.second < dist[v.first]) {
						dist[v.first] = dist[u] + v.second;
						modified = true;
					}
					//dist[v.first] = MIN(dist[v.first], dist[u] + v.second);
				}
			}
		}

		bool negativeCycle = false;
		for (int i = 0; i < N; i++) {
			for (int u = 0; u < N; u++) {
				for (int j = 0; j < AdjList[u].size(); j++) {
					ii v = AdjList[u][j];
					if (dist[v.first] > dist[u] + v.second)
						negativeCycle = true;
				}
			}
		}

		if (negativeCycle)
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}	
