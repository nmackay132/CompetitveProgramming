/*
*****Solved*****
Uva 272

Problem Type:
easy
*/
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
#define REP(n)int decrement = n;while(decrement--)
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



int main(){
	string line;
	bool first = true;
	while (true){
		
		getline(cin, line);
		if (line == "") break;
		vector<char> str;
		//printf("test %s\n", line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '"' && first){
				str.push_back('`');
				str.push_back('`');
				first = false;
			}
			else if (line[i] == '"'){
				str.push_back('\'');
				str.push_back('\'');
				first = true;
			}
			else{
				str.push_back(line[i]);
			}
		}
		for (int i = 0; i < str.size(); i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}

/*
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
*/