/*


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

#define sc scanf
#define pf printf
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
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

int N, M;
vector<vi> AdjList;

int compareVi(vi &vecA, vi &vecB, int a, int b) {
	if (a == b) return INF;
	for (int i = 0; i < vecA.size(); i++) {
		if (vecA[i] == b) continue;
		for (int j = 0; j < vecB.size(); j++) {
			if (vecA[i] == vecB[j]) {
				int c = vecA[i];
				return vecA.size() + vecB.size() + AdjList[c].size() - 6;
			}
		}
	}
	return INF;
}

int main(){
	scanf("%d %d", &N, &M);

	if (M <= 2) {
		printf("-1\n");
		return 0;
	}

	AdjList.assign(N + 1, vi());
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		AdjList[a].push_back(b);
		AdjList[b].push_back(a);
	}

	int min = INF;
	for (int i = 1; i <= N; i++) {
		int a = i;
		for (int j = 0; j < AdjList[i].size(); j++) {
			int b = AdjList[a][j];
			int val = compareVi(AdjList[a], AdjList[b], a, b);
			if (min > val) {
				min = val;
			}
		}
	}

	if (min == INF) {
		printf("-1\n");
	}
	else {
		printf("%d\n", min);
	}

	return 0;
}	
