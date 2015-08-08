/*
*****Solved*****
UVa 516

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

int maxV = 1000010;
int FCount[1000011];

vi primes;
bitset<1000010> bs;
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

vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N){
		while (N % PF == 0){
			N /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}


int main(){
	sieve(maxV);
	//bool start = true;
	while (true){
		string line; getline(cin, line);
		stringstream ss; ss.str(line);
		int n, e;
		int x=1;
		while (ss >> n){
			if (n == 0) return 0;
			ss >> e;
			x *= pow(n, e);
		}
		/*if (!start){
			printf("\n");
		}*/
		x--;
		//printf("x=%d\n", x);

		vi factors = primeFactors(x);
		/*for (int i = 0; i < factors.size(); i++) {
			printf("%d ", factors[i]);
		}
		printf("\n");*/

		memset(&FCount, 0, sizeof(FCount));
		int maxFact = 0;
		for (int i = 0; i < factors.size(); i++) {
			FCount[factors[i]]++;
			if (factors[i] > maxFact){
				maxFact = factors[i];
			}
		}

		bool first = true;
		for (int i = maxFact+1; i >= 0; i--) {
			if (FCount[i] > 0){
				if (first){
					printf("%d %d", i, FCount[i]);
					first = false;
				}
				else{
					printf(" %d %d", i, FCount[i]);
				}
			}
		}
		printf("\n");
	}

	return 0;
}	


