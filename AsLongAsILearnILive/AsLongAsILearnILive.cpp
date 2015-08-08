/*
*****Solved*****
UVa 12376

Problem Type:
graph
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



int main(){
	int T; scanf("%d", &T);
	int C = 1;
	while (T--){
		int V, E;
		vi vVal;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < V; i++) {
			int n; scanf("%d", &n);
			vVal.push_back(n);
		}
		
		vector<vi> AdjList;
		AdjList.assign(V, vi());
		for (int i = 0; i < E; i++) {
			int u, v; scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
		}

		vi visited;
		visited.assign(V, 0);
		int curr = 0;
		int learn = 0;
		int max = -1;
		int maxI = -1;
		while (true){
			max = -1;
			maxI = -1;
			learn += vVal[curr];
			visited[curr] = 1;
			if (AdjList[curr].size() == 0) break;
			bool done = true;
			for (int i = 0; i < AdjList[curr].size(); i++) {
				int u = AdjList[curr][i];
				if (vVal[u] > max && visited[u] == 0){
					//printf("test\n");
					max = vVal[u];
					maxI = u;
					done = false;
				}
			}
			curr = maxI;
			if (done) break;
		}

		printf("Case %d: %d %d\n", C++, learn, curr);
	}

	return 0;
}	
