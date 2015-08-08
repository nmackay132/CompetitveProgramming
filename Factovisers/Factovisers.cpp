/*
*****Solved*****
UVa 10139

Problem Type:
number theory, workin with prime factors
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
int F[10000010];

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

void primeFactors(ll N, vii &factors) {
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N){
		ii f(PF, 0);
		while (N % PF == 0){
			N /= PF;
			f.second++;
		}
		if (f.second > 0){
			factors.push_back(f);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(ii(N,1));
}

ll getpower(int n, int f){
	ll power = 0;
	for (ll p = f; p <= n; p *= f) {
		power += n / p;
	}
	return power;
}

int main(){

	ll F, D;
	sieve(10000011);
	while (scanf("%ld %ld", &F, &D) == 2){
		vii factors;
		primeFactors(D, factors);
		/*for (int i = 0; i < factors.size(); i++) {
			printf("f = %d %d\n", factors[i].first, factors[i].second);
		}*/

		bool divides = true;
		if (D > 0){
			for (int i = 0; i < factors.size() && divides; i++) {
				//int r = getpower(F, factors[i].first);
				//printf("r = %d\n", r);
				divides = (factors[i].second <= getpower(F, factors[i].first));
			}
		}

		if (divides && D>0){
			printf("%d divides %d!\n", D, F);
		}
		else{
			printf("%d does not divide %d!\n", D, F);
		}
	}
	return 0;
}	
