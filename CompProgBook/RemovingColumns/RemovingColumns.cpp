/*
Codeforces #283 Div. 2
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
string G[110];
int Count = 0;
bool Removed;
queue<ii> Ties;

void comp(int rSt, int rEnd, int col){
	int st = -1, end = -1;
	for (int r = rSt; r <= rEnd; r++) {
		if (G[r][col] < G[r - 1][col]){
			Count++;
			Removed = true;
			return;
		}
		if (G[r][col] > G[r - 1][col]){
			continue;
		}
		st = r - 1, end = r;
		for (int i = r+1; i <= rEnd; i++) {
			if (G[i][col] < G[i - 1][col])
				end++;
			else
				break;
		}
		Ties.push_back(ii(st, end));
		r = end + 1;
	}
}

int main(){

	cin >> N >> M;
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		G[i] = line;
	}


	Ties.push(ii(0, N - 1));
	int pLen = 0;
	int col = 0;
	int len = Ties.size();
	queue<ii> temp;
	while (!Ties.empty()){
		Removed = false;
		for (int i = 0; i < len; i++) {
			ii p = Ties.front(); Ties.pop();
			temp.push(p);
			comp(p.first, p.second, col);
		}
		col++;
		if (Removed){
			for (int i = 0; i < temp.size(); i++) {
				ii p = temp.front();  temp.pop();
				Ties.push(p);
			}
		}
	}

	printf("%d\n", Count);
	return 0;
}	
