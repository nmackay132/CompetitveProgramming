/*
*****Wrong*****
Greedy
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

string A, B, C;
int ACharCount[26], BCharCount[26], CCharCount[26], SecStrCount[26];

int main(){
	cin >> A >> B >> C;
	MEM(ACharCount, 0);
	MEM(BCharCount, 0);
	MEM(CCharCount, 0);
	MEM(SecStrCount, 0);

	for (int i = 0; i < A.length(); i++) {
		int ch = A[i] - 'a';
		ACharCount[ch]++;
	}
	for (int i = 0; i < B.length(); i++) {
		int ch = B[i] - 'a';
		BCharCount[ch]++;
	}
	for (int i = 0; i < C.length(); i++) {
		int ch = C[i] - 'a';
		CCharCount[ch]++;
	}

	int minB = INF;
	for (int i = 0; i < B.length(); i++) {
		int ch = B[i] - 'a';
		int fact = ACharCount[ch] / BCharCount[ch];
		minB = MIN(minB, fact);
	}
	int minC = INF;
	for (int i = 0; i < C.length(); i++) {
		int ch = C[i] - 'a';
		int fact = ACharCount[ch] / CCharCount[ch];
		minC = MIN(minC, fact);
	}

	int max = MAX(minB, minC);
	string firstStr;
	string secStr;
	if (max == minB) {
		firstStr = B;
		secStr = C;
		for (int i = 0; i < 26; i++) {
			SecStrCount[i] = CCharCount[i];
		}
	}
	else {
		firstStr = C;
		secStr = B;
		for (int i = 0; i < 26; i++) {
			SecStrCount[i] = BCharCount[i];
		}
	}

	for (int i = 0; i < max; i++) {
		cout << firstStr;
	}
	for (int i = 0; i < firstStr.length(); i++) {
		int ch = firstStr[i] - 'a';
		ACharCount[ch] -= max;
	}

	int minSec = INF;
	for (int i = 0; i < secStr.length(); i++) {
		int ch = secStr[i] - 'a';
		int fact = ACharCount[ch] / SecStrCount[ch];
		minSec = MIN(minSec, fact);
	}
	for (int i = 0; i < minSec; i++) {
		cout << secStr;
	}
	for (int i = 0; i < secStr.length(); i++) {
		int ch = secStr[i] - 'a';
		ACharCount[ch] -= minSec;
	}

	for (int i = 0; i < 26; i++) {
		char ch = 'a' + i;
		while (ACharCount[i] > 0) {
			cout << ch;
			ACharCount[i]--;
		}
	}
	cout << endl;
	return 0;
}	
