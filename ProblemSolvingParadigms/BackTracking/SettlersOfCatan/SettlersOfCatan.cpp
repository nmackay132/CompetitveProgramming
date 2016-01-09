/*
*****Solved*****
UVa 539

Problem Type:
backtracking, dfs
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

int N, M;
vector<vi> g;
vector<bool> visited;
int counter;
int Max;
map<ii, int> dicc;

int dfs(int u) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if ( !visited[dicc[ii(u,v)] ] ) {
			visited[dicc[ii(u,v)]] = true;
			counter++;
			Max = MAX(Max, counter);
			dfs(v);
			visited[dicc[ii(u, v)]] = false;
			counter--;
		}
	}
}

int main(){
	while (cin >> N >> M, N || M) {
		g.assign(N, vi());
		visited.assign(M, false);
		int E = 0;
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			ii e1 = ii(u, v);
			ii e2 = ii(v, u);
			dicc[e1] = E;
			dicc[e2] = E++;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		Max = 0;
		for (int i = 0; i < N; i++) {
			counter = 0;
			dfs(i);
		}

		printf("%d\n", Max);
	}

	return 0;
}	
