/*
*****Solved*****
UVa 11101

Problem Type:
SSSP, multi-souce bfs
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

int G[2010][2010];
int D[2010][2010];

int main(){
	int P; int C;
	while (scanf("%d", &P), P){
		memset(&G, 0, sizeof(G));
		memset(&D, -1, sizeof(D));
		queue<ii> q;
		for (int i = 0; i < P; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			D[x][y] = 0;
			q.push(ii(x, y));
		}

		int Q; scanf("%d", &Q);
		for (int i = 0; i < Q; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			G[x][y] = 2;
		}

		int dx[] = { -1, 0, 1, 0 };
		int dy[] = { 0, 1, 0, -1 };
		int min = INF;
		bool done = false;
		while (!q.empty() && !done){
			ii u = q.front(); q.pop();

			for (int j = 0; j < 4; j++) {
				int x = u.first + dx[j]; int y = u.second + dy[j];
				if (x < 0 || x > 2001 || y < 0 || y > 2001) continue;

				if (D[x][y] == -1){
					//printf("test\n");
					D[x][y] = D[u.first][u.second] + 1;
					q.push(ii(x, y));

					if (G[x][y] == 2){
						min = D[x][y];
						done = true;
						break;
					}
					//printf("p=(%d, %d) d=%d\n", x, y, D[x][y]);
				}
			}
		}

		printf("%d\n", min);


	}

	return 0;
}	
