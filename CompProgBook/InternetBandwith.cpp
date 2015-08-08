/*
*****Solved*****
UVa 820

Problem Type:
graph, max flow
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

#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
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

vector<vi> res;
int N, S, T, E;
int mf, f;
vi p;

void augment(int v, int minEdge){
	if (v == S) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1){
		augment(p[v], MIN(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main(){
	
	int nCase = 1;
	while (scanf("%d", &N), N){
		scanf("%d %d %d", &S, &T, &E);

		res.assign(N + 1, vi());
		for (int i = 0; i < N+1; i++){
			res[i].assign(N+1, 0);
		}

		for (int i = 0; i < E; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			res[a][b] += c;
			res[b][a] += c;
		}
		mf = 0;
		while (true){
			f = 0;
			vi dist(N + 1, INF); dist[S] = 0; queue<int> q; q.push(S);
			p.assign(N + 1, -1);
			while (!q.empty()){
				int u = q.front(); q.pop();
				if (u == T) break;
				for (int v = 0; v < N+1; v++) {
					if (res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1; q.push(v); p[v] = u;
					}
				}
			}
			augment(T, INF);
			if (f == 0) break;
			mf += f;
		}

		printf("Network %d\n", nCase++);
		printf("The bandwidth is %d.\n\n", mf);
	}

	
	return 0;
}

/*
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0
*/