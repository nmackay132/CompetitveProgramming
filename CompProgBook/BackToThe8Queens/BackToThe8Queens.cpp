/*
*****Solved*****
UVa 11085

Problem Type:
backtracking
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

int row[9];
int trow[9];
vector<vi> solutions;
int sol[92][9];
int si = 0;

bool valid(int r, int c){
	for (int tc = 1; tc < c; tc++) {
		if (trow[tc] == r || abs(trow[tc] - r) == abs(tc - c)){
			return false;
		}
	}
	return true;
}

void btrack(int c){
	if (c == 9){
		for (int i = 1; i <= 8; i++) {
			sol[si][i] = trow[i];
		}
		si++;
		return;
	}

	for (int r = 1; r <= 8; r++) {
		if (valid(r, c)){
			//printf("row %d col %d\n", r, c);
			trow[c] = r;
			btrack(c + 1);
		}
	}
}

int main(){
	memset(&trow, 0, sizeof(trow));
	btrack(1);
	int C = 1;
	while (scanf("%d %d %d %d %d %d %d %d",
		&row[1], &row[2], &row[3], &row[4], &row[5], &row[6], &row[7], &row[8]) == 8){

		int minMoves = INF;
		for (int i = 0; i < 92; i++) {
			int moves = 0;
			//printf("C%d:\t", i + 1);
			for (int j = 1; j < 9; j++) {
				//printf("%d ", sol[i][j]);
				if (sol[i][j] != row[j])
					moves++;
			}
			//printf("\n");
			minMoves = MIN(minMoves, moves);
		}

		printf("Case %d: %d\n", C++, minMoves);

	}

	return 0;
}	
