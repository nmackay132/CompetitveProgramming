/*
*****Solved*****
UVa 10338

Problem Type:
number theory, factorials
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

int letters[26];

ll fact(ll n){
	ll p = 1;
	for (int i = 1; i <= n; i++) {
		p *= i;
	}
	return p;
}

int main(){
	int T;
	scanf("%d", &T);
	string line; getline(cin, line);
	int C = 1;
	while (T--){
		cin >> line;
		memset(&letters, 0, sizeof(letters));
		int len = line.length();
		for (int i = 0; i < len; i++) {
			int a = line[i] - 'A';
			//printf("%d\n", a);
			letters[a]++;
		}

		ll f = fact(len);
		for (int i = 0; i < 26; i++) {
			if (letters[i] > 1){
				f /= fact(letters[i]);
			}
		}

		printf("Data set %d: %ld\n", C++, f);
	}

	return 0;
}	
