/*

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

int Mat[101][101];

vi primes;
bitset<10000010> bs;
ll sieveSize;
map<int, bool> isPrime;

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
			isPrime[(int)i] = true;
		}
	}
}

int main(){
	int N, D;
	sieve(100);
	memset(&Mat, 0, sizeof(Mat));
	for (int i = 2; i <= 100; i++) {
		for (int j = 2; j <= i; j++) {
			Mat[i][j] = Mat[i - 1][j];
		}
		if (isPrime[i])
			Mat[i][i]++;
		else{
			for (int k = 0; k < primes.size(); k++) {
				if (primes[k] > i) break;
				int x = primes[k];
				if (i % x != 0) continue;
				int y = i;
				while (y != 1 && y % x == 0){
					Mat[i][primes[k]]++;
					y /= x;
				}
			}
		}
	}
	//printf("prime[0] = %d\n", primes[0]);

	while (scanf("%d %d", &N, &D), N || D){
		vi factors;
		for (int i = 0; i < primes.size(); i++) {
			if (primes[i] > D) break;
			else{
				int x = primes[i];
				if (D % x != 0) continue;
				int y = D;
				while (y > 1 && y % x == 0){
					factors.push_back(x);
					y /= x;
					//printf("t %d\n", y);
				}
			}
		}

		int primeFactors[101];

		for (int i = 0; i < 101; i++) {
			primeFactors[i] = Mat[N][i];
		}

		//for (int i = 0; i < 101; i++) {
		//	printf("%d %d\n", i, Mat[N][i]);
		//}

		for (int i = 0; i < factors.size(); i++) {
			int fact = factors[i];
			primeFactors[fact]--;
		}

		int result = 1;
		for (int i = 0; i < 101; i++) {
			if (primeFactors[i] > 0){
				result *= (primeFactors[i] + 1);
			}
		}

		if (result == 1 && D != N) printf("0\n");
		else printf("%d\n", result);
	}

	return 0;
}	
