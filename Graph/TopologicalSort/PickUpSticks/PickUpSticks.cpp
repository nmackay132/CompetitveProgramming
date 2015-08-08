/*
*****Solved*****
UVa 11686

Problem Type:
topological sort, cycle check
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

// _________________________________________________

const int UNVISITED = 0;
const int EXPLORED = 1;
const int VISITED = 2;

vector<vi> AdjList;
int N, M;
int visited[1000010];
bool isCycle;
vi ts;

void cycle(int u) {
	visited[u] = EXPLORED;
	for (int i = 0; i < (int)AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (visited[v] == UNVISITED)
			cycle(v);
		else if (visited[v] == EXPLORED) {
			isCycle = true;
		}
	}
	visited[u] = VISITED;
}

void toposort(int u) {
	visited[u] = true;
	for (int i = 0; i < (int)AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (!visited[v]) {
			toposort(v);
		}
	}
	ts.push_back(u);
}

int main() {
	while (scanf("%d %d", &N, &M), N || M) {
		AdjList.assign(N + 1, vi());
		MEM(visited, 0);

		for (int i = 0; i < M; ++i) {
			int u, v; scanf("%d %d", &u, &v);
			//			printf("%d %d\n",u,v);
			AdjList[u].push_back(v);
		}

		isCycle = false;
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				cycle(i);
			}
		}

		if (isCycle) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		MEM(visited, 0);
		ts.clear();
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				toposort(i);
			}
		}

		printf("%d", ts[ts.size() - 1]);
		for (int i = (int)ts.size() - 2; i >= 0; --i) {
			printf(" %d", ts[i]);
		}
		printf("\n");

	}
	return 0;
}



















