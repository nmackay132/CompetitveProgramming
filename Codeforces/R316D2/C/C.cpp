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

int N, M;

int main(){
	cin >> N >> M;
	string line;
	cin >> line;
	int val = 0;
	for (int i = 0; i < line.size()-1; i++) {
		if (line[i] == '.' && line[i + 1] == '.') {
			val++;
		}
	}

	int j = 0; char c;
	for (int i = 0; i < M; i++) {
		cin >> j >> c;
		j--;
		if (c == '.') {
			if (line[j] == '.') {
				//nothing
			}
			else {
				if (j > 0 && line[j - 1] == '.') val++;
				if (j < N - 1 && line[j + 1] == '.') val++;
				line[j] = '.';
			}
		}
		else { // c == 'a'
			if (line[j] != '.') {
				//nothing
			}
			else {
				if (j > 0 && line[j - 1] == '.') val--;
				if (j < N - 1 && line[j + 1] == '.') val--;
				line[j] = c;
			}
		}
		printf("%d\n", val);
	}



	return 0;
}	
