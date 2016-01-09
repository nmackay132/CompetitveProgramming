/*
*****Solved*****
UVa 10653

Problem Type:
SSSP on Unweighted Graph, BFS
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

vector<vi> G;

int main(){
	int R, C;
	while (scanf("%d %d", &R, &C), R || C){
		G.assign(R, vi());
		for (int i = 0; i < R; i++)	{
			G[i].assign(C, 0);
		}
		int nr; scanf("%d", &nr);
		for (int i = 0; i < nr; i++) {
			int r, b; scanf("%d %d", &r, &b);
			for (int j = 0; j < b; j++) {
				int c; scanf("%d", &c);
				G[r][c] = 1;
			}
		}
		//printf("test1\n");
		ii start, end;
		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &end.first, &end.second);
		//printf("test2\n");

		queue<ii> q; 
		vector<vi> d;
		d.assign(R, vi());
		for (int i = 0; i < R; i++) {
			d[i].assign(C, INF);
		}
		d[start.first][start.second] = 0;
		int dc[] = {-1, 0, 1, 0};
		int dr[] = {0, 1, 0, -1};
		q.push(start);
		//printf("test3\n");
		bool finished = false;
		while (!q.empty() && !finished){
			ii u = q.front(); q.pop();
			int r = u.first; int c = u.second;
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i]; int nc = c + dc[i];
				if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if (d[nr][nc] < INF || G[nr][nc] == 1) continue;
				d[nr][nc] = d[r][c] + 1;
				if (nr == end.first && nc == end.second) {
					finished = true;  break;
				}
				q.push(ii(nr, nc));
			}
		}
		//printf("test4\n");

		printf("%d\n", d[end.first][end.second]);
	}

	return 0;
}	
