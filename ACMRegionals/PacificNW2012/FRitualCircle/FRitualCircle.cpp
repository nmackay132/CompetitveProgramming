/*

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

bool isDigit(char c) {
	return c >= '0' && c <= '9';
}

void clean(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isDigit(str[i])) {
			str[i] = ' ';
		}
	}
}

vii good, bad, all;
map<ii, int> dicc;

int main(){
	string line;
	while (getline(cin, line)) {
		clean(line);
		stringstream ss; ss.str(line);
		int x, y;
		while (ss >> x >> y) {
			ii p(x, y);
			good.push_back(p);
			all.push_back(p);
			dicc[p] = 0; //0=good
		}
		getline(cin, line);
		clean(line);
		ss.str(line);
		while (ss >> x >> y) {
			ii p(x, y);
			bad.push_back(p);
			all.push_back(p);
			dicc[p] = 1; //1=bad
		}



	}
	return 0;
}	
