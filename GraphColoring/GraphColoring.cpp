/*
*****Solved*****
UVa 193

Problem Type:
Recursive backtracking
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

int N, E;
vector<vi> AdjList;
bitset<110> colored;
bitset<110> black;
bitset<110> blacksol;
int maxblack;

void resetvars(){
	AdjList.assign(N+1, vi());
	maxblack = 0;
	colored.reset();
	black.reset();
	blacksol.reset();
}

bool hasAdjBlackNodes(int node){
	for (int i = 0; i < AdjList[node].size(); i++) {
		if (black[AdjList[node][i]]){
			//printf("tnode=%d\n", AdjList[node][i]);
			return true;
		}
	}
	return false;
}

void copyblack(){
	for (int i = 1; i <= N; i++) {
		blacksol[i] = black[i];
	}
}

void color(int node, int numblack){
	if (node > N){
		if (numblack > maxblack){
			maxblack = numblack;
			copyblack();
		}
		return;
	}

	colored.set(node);
	if (!hasAdjBlackNodes(node)){
		//printf("n=%d\n",node);
		black.set(node);
		color(node + 1, numblack + 1);
		black.reset(node);
	}

	color(node + 1, numblack);
	colored.reset(node);
}

int main(){

	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d", &N, &E);
		resetvars();
		for (int i = 0; i < E; i++) {
			int u, v; scanf("%d %d", &u, &v);
			AdjList[u].push_back(v);
			AdjList[v].push_back(u);
		}
		color(1, 0);

		vi ans;
		for (int i = 1; i <= N; i++) {
			if (blacksol[i])
				ans.push_back(i);
		}
		printf("%d\n", ans.size());
		if (ans.size()> 0){
			printf("%d", ans[0]);
			for (int i = 1; i < ans.size(); i++) {
				printf(" %d", ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}	
