/*
*****Solved*****
UVa 750

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

#define mp make_pair
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

int row[9], col[9], rd[18], ld[18];
int solNum;

void btrack(int c) {

	if (c == 9) {
		printf("%2d      %d", solNum++, col[1]);
		for (int i = 2; i <= 8; i++) {
			printf(" %d", col[i]);
		}
		printf("\n");
		return;
	}
	
	if (col[c] != 0) {
		//pf("t\n");
		btrack(c + 1);
	}
	else {
		for (int r = 1; r <= 8; r++) {
			if (row[r] == 0 && rd[r - c + 8] == 0 && ld[r + c] == 0) {
				//pf("r=%d c=%d\n", r, c);
				col[c] = r;
				row[r] = 1;
				ld[r + c] = 1;
				rd[r - c + 8] = 1;
				btrack(c + 1);
				col[c] = 0;
				row[r] = 0;
				ld[r + c] = 0;
				rd[r - c + 8] = 0;
			}
		}
	}
}

int main(){

	int T; cin >> T;
	while (T--) {
		int r, c; 
		cin >> r >> c;
		MEM(row, 0); MEM(col, 0); MEM(rd, 0), MEM(ld, 0);
		col[c] = r;
		row[r] = 1;
		rd[r - c + 8] = 1;
		ld[r + c] = 1;

		solNum = 1;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		btrack(1);

		if (T) printf("\n");
	}
	return 0;
}	
