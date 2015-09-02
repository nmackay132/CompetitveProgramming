/*
*****Solved*****
UVa 10394

Problem Type:
math, primes
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

vi primes;
bitset<20000010> bs;
ll sieveSize;
map<int, bool> isPrime;
int tPrimes[1000010];

void sieve(ll upperbound){
	sieveSize = upperbound + 1;		// add 1 to includ upperbound
	bs.set();			// set all bits to 1
	bs[0] = bs[1] = 0;	// except index 0 and 1
	int k = 1;
	for (ll i = 2; i <= sieveSize; i++) {
		// cross out multiples of i starting from i * i
		if (bs[i]){
			for (ll j = i*i; j < sieveSize; j += i)
				bs[j] = 0;
			//primes.push_back((int)i);	// add this prime to the list of primes
			if (bs[i - 2])
				tPrimes[k++] = i - 2;
		}
	}
}


int main(){
	sieve(20000001);

	int n;
	while (scanf("%d", &n) == 1){
		printf("(%d, %d)\n", tPrimes[n], tPrimes[n] + 2);
	}

	return 0;
}	
