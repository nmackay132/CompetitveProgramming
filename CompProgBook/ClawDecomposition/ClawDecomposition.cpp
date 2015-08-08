/*
*****Solved*****
UVa 11396

Problem Type:
graph, bipartite graph check
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

int main(){
	int N;
	while (scanf("%d", &N), N) {
		AdjList.assign(N + 1, vi());
		int u, v;
		while (scanf("%d %d", &u, &v), u || v) {
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}

		queue<int> q;
		bool bipartite = true;
		for (int i = 1; i <= N; i++) {
			Color.assign(N + 1, -1);
			q.push(i);
			Color[i] = 0;
			while (!q.empty() && bipartite) {
				int u = q.front(); q.pop();
				for (int j = 0; j < AdjList[u].size(); j++) {
					int v = AdjList[u][j];
					if (Color[u] == Color[v]) {
						bipartite = false;
						break;
					}
					if (Color[v] == -1) {
						Color[v] = 1 - Color[u];
						q.push(v);
					}
				}
			}
		}

		if (bipartite)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}	
