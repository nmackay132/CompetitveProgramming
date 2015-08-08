/*
*****Solved*****
UVa 872

Problem Type:
topological sort
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

vector<vi> AdjList;
vector<char> elements;
map<char, int> dicc;
map<int, char> rdicc;
vector<bool> visited;
int V;
bool possible = false;
vector<string> answers;

bool valid(int u) {
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (visited[v])
			return false;
	}
	return true;
}

bool dfs(vector<char> path){
	if (path.size() == V) {
		string str;
		str += path[0];
		for (int i = 1; i < V; i++) {
			string temp = " ";
			temp += path[i];
			str += temp;
		}
		answers.push_back(str);
		possible = true;
	}
	for (int u = 0; u < elements.size(); u++) {
		if (!visited[u] && valid(u)) {
			path.push_back(rdicc[u]);
			visited[u] = true;
			dfs(path);
			path.pop_back();
			visited[u] = false;
		}
	}
	return possible;
}

int main(){

	int T;
	scanf("%d", &T);
	string line; getline(cin, line);
	while (T--){
		getline(cin, line); getline(cin, line); //skip blank lines
		stringstream ss; ss.str(line);
		char c; elements.clear();
		V = 0;
		dicc.clear();
		while (ss >> c){
			elements.push_back(c);
			dicc[c] = V;
			rdicc[V] = c;
			V++;
		}
		getline(cin, line);
		ss.clear();
		ss.str(line);
		string token;
		AdjList.assign(elements.size(), vi());
		while (ss >> token){
			char a = token[0];
			char b = token[2];
			AdjList[dicc[a]].push_back(dicc[b]);
		}

		visited.assign(V, false);
		vector<char> path;
		answers.clear();
		possible = false;
		if (!dfs(path)) {
			printf("NO\n");
		}
		else {
			sort(answers.begin(), answers.end());
			for (int i = 0; i < answers.size(); i++) {
				cout << answers[i] << "\n";
			}
		}
		if (T != 0) {
			printf("\n");
		}
	}
	return 0;
}	
