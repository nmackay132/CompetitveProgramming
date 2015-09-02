/*
*****Solved*****
UVa 11060

Problem Type:
topological sort with priority queue
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
vi revAdjList;

int main(){

	int N;
	map<string, int> vertices;
	vector<string> words;
	string str;
	int V = 0;
	int C = 1;
	while (scanf("%d", &N) != EOF){
		vertices.clear();
		words.clear();
		for (int i = 0; i < N; i++) {
			cin >> str;
			vertices[str] = i;
			words.push_back(str);
		}

		AdjList.assign(N, vi());
		revAdjList.assign(N, 0);
		int E; scanf("%d", &E);
		for (int i = 0; i < E; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			AdjList[vertices[str1]].push_back(vertices[str2]);
			revAdjList[vertices[str2]]++;
		}

		priority_queue<int> pq;
		for (int i = 0; i < revAdjList.size(); i++) {
			if (revAdjList[i] == 0)
				pq.push(-i);
		}

		vi toposorted;
		while (!pq.empty()){
			int u = -pq.top(); pq.pop();
			toposorted.push_back(u);	
			for (int i = 0; i < (int)AdjList[u].size(); i++) {
				int v = AdjList[u][i];
				revAdjList[v]--;
				if (revAdjList[v] == 0)
					pq.push(-v);
			}
		}

		printf("Case #%d: Dilbert should drink beverages in this order:", C++);
		for (int i = 0; i < toposorted.size(); i++)	{
			cout << " " << words[toposorted[i]];
		}
		printf(".\n\n");


	}
	return 0;
}	
