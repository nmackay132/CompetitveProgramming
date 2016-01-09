/*

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
typedef pair < int, ii > iii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

map<string, int> dicc;
int V = 0;
vector<vector<iii> > AdjList;
vector<int> visited;

void dfs(int u, int val) {
	visited[u] = 1;
	for (int i = 0; i < AdjList[u].size(); i++) {
		iii x = AdjList[u][i];
		int v = x.first; int e1 = x.second.first, e2 = x.second.second;
		int aVal = lcm(val, e1);
		if (!visited[v]) {
			int bVal = lcm(aVal, )
			dfs(v);
		}
	}
}

int main(){
	while (true) {
		string line;
		getline(cin, line);
		stringstream ss(line);
		string temp, str1, str2;
		cin >> temp;
		if (temp[0] == '!') {
			int e1, e2; cin >> e1 >> str1;
			if (dicc.count(str1) == 0) {
				dicc[str1] = V++;
			}
			cin >> str2 >> e2 >> str2;
			if (dicc.count(str2) == 0) {
				dicc[str2] = V++;
			}
			AdjList[dicc[str1]].push_back(iii(dicc[str2], ii(e1, e2)));
			AdjList[dicc[str2]].push_back(iii(dicc[str1], ii(e2, e1)));
		}
		else if (temp[0] == '?') {
			cin >> str1 >> temp >> str2;
			if (dicc.count(str1) == 0 || dicc.count(str2) == 0) {
				cout << "?" << " " << str1 << " = ? " << str2;
			}
			else {
				int u = dicc[str1], v = dicc[str2];
				for (int i = 0; i < AdjList[u].size(); i++) {

				}
			}

		}

	}

	return 0;
}	
