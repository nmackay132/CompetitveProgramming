/*
*****Solved*****
UVa 136

Problem Type:
dp, number theory
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
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

ll two, three, five;
int ugly[1501];

int main(){
	
	int p2, p3, p5;
	ugly[1] = p2 = p3 = p5 = 1;

	for (int i = 2; i <= 1500; i++) {
		//printf("test %d ugly[p2]=%d ugly[p3]=%d ugly[p5]=%d\n", i,ugly[p2],ugly[p3],ugly[p5]);
		int a = 2 * ugly[p2];
		int b = 3 * ugly[p3];
		int c = 5 * ugly[p5];
		if (a < b && a < c){
			ugly[i] = a;
			p2 = i;
		}
		else if (b < a && b < c){
			ugly[i] = b;
			p3++;
		}
		else if (c < a && c < b){
			ugly[i] = c;
			p5++;
		}
		else if (a == b){
			ugly[i] = b;
			p3++; i--;
		}
		else if (a == c){
			ugly[i] == c;
			p5++; i--;
		}
		else if (b == c){
			ugly[i] = c;
			p5++; i--;
		}

	}

	printf("The 1500'th ugly number is %d.\n", ugly[1500]);
	return 0;
}	
