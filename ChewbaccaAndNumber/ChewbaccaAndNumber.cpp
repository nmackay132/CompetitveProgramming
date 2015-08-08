/*
Codeforces #291 Div. 2 A
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
string N;

int comp(int pos){
	if (pos == N.length())
		return 0;
	int min = INF;
	int a = N[pos] - '0';
	min = MIN(a+comp(pos+1), (9-a) + comp(pos+1));
	return min;
}

int main(){
	cin >> N;
	int nums[20];
	for (int i = 0; i < N.length(); i++) {
		int a = N[i] - '0';
		if (a == 9 && i == 0)
			nums[i] = 9;
		else if (a >= 5){
			nums[i] = 9 - (N[i]-'0');
		}
		else{
			nums[i] = N[i] - '0';
		}
	}

	for (int i = 0; i < N.length(); i++) {
		cout << nums[i];
	}
	cout << "\n";

	return 0;
}	