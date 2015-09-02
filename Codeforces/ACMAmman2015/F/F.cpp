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

#define sc scanf
#define pf printf
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

int V, E;

//KRUSKAL'S
class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0); p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};


int main(){
	int T; scanf("%d", &T);
	while (T--) {
		vector<pair<int, ii> > EdgeList;
		scanf("%d %d", &V, &E);

		int totalCost = 0;
		int u, v, w;
		for (int i = 0; i < E; i++) {
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u-1, v-1)));
		}

		sort(EdgeList.begin(), EdgeList.end());

		int max = -INF;
		int mstCost = 0;
		UnionFind UF(V);
		for (int i = 0; i < E; i++) {
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) {
				//mstCost += front.first;
				max = MAX(max, front.first);
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		//printf("mstCost=%d\n", mstCost);
		printf("%d\n", max);
	}
	return 0;
}	
