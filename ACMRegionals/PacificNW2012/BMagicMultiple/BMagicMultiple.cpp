/*
*****Solved*****
Problem Type:
greedy
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

bool digits[10];

bool markDigits(long n){
	while (n > 0){
		digits[n % 10] = true;
		n /= 10;
	}
}

int main(){
	long n;
	while (scanf("%ld", &n) != EOF){
		long k = 1;
		MEM(digits, false);
		while (true){
			markDigits(n*k);
			bool ok = true;
			for (int i = 0; i < 10; i++) {
				ok &= digits[i];
			}
			if (ok){
				printf("%ld\n", k);
				break;
			}
			k++;
		}
	}
	return 0;
}	
