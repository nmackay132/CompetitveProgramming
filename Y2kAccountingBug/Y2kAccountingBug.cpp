/*
*****Solved*****
UVa 10576

Problem Type:
Complete search
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

int S, D;
int months[12];


int main(){
	while (scanf("%d %d", &S, &D) == 2){

		int maxSum = -INF;
		for (int k = 0; k < (1<<12); k++) {

			for (int j = 0; j < 12; j++) {
				if (k & (1 << j)){
					months[j] = S;
				}
				else{
					months[j] = -D;
				}
			}

			bool ok = true;
			for (int i = 0; i < 8; i++) {
				if (months[i] + months[i + 1] + months[i + 2] + months[i + 3] + months[i + 4] >= 0) {
					ok = false; break;
				}
			}
			if (ok){
				int sum = 0;
				for (int i = 0; i < 12; i++) {
					sum += months[i];
				}
				maxSum = MAX(sum, maxSum);
			}
		}
		if (maxSum < 0)
			printf("Deficit\n");
		else
			printf("%d\n", maxSum);
	}
	return 0;
}	
