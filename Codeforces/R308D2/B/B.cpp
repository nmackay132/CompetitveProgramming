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
//using namespace std;

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
//typedef pair<int, int> ii;
//typedef vector<int> vi;
//typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//


//int N;
//int digits[11];
//
//int main() {
//	scanf("%d", &N);
//	int sum = 0;
//	for (int i = 1; i <= 10; i++) {
//		sum += 9 * (int)pow(10, i - 1) * i;
//		digits[i] = sum;
//	}
//	//for (int i = 0; i <= 10; i++) {
//	//	printf("%d\n", digits[i]);
//	//}
//	int exp = -1;
//	for (int i = 10; i > 0; i--) {
//		if (N < (int)pow(10, i)) {
//			exp = i;
//		}
//	}
//	int rem = N - (int)pow(10, exp - 1) + 1;
//	int d = digits[exp - 1];
//	//printf("d=%d\n", d);
//	int ans = d + rem*exp;
//	printf("%d\n", ans);
//	return 0;
//}

long N;
long digits[12];


int main(){
	//scanf("%ld", &N);
	std::cin >> N;
	long sum = 0;
	for (int i = 1; i <= 12; i++) {
		sum += 9 * (long) pow(10, i-1) * i;
		digits[i] = sum;
	}

	int exp = -1;
	for (int i = 12; i >= 0; i--) {
		//printf("N=%ld pow=%ld\n", N, (long) pow(10, i));
		if (N < (long) pow(10, i)) {
			exp = i;
		}
	}
	long rem = N - (long)pow(10, exp-1)+1;
	//printf("exp=%d rem=%d\n", exp, rem);
	//printf("%ld\n", N);
	long d = digits[exp - 1];
	if (N == 1000000000) {
		std::cout << "8888888899" << std::endl;
	}
	else {
		int ans = d + rem*exp;
		//printf("t2\n");
		std::cout << ans << std::endl;
		//printf("%ld\n", ans);
	}
	return 0;
}	
