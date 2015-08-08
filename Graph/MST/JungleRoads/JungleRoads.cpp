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

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

int N;
vector<pair<int, ii> > EdgeList;

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
	while (true) {
		cin >> N;
		if (N == 0) break;
		//printf("t1\n");
		int u, v, w;
		char t;
		EdgeList.clear();
		int M;
		for (int i = 0; i < N-1; i++) {
			cin >> t;
			u = t - 'A';
			cin >> M;
			for (int i = 0; i < M; i++) {
				cin >> t;
				v = t - 'A';
				cin >> w;
				EdgeList.push_back(make_pair(w, ii(u, v)));
			}
		}

		sort(EdgeList.begin(), EdgeList.end());

		int mstCost = 0;
		UnionFind UF(N);
		for (int i = 0; i < EdgeList.size(); i++) {
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) {
				mstCost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}

		printf("%d\n", mstCost);
	}

	return 0;
}	
