/*

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
#include <unordered_set>
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

int V, E;
vector<vi> EdgeList;
vector<int> visited;

int main(){

	char A, B, C;
	while (scanf("%d %d", &V, &E) == 2) {

		scanf(" %c%c%c", &A, &B, &C);
		//cin >> A >> B >> C;
		int numAwake = 3;
		//visited.assign(26, -1);


		printf("char %c %c %c\n", &A, &B, &C);
		visited[A - 'A'] = 0;
		visited[B - 'A'] = 0;
		visited[C - 'A'] = 0;

		EdgeList.assign(26, vi());
		for (int i = 0; i < 26; i++) {
			EdgeList[i].assign(26, -1);
		}

		scanf("%d", E);
		for (int i = 0; i < E; i++) {
			scanf("%c%c", A, B);
			int a, b;
			a = A - 'A';
			b = B - 'A';
			EdgeList[a][b] = 1;
			EdgeList[b][a] = 1;
		}

		for (int i = 0; i < EdgeList.size(); i++) {
			for (int i = 0; i < EdgeList[i].size(); i++)
			{
				printf("edge %d %d\n", i, EdgeList);
			}
		}

		vii justAwoke;
		bool wasAdded = true;;
		int numYears = 0;
		while (numAwake < V){
			if (!wasAdded){
				printf("%d THIS BRAIN NEVER WAKES UP\n", numAwake);
				return 0;
			}
			wasAdded = false;
			justAwoke.clear();
			for (int i = 0; i < 26; i++) {
				if (EdgeList[i].size() > 0 && visited[i] == -1){
					//printf("test %d\n", i);
					int count = 0;
					int maxYears = -1;
					for (int j = 0; j < 26; j++) {
						if (EdgeList[i][j] == -1) continue;
						if (visited[j] >= 0) {
							count++;
							maxYears = max(maxYears, visited[j]);
						}
						if (count >= 3) break;
					}
					if (count >= 3){
						justAwoke.push_back(ii(i, maxYears));
						wasAdded = true;
						visited[i] = -2;
					}
				}
			}
			for (int i = 0; i < justAwoke.size(); i++) {
				visited[justAwoke[i].first] = justAwoke[i].second + 1;
				numYears = max(justAwoke[i].second + 1, numYears);
				numAwake++;
			}

		}

		printf("WAKE UP IN, %d, YEARS\n", numYears);
	}
	return 0;
}

/*
6
11
HAB
AB
AC
AH
BD
BC
BF
CD
CF
CH
DF
FH
*/

/*
struct edge { int nxt, to; } e[10048];
int ecnt, Next[32], vis[32];

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.nxt = Next[from];
	E.to = to;
	Next[from] = ecnt++;
}

int main(void){
	queue < pair<int, int> > q;
	char a, b, c;
	for (int m, n; scanf("%d %d", &n, &m) == 2;){
		int at, d, v, visited = ecnt = 0;
		for (int i = 0; i < 26; ++i) vis[i] = 0, Next[i] = -1;
		scanf(" %c%c%c", &a, &b, &c);
		//printf("%c %c %c\n", a, b, c);
		q.push(make_pair(a - 'A', 0)); vis[a - 'A'] = 3;
		q.push(make_pair(b - 'A', 0)); vis[b - 'A'] = 3;
		q.push(make_pair(c - 'A', 0)); vis[c - 'A'] = 3;
		while (m--){
			scanf(" %c%c", &a, &b);
			//    printf("%c %c\n", a, b);
			add_edge(a - 'A', b - 'A');
			add_edge(b - 'A', a - 'A');
		}
		while (!q.empty()){
			at = q.front().first;
			d = q.front().second;
			//    printf("%c, %d\n", at + 'A', d);
			q.pop();
			++visited;
			for (at = Next[at]; at != -1; at = e[at].nxt)
				if (++vis[v = e[at].to] == 3) q.push(make_pair(v, d + 1));
		}
		if (visited == n) printf("WAKE UP IN, %d, YEARS\n", d);
		else puts("THIS BRAIN NEVER WAKES UP");
	}
	return 0;
}
*/