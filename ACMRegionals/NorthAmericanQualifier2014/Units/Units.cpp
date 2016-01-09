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
typedef pair<int, string> is;
//map < string, vector<pair<int, string> > > dicc;
map<string, int> dicc;
vector<string> rdicc;
vector<vector<is> > g;
vector<bool> done;
vector<bool> visited;
vector<is> results;
int maxval;
int maxu;

void dfs(int u, int val) {
	visited[u] = true;
	if (val > maxval) {
		maxval = val;
		maxu = u;
	}
	for (int i = 0; i < g[u].size(); i++) {
		is p = g[u][i];
		int v = dicc[p.second];
		if (!visited[v] && !done[v]) {
			int newVal = val * p.first;
			dfs(v, newVal);
		}
	}
}

int main(){
	int N;
	while (cin >> N, N) {
		dicc.clear();
		g.assign(N, vector<is>());
		results.clear();
		done.assign(N, false);
		rdicc.clear();
		int V = 0;
		for (int i = 0; i < N; i++) {
			string unit; cin >> unit;
			dicc[unit] = V++;
			rdicc.push_back(unit);
		}
		for (int i = 0; i < N-1; i++) {
			string u1, eq, u2; int num;
			cin >> u1 >> eq >> num >> u2;
			g[dicc[u1]].push_back(mp(num, u2));
		}

		maxu = 0;
		while (true) {
			visited.assign(N, false);
			for (int i = 0; i < g.size(); i++) {
				dfs(i, 1);
			}
			string unit = rdicc[maxu];
			done[maxu] = true;
			results.push_back(is(maxval, unit));
		}
		pf("test2\n");

		for (int i = results.size()-1; i >= 0; i--) {
			if (i < results.size() - 1) cout << " = ";
			cout << results[i].first << results[i].second;
		}
		cout << endl;
	}
	
	return 0;
}	
