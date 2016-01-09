/*
*****Solved*****
UVa 628

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

int N;
vector<string> words;
vector<string> rules;

void btrack(string r, string pw, int p) {

	if (p == r.size()) {
		cout << pw << endl;
		return;
	}

	if (r[p] == '#') {
		for (int i = 0; i < words.size(); i++) {
			btrack(r, pw + words[i],p + 1);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			char temp = '0' + i;
			btrack(r, pw + temp, p + 1);
		}
	}
}

int main(){

	while (scanf("%d", &N)== 1) {
		string w;
		rules.clear(); words.clear();
		for (int i = 0; i < N; i++) {
			cin >> w;
			words.push_back(w);
		}

		int R; cin >> R;

		for (int i = 0; i < R; i++) {
			cin >> w;
			rules.push_back(w);
		}

		cout << "--" << endl;
		for (int i = 0; i < rules.size(); i++) {
			btrack(rules[i],"", 0);
		}

	}

	return 0;
}	
