/*
*****Solved*****
UVa 11045

Problem Type:
max-flow
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
int N, M;
int res[40][40];
int mf, f, s, t;
vi p;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge; return;
	}
	else if (p[v] != -1) {
		augment(p[v], MIN(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

void resetVars() {
	MEM(res, 0);
	for (int i = 1; i <= M; i++) {
		res[0][i] = 1;
		res[i][0] = 1;
	}
	for (int i = 31; i <= 36; i++) {
		res[i][37] = N / 6;
		res[37][i] = N / 6;
	}
}

int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M;
		resetVars();
		string s;
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> s;
				if (s == "XS") {
					res[i][31]++;
					res[31][i]++;
				}
				else if (s == "S") {
					res[i][32]++;
					res[32][i]++;
				}
				else if (s == "M") {
					res[i][33]++;
					res[33][i]++;
				}
				else if (s == "L") {
					res[i][34]++;
					res[34][i]++;
				}
				else if (s == "XL") {
					res[i][35]++;
					res[35][i]++;
				}
				else if (s == "XXL") {
					res[i][36]++;
					res[36][i]++;
				}
			}
		}

		mf = 0;
		while (true) {
			f = 0;
			vi dist(40, INF); dist[0] = 0;
			queue<int> q; q.push(0);
			p.assign(40, -1);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == 37) break; 
				for (int v = 0; v < 40; v++) {
					if (res[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u] + 1;
						q.push(v); p[v] = u;
					}
				}
			}
			augment(37, INF);
			if (f == 0) break;
			mf += f;
		}

		if (mf == M)
			printf("YES\n");
		else
			printf("NO\n");
		
	}

	return 0;
}	
