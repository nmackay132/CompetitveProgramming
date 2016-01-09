/*


Problem Type:

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

const int  MAX_INT = numeric_limits<int>::max();
const int  MIN_INT = numeric_limits<int>::min();
const int INF = 1000000000;
const int  NEG_INF = -1000000000;

#define mp make_pair
#define sc scanf
#define pf printf
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
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

vector<vii> adjList, Tree;
vector<vi> cc;
vi low, num, parent, S, visited, label;
int numCount, SCC;

void tarjanSCC(int u) {
	low[u] = num[u] = numCount++;
	S.push_back(u);
	visited[u] = 1;
	for (int i = 0; i < adjList[u].size(); i++) {
		int v = adjList[u][i].first;
		if (num[v] == -1) {
			parent[v] = u;
			tarjanSCC(v);
		}

		if (visited[v] && parent[u] != v) {
			low[v] = min(low[u], low[v]);
		}

		if (low[u] == low[v]) {
			cc.push_back(vi());
			while (1) {
				int v = S.front(); S.pop_back();
				visited[v] = 0;
				cc[SCC].push_back(v);
				label[v] = SCC;
				if (u == v) break;
			}
			SCC++;
		}

	}
}

int N, M;

int main(){

	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		adjList.assign(N , vii());
		visited.assign(N, false);
		cc.clear();
		int u, v, w;
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			adjList[u].push_back(ii(v, w));
			adjList[v].push_back(ii(u, w));
		}


		for (int i = 0; i < adjList.size(); i++) {
			int u = label[i];
			for (int j = 0; j < adjList[i].size(); j++) {
				int v = label[adjList[i][j].first];
				int w = adjList[u][i].second;
				if (u == v) continue;
				Tree[u].push_back(ii(v, w));
				Tree[v].push_back(ii(u, w));
			}
		}

		for (int i = 0; i < Tree.size(); i++) {

		}


	}
	return 0;
}	
