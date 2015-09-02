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

const int  min_int = std::numeric_limits<int>::min();
const int max_int = std::numeric_limits<int>::max();

#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
#define FOR(i,s,n)for(i=s;i<n;i++)
#define REP(n)int decrement = n;while(decrement--)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define inf (1<<30)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define iszero(a)fabs(a)<eps

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ if (b == 0)return a; return gcd(b, a%b); }

struct io {
	template<class T> static inline T next(){
		T tmp;	std::cin >> tmp; return tmp;
	};
};

//----------------------------------------------------------------------//
vi set;

int find(int i){
	if (set[i] < 0)return i;
	return set[i] = find(set[i]);
}

bool areJoined(int u, int v){
	return find(u) == find(v);
}

void join(int u, int v){
	if (!areJoined(u, v)){
		int p_u = find(u);
		int p_v = find(v);

		if (set[p_u] < set[p_v]){
			set[p_v] = p_u;
		}
		else if (set[p_v] < set[p_u]){
			set[p_u] = p_v;
		}
		else{
			set[p_v] = p_u;
			set[p_u]--;
		}
	}
}

vector<vii> MST;
vi visited;
bool done;
void minmax(int u, int dest, int max_edge){
	visited[u] = true;
	if (u == dest){
		printf("%d\n", max_edge);
		done = true;
	}
	else{
		for (int i = 0; !done && i < MST[u].size(); i++){
			int v = MST[u][i].first, w = MST[u][i].second;
			if (!visited[v]){
				minmax(v, dest, max(max_edge, w));
			}
		}
	}
}

int main(){

	int C, S, Q, i, j, Case = 1;
	bool line = false;
	while (scanf("%d %d %d", &C, &S, &Q) == 3 && C && S && Q){

		if (line)printf("\n");
		line = true;

		vector<pair<int, ii> > streets;

		// Load edges
		FOR(i, 0, S){
			int u = io::next<int>(), v = io::next<int>(), s = io::next<int>();
			streets.push_back(make_pair(s, ii(u, v)));
		}

		// Create the MST (Kruskall)
		sort(streets.begin(), streets.end());
		set.assign(C + 1, -1);
		MST.assign(C + 1, vii());
		int st_size = 0;
		for (i = 0; i < streets.size() && st_size < C - 1; i++){
			int u = streets[i].second.first;
			int v = streets[i].second.second;
			int w = streets[i].first;
			if (!areJoined(u, v)){
				MST[v].push_back(ii(u, w));
				MST[u].push_back(ii(v, w));
				join(u, v);
				st_size++;
			}
		}

		printf("Case #%d\n", Case++);
		// Traverse MST from s to d and find the largest edge
		FOR(i, 0, Q){
			done = false;
			visited.assign(C + 1, 0);
			int src = io::next<int>();
			int dest = io::next<int>();
			if (!areJoined(src, dest))
				printf("no path\n");
			else
				minmax(src, dest, 0);
		}

	}

	return 0;
}


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

int V, E, Q;
vector< pair<int, ii> > EdgeList;
vector<int> dist;

vector<vii> mst;

class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0); p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y])
				p[y] = x;
			else{
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
};

int minimum = -1;
void dfs(int v, int end){
	for (int i = 0; i < (int)mst[v].size(); i++) {
		ii u = mst[v][i];
		if (dist[u.first] == -1){
			dist[u.first] = max(u.second, dist[v]);
			//printf("%d\n", dist[u.first]);
			if (u.first == end){
				minimum = dist[u.first];
				return;
			}
			dfs(u.first, end);
		}
	}
}

void printMST(){
	printf("MST\n");
	for (int i = 0; i < mst.size(); i++) {
		for (int j = 0; j < mst[i].size(); j++) {
			printf("%d %d %d\n", i, mst[i][j].first, mst[i][j].second);
		}
	}
}


int main(){
	int c = 1;
	while (scanf("%d %d %d", &V, &E, &Q), V || E || Q){
		if (c>1) printf("\n");
		mst.assign(V+1, vii());
		EdgeList.assign(V + 1, make_pair(INF, ii()));
		int v, u, d;
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &v, &u, &d);
			EdgeList.push_back(make_pair(d, ii(v, u)));
		}
		sort(EdgeList.begin(), EdgeList.end());

		UnionFind UF(V+1);
		int setSize = 0;
		for (int i = 0; i < EdgeList.size() && setSize < E-1; i++) {
			pair<int, ii> front = EdgeList[i];
			int v = front.second.first, u = front.second.second;
			int w = front.first;
			if (!UF.isSameSet(v, u)){
				mst[u].push_back(ii(v,w));
				mst[v].push_back(ii(u,w));
				UF.unionSet(v, u);
				setSize++;
			}
		}

		//printMST();

		printf("Case #%d\n", c++);
		while (Q--){
			scanf("%d %d", &v, &u);
			dist.assign(V+1, -1);
			minimum = -1;
			if (UF.isSameSet(v,u))
				dfs(v, u);
			if (minimum == -1) printf("no path\n");
			else printf("%d\n", minimum);
		}
	}
	return 0;
}
*/

/*
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0






12 5 17
8 10 319
1 11 677
7 12 353
5 12 528
10 5 704
11 9
9 0
5 7
10 6
1 11
1 8
4 2
4 1
10 8
0 6
5 11
0 2
11 4
11 7
4 10
8 1
2 1
17 12 3
13 5 333
6 3 731
12 1 801
1 15 548
2 12 298
14 12 336
7 4 519
13 8 901
11 6 227
1 17 99
17 13 646
1 9 573
9 2
4 3
2 9
4 4 0
2 1 226
2 4 61
1 3 930
2 3 310
12 7 16
3 8 569
2 8 289
7 2 809
12 1 870
1 8 511
7 3 250
3 10 988
3 4
2 6
7 6
0 2
4 2
3 9
1 0
6 10
6 9
3 9
9 2
4 2
10 2
6 1
10 1
8 5
12 16 8
4 3 347
6 8 636
3 10 114
6 4 660
9 1 757
11 9 633
8 12 403
2 6 405
12 7 281
9 7 77
1 2 848
12 5 201
7 5 382
3 5 140
5 2 773
12 1 529
0 9
10 3
8 11
4 2
8 4
7 0
4 6
4 8
16 8 15
2 1 57
12 2 197
4 15 323
12 7 852
12 4 138
10 8 645
14 12 181
3 5 903
6 12
2 14
7 3
15 9
14 0
6 1
14 1
12 4
5 8
7 15
8 10
0 6
5 13
8 9
12 14
15 2 8
15 1 683
10 13 571
7 6
9 4
14 12
6 2
12 0
14 10
12 11
0 10
17 2 10
8 11 32
10 3 612
9 14
16 8
15 14
10 12
4 10
6 14
7 5
15 3
16 5
0 11
1 0 0
3 2 6
3 2 843
2 1 491
1 0
2 0
2 1
1 2
1 0
0 2
0 0 0
*/