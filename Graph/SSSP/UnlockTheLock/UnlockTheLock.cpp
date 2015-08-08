/*
*****Solved*****
UVa 12160

Problem Type:
bfs
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

vi buttons;
int G[10001];

int main(){

	int st, end, N; int C = 1;
	while (scanf("%d %d %d", &st, &end, &N), st || end || N){
		buttons.clear();
		for (int i = 0; i < N; i++) {
			int b; scanf("%d", &b);
			buttons.push_back(b);
		}
		//memset(&G, 0, sizeof(G));

		vi d;
		d.assign(10000, INF);
		d[st] = 0;
		queue<int> q; q.push(st);
		bool finished = false;
		while (!q.empty() && !finished){
			int u = q.front(); q.pop();
			for (int i = 0; i < buttons.size(); i++) {
				int v = (u + buttons[i]) % 10000;
				if (d[v] != INF) continue;
				d[v] = d[u] + 1;
				if (v == end){
					finished = true;
					break;
				}
				q.push(v);
			}
		}

		if (!finished){
			printf("Case %d: Permanently Locked\n", C++);
		}
		else{
			printf("Case %d: %d\n", C++, d[end]);
		}

	}
	return 0;
}	
