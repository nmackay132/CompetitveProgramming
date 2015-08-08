/*
*****Solved*****
UVa 10018

Problem Type:
easy string manipulation
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

#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
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
int loops = 0;

long long revAdd(long long n){
	string s = to_string(n);
	string temp = "";
	for (int i = 0; i < s.size(); i++) {
		temp = s[i] + temp;
	}
	long long  m = stol(temp);
	return n + m;
}

bool isPalindrome(long long n){
	string s = to_string(n);
	int f = 0, l = s.length() - 1;
	while (f < l){
		if (s[f] != s[l]) return false;
		else {
			f++;
			l--;
		}
	}
	return true;
}

int main(){

	int N; scanf("%d", &N);
	while (N--){
		long long a;
		scanf("%lld", &a);
		loops = 0;

		while (!isPalindrome(a)){
			loops++;
			a = revAdd(a);
		}

		cout << loops << " " << a << "\n";

	}
	return 0;
}

/*
4
195
265
750
121
*/