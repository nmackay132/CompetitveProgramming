/*
UVa 11235

Problem Type:

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

int N, Q;
int offset = 100010;
vi C, cnt, start, finish;

// SEGMENT TREE


	vi st, A;
	int n;
	int left(int p) { return p << 1; }
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R) {		// O(n)
		if (L == R) {					// as L==R, either one is fine
			st[p] = L;					// store the index
		}
		else {						// recursively compute the values
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return -1;  // current segment outside query range
		if (L >= i && R <= j) return st[p];
		printf("L=%d R=%d i=%d j=%d\n", L, R, i, j);

		// compute the min position in the left and right part of the interval
		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);


		if (p1 == -1) return p2;	// if we try to access segment outside query
		if (p2 == -1) return p1;

		printf("");
		int c1 = p1 - start[p1] + 1;
		int c2 = finish[p2] - p2 + 1;
		return (c1 <= c2) ? p1 : p2;
	}

//public:
	//SegmentTree(const vi &_A) {
	//	A = _A; n = (int)A.size();			// copy content for local use
	//	st.assign(4 * n, 0);			// create large enough vector or zeros
	//	build(1, 0, n - 1);						// recursive build
	//}

	int rmq(int i, int j) {					// overloading
		printf("i=%d j=%d\n", i, j);
		return rmq(1, 0, A.size() - 1, i, j);
	}


int main(){
	while (scanf("%d", &N), N) {
		A.clear(); C.clear(); start.clear(); finish.clear();  cnt.clear();
		scanf("%d", &Q);
		int a;
		C.assign(200200, 0);
		cnt.assign(N, 0); start.assign(4*N, 0); finish.assign(4*N, 0);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a);
			a += offset;
			A.push_back(a);
			C[a]++;
		}
		//printf("t\n");

		int prv, prvI;
		for (int i = 0; i < N; i++) {
			cnt[i] = C[A[i]];
			if (i == 0) {
				start[i] = i;
				prvI = i;
			}
			else {
				if (A[i] == prv) {
					start[i] = prvI;
				}
				else {
					start[i] = i;
					prvI = i;
				}
			}
			prv = A[i];
		}
		//printf("t2\n");

		for (int i = N-1; i >= 0; i--) {
			if (i == N - 1) {
				finish[i] = i;
				prvI = i;
			}
			else {
				if (A[i] == prv) {
					finish[i] = prvI;
				}
				else {
					finish[i] = i;
					prvI = i;
				}
			}
			prv = A[i];
		}

		st.assign(4 * A.size(), 0);
		build(1, 0, A.size() - 1);
		printf("t3\n");
		int b;
		for (int i = 0; i < Q; i++) {
			scanf("%d %d", &a, &b);
			int ans = rmq(a, b);
			printf("%d\n", ans);
		}

	}

	return 0;
}	
