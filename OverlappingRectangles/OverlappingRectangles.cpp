/*
*****Solved*****
UVa 460

Problem Type:
geometry, rectangle overlap
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


int main(){
	int T; scanf("%d", &T);
	while (T--){
		int XLL1, YLL1, XUR1, YUR1;
		scanf("%d %d %d %d", &XLL1, &YLL1, &XUR1, &YUR1);

		int XLL2, YLL2, XUR2, YUR2;
		scanf("%d %d %d %d", &XLL2, &YLL2, &XUR2, &YUR2);
		
		int XLL = MAX(XLL1, XLL2);
		int YLL = MAX(YLL1, YLL2);
		int XUR = MIN(XUR1, XUR2);
		int YUR = MIN(YUR1, YUR2);

		if (XLL < XUR && YLL < YUR){
			printf("%d %d %d %d\n", XLL, YLL, XUR, YUR);
		}
		else{
			printf("No Overlap\n");
		}
		if (T) printf("\n");
	}

	return 0;
}	
