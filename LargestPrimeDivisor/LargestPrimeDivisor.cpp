/*
*****Solved*****
UVa 11466

Problem Type:
number theory, prime factors
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
bitset<10000010> bs;
ll sieveSize;

void sieve(ll upperbound){
	sieveSize = upperbound + 1;		// add 1 to include upperbound
	bs.set();			// set all bits to 1
	bs[0] = bs[1] = 0;	// except index 0 and 1
	for (ll i = 2; i <= sieveSize; i++) {
		// cross out multiples of i starting from i * i
		if (bs[i]){
			for (ll j = i*i; j < sieveSize; j += i){
				bs[j] = 0;
			}
			primes.push_back((int)i);	// add this prime to the list of primes
		}
	}
}

ll largestPrimeFactor(ll N) {
	ll PF_idx = 0, PF = primes[PF_idx];
	ll largest = 1;
	int count = 0;
	while (PF * PF <= N){
		if (N%PF == 0) count++;
		while (N % PF == 0){
			N /= PF;
			if (PF > largest)
				largest = PF;
		}
		PF = primes[++PF_idx];
	}
	if (N > 1)
		count++;
	if (N > largest)
		largest = N;
	if (count > 1)
		return largest;
	else
		return -1;
}

int main(){
	sieve(10000000);
	ll N;
	while (scanf("%ld", &N), N){
		if (N < 0) N = -N;
		ll ans = largestPrimeFactor(N);
		printf("%ld\n", ans);
	}

	return 0;
}	
