/*
*****Solved*****
UVa 11831

Problem Type:
graph traversal
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
vector<vector<char> > G;
int stickCount;
typedef pair<ii, int> iii;

iii nextLoc(ii pos, int dir, char cmd){
	if (cmd == 'D') dir++;
	if (cmd == 'E') dir--;
	if (dir == -1) dir = 3;
	if (cmd == 'F'){
		ii loc;
		if (dir == 0) loc = ii(pos.first - 1, pos.second);
		if (dir == 1) loc = ii(pos.first, pos.second + 1);
		if (dir == 2) loc = ii(pos.first + 1, pos.second);
		if (dir == 3) loc = ii(pos.first, pos.second - 1);
		if (loc.first < N && loc.first >= 0 && loc.second < M && loc.second >= 0
			&& G[loc.first][loc.second] != '#'){
			if (G[loc.first][loc.second] == '*') {
				stickCount++;
				G[loc.first][loc.second] = 't';
			}
			pos = loc;
			//printf("tpos=%d %d\n", pos.first, pos.second);
		}
	}
	return make_pair(pos, dir % 4);
}

int main(){

	int S; 
	while (scanf("%d %d %d", &N, &M, &S), N || M || S){
		string line; getline(cin, line);
		ii start;
		char dir;
		//printf("test0\n");
		G.assign(N, vector<char>());
		for (int i = 0; i < N; i++) {
			G[i].assign(M, 'Z');
		}
		//printf("test1\n");
		for (int i = 0; i < N; i++) {
			getline(cin, line);
			for (int j = 0; j < M; j++) {
				char c = line[j];
				G[i][j] = c;
				if (c == 'N' || c == 'S' || c == 'L' || c == 'O'){
					start = ii(i, j);
					if (c == 'N') dir = 0;
					if (c == 'L') dir = 1;
					if (c == 'S') dir = 2;
					if (c == 'O') dir = 3;
				}
			}
		}
		//printf("test2\n");
		stickCount = 0;
		getline(cin, line);
		iii status = iii(start, dir);
		//printf("pos=%d,%d dir=%d\n", status.first.first, status.first.first, status.second);
		for (int i = 0; i < S; i++) {
			char cmd = line[i];	
			status = nextLoc(status.first, status.second, cmd);
			//printf("pos=%d,%d dir=%d\n", status.first.first, status.first.second, status.second);
		}

		printf("%d\n", stickCount);

	}
	return 0;
}	
