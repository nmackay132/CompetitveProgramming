/*


Problem Type:

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

vector<string> lang;
map<string, int> dicc;

void makeLower(string &str) {
	for (int i = 0; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
}

int main(){
	int N;
	cin >> N;
	string line;
	getline(cin, line);
	string word;
	for (int i = 0; i < N; i++) {
		getline(cin, line);
		stringstream ss; ss.str(line);
		ss >> word;
		lang.push_back(word);
		//cout << word << endl;
		//printf("i=%d\n", i);
		while (ss >> word) {
			makeLower(word);
			dicc[word] = i;
			//printf("%d\n", i);
		}
	}
	getline(cin, line);

	while (getline(cin, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '.' || line[i] == ',' || line[i] == '!' || line[i] == ';' || line[i] == '?' || line[i] == '(' || line[i] == ')')
				line[i] = ' ';
		}
		stringstream ss;
		ss.str(line);
		string w;
		while (ss >> w) {
			makeLower(w);	
			if (dicc.count(w) > 0) {
				cout << lang[dicc[w]] << endl;
				break;
			}
		}
	}

	return 0;
}	
