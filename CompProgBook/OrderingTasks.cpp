/*
*****Solved*****
UVa 10305

Problem Type:
topological sort
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
int N, M;
const int V = 101;
int dfs_num[V];
vector<vii> AdjList;
vi ts;


void dfs2(int u){
	dfs_num[u] = 1;
	for (int i = 0; i < AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (dfs_num[v.first] == 0){
			dfs2(v.first);
		}
	}
	ts.push_back(u+1);
}

int main(){

	while (scanf("%d %d", &N, &M), (N || M)){
		AdjList.assign(N, vii());
		int u, v;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &u, &v);
			AdjList[u-1].push_back(ii(v-1,0));
		}
		fill_n(dfs_num, 101, 0);
		ts.clear();

		for (int i = 0; i < N; i++) {
			if (dfs_num[i] == 0)
				dfs2(i);
		}
		
		printf("%d",ts[ts.size()-1]);
		for (int i = ts.size()-2; i >= 0; i--) {
			printf(" %d", ts[i]);
		}
		printf("\n");
	}

	return 0;
}

/*
7 6
1 2
2 3
1 3
1 5
1 4
7 1
1 0
0 0
*/