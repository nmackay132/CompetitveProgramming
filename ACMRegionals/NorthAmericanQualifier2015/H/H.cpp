//
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

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a*(b / gcd(a, b)); }

/**
* __builtin_popcount(int d) // count bits
* strtol(s, &end, base); // convert base number
*/
//----------------------------------------------------------------------//

int N;
char mat[110][110];

int main() {
	cin >> N;
	while (N--) {
		string str;
		cin >> str;
		MEM(mat, 0);
		int L = str.length();
		int fact = ceil(sqrt(L));
		int M = fact;
		int count = 0;
		for (int r = 0; r < M; ++r) {
			for (int c = 0; c < M; ++c) {
				if (count < L) {
					mat[r][c] = str[count++];
				}
				else {
					mat[r][c] = '*';
				}
			}
		}

		for (int layer = 0; layer < M / 2; ++layer) {
			int f = layer;
			int last = M - 1 - layer;
			for (int i = f; i < last; ++i) {
				int off = i - f;
				char top = mat[f][i];
				mat[f][i] = mat[last - off][f];
				mat[last - off][f] = mat[last][last - off];
				mat[last][last - off] = mat[i][last];
				mat[i][last] = top;
			}
		}

		for (int r = 0; r < M; ++r) {
			for (int c = 0; c < M; ++c) {
				if (mat[r][c] != '*') {
					cout << mat[r][c];
				}
			}
		}
		cout << endl;
	}
	return 0;
}