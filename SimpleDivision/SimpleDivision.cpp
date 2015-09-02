/*
*****Solved*****
UVa 10407

Problem Type:
number theory, gcd
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

//int arr[1010];
//int darr[1000010];

int main(){
	int N;
	while (scanf("%d", &N), N){
		vi arr;
		arr.push_back(N);
		int a;
		//int index = 0;
		while (scanf("%d", &a), a){
			//arr[index] = a;
			//index++;
			arr.push_back(a);
		}
		//int max = index;
		vi darr;
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i; j < arr.size(); j++) {
				darr.push_back(abs(arr[i] - arr[j]));
			}
		}

		int maxFact = darr[0];
		for (int i = 1; i < darr.size(); i++) {
			maxFact = gcd(maxFact, darr[i]);
		}
		
		printf("%d\n", maxFact);
	}

	return 0;
}	
