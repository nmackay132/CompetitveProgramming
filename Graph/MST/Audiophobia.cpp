/*

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

int V, E, Q;
vector<vii> AdjList;
vector<int> dist;

vector<vii> mst;
vi taken;
priority_queue< pair<ii, int> > pq;

class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0); p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};


int minimum = -1;
void dfs(int v, int end){
	for (int i = 0; i < (int) mst[v].size(); i++) {
		ii u = mst[v][i];
		if (dist[u.first] == -1){
			dist[u.first] = max(u.second, dist[v]);
			//printf("%d\n", dist[u.first]);
			if (u.first == end){
				minimum = dist[u.first];
				return;
			}
			dfs(u.first, end);
		}
	}
} 

void process(int vtx){
	taken[vtx] = 1;
	for (int i = 0; i < (int) AdjList[vtx].size(); i++) {
		ii v = AdjList[vtx][i];
		if (!taken[v.first]) pq.push(make_pair(ii(-v.second, -v.first), -vtx));
	}
}

void makeMST(int start){
	taken.assign(V, 0);
	process(start);
	int prev = -1;
	while (!pq.empty()){
		pair<ii, int> front = pq.top(); pq.pop();
		int u = -front.first.second, w = -front.first.first, v = -front.second;
		if (!taken[u]){
			mst[v].push_back(ii(u, w));
			mst[u].push_back(ii(v, w));
			process(u);
		}
	}
}

void printMST(){
	printf("MST\n");
	for (int i = 0; i < mst.size(); i++) {
		for (int j = 0; j < mst[i].size(); j++) {
			printf("%d %d %d\n", i + 1, mst[i][j].first + 1, mst[i][j].second);
		}
	}
}

int main(){
	int c = 1;
	while (scanf("%d %d %d", &V, &E, &Q), V || E || Q){
		if (c>1) printf("\n");
		AdjList.assign(V, vii());
		mst.assign(V, vii());
		int v, u, d;
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &v, &u, &d);
			AdjList[v-1].push_back(ii(u-1, d));
			AdjList[u-1].push_back(ii(v-1, d));
		}


		printf("Case #%d\n", c++);
		while (Q--){
			scanf("%d %d", &v, &u);
			makeMST(v-1);
			//printMST();
			dist.assign(V, -1);
			minimum = -1;
			dfs(v-1, u-1);
			if (minimum == -1) printf("no path\n");
			else printf("%d\n", minimum);
		}
	}
	return 0;
}
*/

/*
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0
*/