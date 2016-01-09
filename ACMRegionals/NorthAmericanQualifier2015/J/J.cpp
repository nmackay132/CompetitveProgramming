/*


Problem Type:
graph, connected components
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

vi visited;
vector<vi> g;
bool found;
int st, fin;
vi path;
vector<string> rdicc;


void dfs(int u) {
	if (u == fin && !found) {
		found = true;
		for (int i = 0; i < path.size(); i++) {
			if (i != 0) cout << " ";
			cout << rdicc[path[i]];
		}
		cout << endl;
		return;
	}
	//cout << "u = " << rdicc[u] << endl;

	visited[u] = true;
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		
		if (!visited[v]) {
			path.push_back(v);
			dfs(v);
			path.pop_back();
		}
	}
}


int main(){
	int N;
	cin >> N;
	map<string, int> dicc;
	g.assign(N*N+1, vi());
	rdicc.clear();
	path.clear();
	visited.assign(N, false);

	int V = 0;
	string line;
	string s1, s2;
	getline(cin, line);
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		stringstream ss; ss.str(line);
		ss >> s1;
		if (dicc.count(s1) == 0) {
			dicc[s1] = V++;
			rdicc.push_back(s1);
		}
		while (ss >> s2) {
			if (dicc.count(s2) == 0) {
				dicc[s2] = V++;
				rdicc.push_back(s2);
			}
			g[dicc[s2]].push_back(dicc[s1]);
			g[dicc[s1]].push_back(dicc[s2]);
		}
	}

	cin >> s1 >> s2;
	st = dicc[s1]; fin = dicc[s2];

	found = false;
	path.push_back(st);
	dfs(st);


	if (!found) {
		cout << "no route found";
	}

	return 0;
}	
