/*
*****Solved*****
Codeforces #305 Div. 2 A.

Problem Type:
string, palindrome
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



int main(){

	string line;
	cin >> line;
	int n; 
	cin >> n;
	if (line.length() % n != 0){
		//printf("len = %d\n", line.length());
		printf("NO\n");
		return 0;
	}
	int len = line.length() / n;
	vector<vector<char> > words;
	words.assign(n, vector<char>());
	for (int i = 0; i < n; i++) {
		for (int j = i*len; j < (i+1)*len; j++) {
			words[i].push_back(line[j]);
		}
	}
		
	bool okay = true;
	for (int i = 0; i < n; i++)
	{
		int beg = 0, end = len - 1;
		bool palindrome = true;
		while (beg < end){
			if (words[i][beg] != words[i][end]){
				palindrome = false;
				break;
			}
			beg++; end--;
		}
		if (!palindrome){
			okay = false;
		}
	}

	if (okay){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
}	
