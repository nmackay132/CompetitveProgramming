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

int N;
int guesses[26];
map<char, int> dicc;
map<char, int> wdicc;

int main(){
	while (scanf("%d", &N), N != -1) {
		string str;
		cin >> str;
		MEM(guesses, 0);
		int V = 0;
		dicc.clear(); wdicc.clear();
		for (int i = 0; i < str.length(); i++) {
			int pos = str[i] - 'a';
			guesses[pos] = 1;
			if (dicc.count(str[i]) == 0) {
				dicc[str[i]] = V++;
			}
		}

		printf("Round %d\n", N);

		string word;
		cin >> word;
		int count = 7;
		bool done = false;
		for (int i = 0; i < word.length(); i++) {
			int c = word[i] - 'a';
			if (guesses[c] == 1) {
				if (dicc.count(word[i]) > 0) {
					V--;
					dicc.erase(word[i]);
				}
			}
			else {
				if (wdicc.count(word[i]) == 0) {
					wdicc[word[i]] = 1;
					count--;
				}
			}
			if (V == 0) {
				printf("You win.\n");
				done = true;
				break;
			}
			if (count == 0) {
				printf("You lose.\n");
				done = true;
				break;
			}
		}

		if (!done) {
			printf("You chickened out.\n");
		}
	}

	return 0;
}	
