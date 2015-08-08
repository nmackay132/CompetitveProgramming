/*
*****Solved*****
UVa 10140

Problem Type:
Number theory, prime numbers
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
	sieveSize = upperbound + 1;		// add 1 to includ upperbound
	bs.set();			// set all bits to 1
	bs[0] = bs[1] = 0;	// except index 0 and 1
	for (ll i = 2; i <= sieveSize; i++) {
		// cross out multiples of i starting from i * i
		if (bs[i]){
			for (ll j = i*i; j < sieveSize; j += i)
				bs[j] = 0;
			primes.push_back((int)i);	// add this prime to the list of primes
		}
	}
}
ll L, U;
bitset<1000010> D;

int main(){
	sieve(10000000);
	while (scanf("%ld %ld", &L, &U) == 2){
		ll diff = U - L;
		D.set();
		for (int i = 0; i < primes.size(); i++) {
			ll n = primes[i];
			ll x = L / n;
			if (L%n != 0) x++;
			x = x*n;
			if (L == 1)
				D[0] = 0;
			for (ll j = x; j <= U; j +=n) {
				//printf("j=%d L=%d\n", j,L);
				if (j < 10000010 && !bs[j])
					D[j - L] = 0;
				else if (j >= 10000010){
					//printf("check\n");
					D[j - L] = 0;
				}
			}
		}

		int min = INF, max = 0;
		int minI = -1, maxI = -1;
		int minI2 = -1, maxI2 = -1;
		int prv = -1;
		for (int i = 0; i <= diff; i++) {
			if (D[i]){
				//if (i+L==2 || i+L==3)
					//printf("i=%d\n", i);
				if (prv == -1) prv = i;
				else{
					int x = i - prv;
					if (x < min) {
						min = x;
						minI = i + L;
						minI2 = prv + L;
					}
					if (x > max) {
						max = x;
						maxI = i + L;
						maxI2 = prv + L;
					}
					prv = i;
				}
			}
		}

		if (minI == -1)
			printf("There are no adjacent primes.\n");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n", minI2, minI, maxI2, maxI);

	}
	return 0;
}	
