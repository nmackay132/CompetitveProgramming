/*
*****Solved*****
UVa 1112

Problem Type:
graph, floyd warshall
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

vector<vii> AdjList;
vector<vi> AdjMat;

int main(){
	int N; scanf("%d", &N);
	while (N--){

		int V, F, T, E;
		cin >> V >> F >> T >> E;
		AdjMat.assign(V, vi());
		for (int i = 0; i < V; i++) {
			AdjMat[i].assign(V, INF);
		}

		for (int i = 0; i < E; i++) {
			int v, u, w;
			scanf("%d %d %d", &v, &u, &w);
			AdjMat[v - 1][u - 1] = w;
		}

		for (int k = 0; k < V; k++) {
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					AdjMat[i][j] = MIN(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
				}
			}
		}
		int count = 0;
		for (int i = 0; i < V; i++) {
			if (AdjMat[i][F - 1] <= T && i != F-1){
				count++;
				//printf("edge %d %d\n", i+1, F);
			}
		}
		//printf("2 to 2 %d\n", AdjMat[1][1]);
		printf("%d\n", count + 1);

		if (N)
			printf("\n");
	}

	return 0;
}

/*
2

4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

5
2
2
9
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 4
4 3 1
5 2 2
*/