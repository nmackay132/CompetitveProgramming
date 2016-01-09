/*
*****Solved******
UVa 439 and Ultimate Code Jam 1.0

Problem Type:
SSSP, bfs
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

int dist[10][10];
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
	char p1[2], p2[2];
	while (scanf("%s %s", p1, p2) == 2) {
		//printf("t1\n");
		int x1 = p1[0] - 'a';
		int y1 = p1[1] - '1';
		int x2 = p2[0] - 'a';
		int y2 = p2[1] - '1';
		//printf("x1=%d y1=%d\n", x1, y1);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				dist[i][j] = INF;
			}
		}

		int ans;
		queue<ii> q; q.push(ii(x1, y1));
		dist[x1][y1] = 0;
		while (!q.empty()) {
			ii u = q.front(); q.pop();
			int x = u.first, y = u.second;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == INF) {
					dist[nx][ny] = dist[x][y] + 1;
					if (nx == x2 && ny == y2) {
						ans = dist[nx][ny];
					}
					q.push(ii(nx, ny));
				}
			}
		}

		if (x1 == x2 && y1 == y2) {
			printf("To get from %s to %s takes 0 knight moves.\n", p1, p2);
		}
		else
			printf("To get from %s to %s takes %d knight moves.\n", p1, p2, ans);
	}

	return 0;
}	
