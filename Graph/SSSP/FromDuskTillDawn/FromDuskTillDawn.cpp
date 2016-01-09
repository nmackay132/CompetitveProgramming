/*


Problem Type:

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

#define mp make_pair
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

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

int daysPassed(int a, int d) {
	if (a < 6 && (d > 18 || d < a)) return 1;
	if (a > 18 && d > 18 && d < a) return 1;
	return 0;
}

typedef pair<ii, int> iii;

int main(){

	int T; cin >> T;
	while (T--) {
		map<string, int> dicc;
		vector<vii> g;
		vii times;
		int M; cin >> M;
		g.assign(101, vii());
		int V = 0, E = 0;
		for (int i = 0; i < M; i++) {
			string u, v;
			int d, a;
			cin >> u >> v >> d >> a;
			if ((d < 18 && d > 6) || (a > 6 && a < 18)) continue; // wrong arrival or departure times
			if (d > a && ((d < 6 && a < 6) || (d > 18 && a > 18)) ) continue; // travel more than 12 hours
			if (a - d > 12) continue; // travel more than 12 hours
			if (dicc.count(u) == 0) {
				dicc[u] = V++;
			}
			if (dicc.count(v) == 0) {
				dicc[v] = V++;
			}
			g[dicc[u]].push_back(ii(dicc[v], E));
			g[dicc[v]].push_back(ii(dicc[u], E));
			times.push_back(ii(d, a));
		}

		string start, end; cin >> start >> end;
		if (dicc.count(start) == 0) {
			dicc[start] = V++;
		}
		if (dicc.count(end) == 0) {
			dicc[end] = V++;
		}

		priority_queue<ii> pq;
		vector<iii> dist(V, iii(ii(INF,0),0));
		dist[dicc[start]] = iii(ii(0,0),13); pq.push(ii(0, dicc[start]));
		while (!pq.empty()) {
			ii front = pq.top(); pq.pop();
			int u = front.second, d = -front.first;
			int udays = dist[u].second;
			if (d > dist[u].first.first) continue;
			for (int i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first; int e = g[u][i].second;
				if (dist[v].first.first > dist[u].first.first + d) {
					dist[v].first.first = dist[u].first.first + d;
					int arrTime = dist[u].second;
					int depTime = times[e].second;
					int days = daysPassed(arrTime, depTime);
				}

			}
		}
	}
	return 0;
}	
