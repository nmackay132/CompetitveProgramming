/*


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
const int SIZE = (20 + 5 + 5 + 6);

typedef bitset<SIZE> state;

int getX(state st) {
	state mask = ((1 << 5) - 1) << 20;
	mask &= st;
	mask = mask >> 20;
	return mask.to_ulong;
}

int setX(state st, int x) {
	state mask = (1 << 5) << 20;
	st 
	mask = mask >> 20;
	return mask.to_ulong;
}

int getY(state st) {
	state mask = ((1 << 5) - 1) << 25;
	mask &= st;
	mask = mask >> 25;
	return mask.to_ulong;
}

state down(state st) {
	state res = st;
	res[0] = st[2];
	res[1] = st[0];
	res[2] = st[5];
	res[5] = st[1];
	return res;
}

state up(state st) {

}

int board[20][20];
map<ii, int> vertices;
int X[20], Y[20];

int main(){

	string line;
	while (true) {
		int V = 0;
		int C, G;
		state start, end;
		for (int i = 0; i < 20; i++) {
			getline(cin, line);
			if (line == "") break;
			for (int j = 0; j < line.size(); j++) {
				char c = line[j];
				switch (c) {
				case '.':
					vertices[ii(i, j)] = V++;
					board[i][j] = 0;
					break;
				case 'P':
					start[V] = 1;
					vertices[ii(i, j)] = V++;
					board[i][j] = 1;
					break;
				case 'G':
					G = V;
					vertices[ii(i, j)] = V++;
					board[i][j] = 0;
					break;
				case 'C':
					C = V;
					start[V] = 0;
					vertices[ii(i, j)] = V++;
					board[i][j] = 0;
					break;
				case '#':
					board[i][j] = -1;
					break;
			}
		}
		beg 
	}

	return 0;
}	
