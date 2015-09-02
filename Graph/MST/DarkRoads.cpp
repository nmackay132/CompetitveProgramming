/*
*****Solved*****
UVa 11631

Problem type:
graph, minimum spanning tree (Kruskal's)
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

int M, N;

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

int main(){
	while (scanf("%d %d", &M, &N), (M || N)){
		vector < pair<int, ii> > EdgeList;
		int totalCost = 0;
		int u, v, w;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u,v)));
			totalCost += w;
		}

		sort(EdgeList.begin(), EdgeList.end());

		int mstCost = 0;
		UnionFind UF(M);
		for (int i = 0; i < N; i++) {
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)){
				mstCost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", totalCost - mstCost);
	}
	return 0;
}

/*
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0

3 2
0 1 2000000
1 2 1
0 0
*/