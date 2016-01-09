/*
*****Solved*****

Problem Type:
sssp, djikstras
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
const int  NEG_INF = -1000000000;

#define sc scanf
#define pf printf
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
#define are_equal(a,b)fabs(a-b)<EPS
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const ll INF = 1000000000000000;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

ll grid[1010][1010];
ll dist[1010][1010];
typedef pair<ll, ii> lii;
int dw[] = { -1, 0, 1, 0 };
int dh[] = { 0, 1, 0, -1 };

int main(){
	int T;
	cin >> T;
	while (T--) {
		map<char, int> weight;
		int k, w, h;
		cin >> k >> w >> h;
		char a; 
		int wt;
		for (int i = 0; i < k; i++) {
			cin >> a >> wt;
			weight[a] = wt;
		}
		char ch;
		ii start; string line; getline(cin, line);
		for (int i = 0; i < h; i++) {
			getline(cin, line);
			for (int j = 0; j < w; j++) {
				//cin >> ch
				ch = line[j];
				if (ch == 'E') {
					grid[i][j] = 0;
					dist[i][j] = 0; 
					start = ii(i, j);
				}
				else {
					grid[i][j] = weight[ch];
					dist[i][j] = INF;
				}
			}
		}

		priority_queue<lii> pq;
		pq.push(lii(0, start));
		ll res = INF;
		while (!pq.empty()) {
			lii front = pq.top(); pq.pop();
			ll d = -front.first;
			ii pos = front.second;
			if (d > dist[pos.first][pos.second]) continue;
			for (int i = 0; i < 4; i++) {
				ii _pos = ii(pos.first + dh[i], pos.second + dw[i]);
				if (_pos.first < 0 || _pos.first >= h || _pos.second < 0 || _pos.second >= w) {
					if (res > d) {
						res = d;
						if (res == 0)
							goto stop;
					}
				}
				else if (dist[_pos.first][_pos.second] > dist[pos.first][pos.second] + grid[_pos.first][_pos.second]) {
					dist[_pos.first][_pos.second] = dist[pos.first][pos.second] + grid[_pos.first][_pos.second];
					pq.push(lii(-dist[_pos.first][_pos.second], _pos));
				}
			}
		}
	stop:
		printf("%ld\n", res);


	}

	return 0;
}	
