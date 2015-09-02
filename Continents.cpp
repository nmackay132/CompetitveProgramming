/*
*****Solved*****
UVa 11094 

Problem Type:
graph, floodfill
/

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

int M, N;
char grid[21][21];
ii mark;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int floodfill(int r, int c, char c1, char c2){
	if (r < 0 || r >= M) return 0;
	if (c == -1) c = N - 1;
	if (c == N) c = 0;
	if (grid[r][c] != c1) return 0;
	int ans = 1;
	grid[r][c] = c2;
	for (int d = 0; d < 4; d++) 
		ans += floodfill(r + dr[d], c + dc[d], c1, c2);
	return ans;
}

int main(){
	while (scanf("%d %d", &M, &N) == 2){

		for (int i = 0; i < M; i++) {
			scanf("%s", grid[i]);
		}
		scanf("%d %d", &mark.first, &mark.second);
		char ch = grid[mark.first][mark.second];

		char ch2 = 'w';
		if (ch == ch2) ch2 = '.';

		floodfill(mark.first, mark.second, ch, ch2);

		int maxCount = 0;
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < N; c++) {
				int num = floodfill(r, c, ch, ch2);
				maxCount = max(num, maxCount);
			}
		}

		printf("%d\n", maxCount);
	}
	return 0;
}

/*
5 5
wwwww
wwllw
wwwww
wllww
wwwww
1 3

5 7
wwwwwww
llwllwl
lwwwwwl
wwllwwl
wwwwwww
1 3
*/