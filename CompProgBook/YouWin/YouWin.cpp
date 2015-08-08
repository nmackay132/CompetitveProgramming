/*
Problem J
2013 ACM Southeastern Regionals

Problem Type:
dp with bitstring
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

int MAXV;
int memo[1 << 20][20];
string Word;
int Len;
int Count = 0;

int calc(int state, int curs){
	Count++;
	if (Count > 17) return 0;
	printf("s=%d c=%d\n", state, curs);
	if (state == 0) return 0;
	if (memo[state][curs] != -1) return memo[state][curs];
	int min = INF;
	int newstate = (1 << curs) ^ state;

	for (int i = 0; i < Len; i++) {
		if ((1 << i) & newstate == 0) continue;

		int d = abs(Word[curs] - Word[i]);
		int dist = MIN(d, 26 - d) + 1;
		//printf("dist=%d\n", dist);
		if (curs < i){
			for (int j = curs; j < i; j++) {
				if ((1 << j) & state != 0){
					dist++;
				}
			}
			//printf("s=%d c=%d i=%d dist=%d\n", state, curs, i, dist);
			min = MIN(min, dist + calc(state ^ (1<<i), i));
		}
		else {
			//printf("2s=%d c=%d i=%d dist=%d\n", state, curs, i, dist);
			for (int j = i; j <= curs; j++) {
				if ((1 << j) & state != 0){
					dist++;
				}
			}
			min = MIN(min, dist + calc(state ^ (1 << i), i));
		}
	}
	return memo[state][curs] = min;
}

int main(){

	while (true){
		cin >> Word;
		if (Word == "0") break;
		Len = Word.length();
		MAXV = (1 << Len) - 1;
		memset(&memo, -1, sizeof(memo));
		//printf("%d\n", calc(0, 0));
		int min = INF; for (int i = 0; i < Len; i++)
		{
			//printf("len=%d & %d\n", Len, (1 << Len) - 1);
			min = MIN(min,calc((1 << Len)-1, i));
		}
		printf("%d\n", min);
	}
	return 0;
}	


/*
int calc(int state, int curs){
Count++;
if (Count > 10) return 0;
//printf("s=%d c=%d\n", state, curs);
if (state == MAXV) return 0;
if (memo[state][curs] != -1) return memo[state][curs];
int min = INF;
for (int i = 0; i < Len; i++) {
if ((1 << i) & state != 0) continue;
int d = abs(Word[curs] - Word[i]);
int dist = MIN(d, 26 - d) + 1;
if (curs < i){
printf("s=%d c=%d i=%d\n", state, curs, i);
for (int j = curs; j < i; j++) {
if ((1 << j) & state > 0){
dist++;
}
}
min = MIN(min, dist + calc(state | (1<<i), i));
}
else {
printf("2s=%d c=%d i=%d\n", state, curs, i);
for (int j = i; j <= curs; j++) {
if ((1 << j) & state > 0){
dist++;
}
}
min = MIN(min, dist + calc(state | (1 << i), i));
}
}
return memo[state][curs] = min;
}
*/