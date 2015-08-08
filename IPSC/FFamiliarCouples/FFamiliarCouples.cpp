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
#include <fstream>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int NEG_INF = -1000000000;

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;



class UnionFind {
private:
	vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
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
			if (rank[x] > rank[y])
				p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}

};

int main() {
	int c, n, q, t, a, b;
	cin >> c;
	ofstream myfile;
	myfile.open("output2.txt");
	while (c--) {
		cin >> n >> q;
		UnionFind UF1(n);
		UnionFind UF2(n);
		ll total = 0;
		ll pairs = 0;
		for (int i = 1; i <= q; i++) {
			cin >> t >> a >> b;
			a--;
			b--;
			if (t == 1) {
				if (!UF1.isSameSet(a, b)) {
					for (int j = 0; j < n; j++) {
						if (!UF1.isSameSet(a, j))
							continue;
						for (int k = 0; k < n; k++) {
							if (k == j ||  a == k) continue;
							if (!UF1.isSameSet(b, k))
								continue;
							if (UF2.isSameSet(j, k))
								pairs++;
						}
					}
				}
				UF1.unionSet(a, b);
			}
			else {
				if (!UF2.isSameSet(a, b)) {
					for (int j = 0; j < n; j++) {
						if (!UF2.isSameSet(a, j))
							continue;
						for (int k = 0; k < n; k++) {
							if (k == j || a == k) continue;
							if (!UF2.isSameSet(b, k))
								continue;
							if (UF1.isSameSet(j, k))
								pairs++;
						}
					}
				}
				UF2.unionSet(a, b);
			}
			ll temp = pairs * i;
			total += temp;
			//			cout << i << " " << t << " " << a+1 << " " << b+1 << ": " << total << endl;
		}
		total %= 1000000007;
		myfile << total << endl;
	}
	myfile.close();
	return 0;
}
