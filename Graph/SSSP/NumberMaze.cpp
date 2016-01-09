/*
*****Solved*****
UVa 929

Problem Type:
graph, djikstra
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

int R, C;
vector<vii> AdjList;
vector<vi> grid;

int main(){
	int N;
	cin >> N;
	while (N--){
		scanf("%d %d", &R, &C);

		vector<vi> grid; grid.assign(R, vi());
		for (int i = 0; i < R; i++) {
			grid[i].assign(C, 0);
		}

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				scanf("%d", &grid[r][c]);
			}
		}

		vector<vi> dist; dist.assign(R, vi());
		for (int i = 0; i < R; i++) {
			dist[i].assign(C, INF);
		}

		int dx[] = {-1,0,1,0};
		int dy[] = {0,-1,0,1};

		priority_queue<pair<int, ii> > pq;
		pq.push(make_pair(-grid[0][0], ii(0, 0)));
		dist[0][0] = grid[0][0];
		while (!pq.empty()){
			pair<int, ii> front = pq.top(); pq.pop();
			int d = -front.first, r = front.second.first, c = front.second.second;
			if (d > dist[r][c]) continue;
			for (int i = 0; i < 4; i++) {
				if (r + dx[i] >= 0 && r + dx[i] < R && c + dy[i] >= 0 && c + dy[i] < C){
					int tr = r + dx[i], tc = c + dy[i];
					if (dist[r][c] + grid[r][c] < dist[tr][tc]){
						dist[tr][tc] = dist[r][c] + grid[r][c];
						pq.push(make_pair(-dist[tr][tc], ii(tr, tc)));
					}
				}
			}
		}
		printf("%d\n", dist[R - 1][C - 1] + grid[R-1][C-1] - grid[0][0]);
	}

	return 0;
}

/*
2
4
5
3 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
2 1 2 3 4 5
*/