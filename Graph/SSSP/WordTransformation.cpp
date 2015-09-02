/*
*****Solved*****
UVa 429

Problem Type:
graph, single source shortest path (SSSP), bfs
*/

/*
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


vector<string> words;
int numWords = 0;
vector<vi> AdjList;
vi dist;

int bfs(int start, int end){
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int i = 0; i < (int) AdjList[v].size(); i++) {
			int u = AdjList[v][i];
			if (dist[u] == INF){
				dist[u] = dist[v] + 1;
				if (u == end)
					return dist[u];
				q.push(u);
			}
		}
	}
	return -1;
	
}

void makeGraph(){
	for (int i = 0; i < words.size(); i++) {
		string word1 = words[i];
		for (int j = i+1; j < words.size(); j++) {
			string word2 = words[j];
			int len1 = words[i].length();
			int len2 = words[j].length();
			if (len1 != len2) continue;
			int numDiff = 0;
			for (int k = 0; k < len1; k++) {
				if (word1[k] != word2[k])
					numDiff++;
			}
			if (numDiff == 1){
				AdjList[i].push_back(j);
				AdjList[j].push_back(i);
			}
		}
	}
}

int main(){

	int N;
	scanf("%d", &N);
	while(N--){
		string line;
		while (true) {
			cin >> line;
			if (line == "*") break;
			words.push_back(line);
			numWords++;
		}
		AdjList.assign(numWords, vi());
		
		makeGraph();
		
		getline(cin, line);
		string start, end;
		while (true){
			getline(cin, line);
			if (line == "") break;
			int pos = line.find(" ");
			start = line.substr(0, pos);
			end = line.substr(pos + 1, line.size());
			int stIn = -1, edIn = -1;
			for (int i = 0; i < words.size(); i++) {
				if (words[i] == start) stIn = i;
				if (words[i] == end) edIn = i;
			}

			dist.assign(numWords, INF);
			if (stIn == edIn)
				cout << start << " " << end << " " << 0 << "\n";
			else{
				int ans = bfs(stIn, edIn);
				cout << start << " " << end << " " << ans << "\n";
			}
		}
		if (N)
			cout << endl;
	}
	

	return 0;
}

/*
1

dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
may pod
spice stock



2

dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod
*/