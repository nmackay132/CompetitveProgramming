/*
*****Solved*****
UVa 11953

Problem Type:
graph, floodfill
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

int N;
vector<vector<char> > grid;

int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};

int floodfill(int r, int c){
	if (r < 0 || r >= N || c < 0 || c >= N) return 0;
	if (grid[r][c] != 'x' && grid[r][c] != '@') return 0;
	int ans;
	if (grid[r][c] == 'x') ans = 1;
	else ans = 0;
	grid[r][c] = 'o';
	for (int d = 0; d < 4; d++) {
		ans += floodfill(r + dr[d], c + dc[d]);
	}
	return ans;
}

int main(){
	int T, C = 1;
	scanf("%d", &T);
	while (T--){

		scanf("%d", &N);get
		string line; getline(cin, line);
		grid.assign(N, vector<char>());
		for (int r = 0; r < N; r++) {
			getline(cin, line);
			for (int c = 0; c < N; c++) {
				grid[r].push_back(line[c]);
			}
		}

		int boats = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (floodfill(r, c) > 0)
					boats++;
			}
		}

		printf("Case %d: %d\n", C++, boats);
		
	}

	return 0;
}

/*
2
4
x...
..x.
@.@.
....
2
..
x.
*/