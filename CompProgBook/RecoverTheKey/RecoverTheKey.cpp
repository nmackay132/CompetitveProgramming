/*
IEEE Competition
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

struct node {
	int nxt, prv;
	int index;
	string str;
	bool operator < (node other) {	// override less than operator
		if (str < other.str)
			return str < other.str;
		else {
			return nxt == -1;
		}
	}
};


int main(){

	int T; scanf("%d", &T);
	while (T--){
		string line; getline(cin, line); getline(cin, line);
		stringstream ss; ss.str(line);
		string str;
		int index = 0;
		vector<node> ulist; vector<node> slist;
		while (ss >> str){
			node n; n.str = str.substr(0, str.length() - 1);
			node m; m.str = str.substr(1, str.length());
			n.index = index;
			m.index = index + 1;
			m.prv = index; m.nxt = -1; index++;
			n.nxt = index; n.prv = -1; index++;
			ulist.push_back(n); ulist.push_back(m);
			slist.push_back(n); slist.push_back(m);
		}

		sort(slist.begin(), slist.end());

		node first, last;

		for (int i = 0; i < slist.size() - 1; i++) {
			if (slist[i].str == slist[i + 1].str){
				ulist[slist[i].index].nxt = slist[i + 1].index;
				i++;
			}
			else{
				if (slist[i].nxt == -1) last = slist[i];
				else first = slist[i];
			}
		}

		cout << first.str;
		int i = first.nxt;
		while (true){
			cout << ulist[i].str.at(str.length() - 1);
			i = ulist[i].nxt;
		}
		cout << last.str.at(str.length() - 1) << "\n";
	}
	return 0;
}

/*
1
1234 3456 2345
*/