/*
Codeforces 287 Div. 2
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

int H;
ll N;

int main(){

	scanf("%d %ld", &H, &N);
	ll nodes = 1;
	for (int i = 1; i <= H; i++) {
		nodes *= 2;
	}
	bool isLeft = true;
	int lvl = 1;
	ll n = 1;
	ll left = 0, right = nodes;
	ll total = 1;
	while (left < right){

		while (lvl < H){
			n *= 2;
			ll mid = (left + right) / 2;
			if (isLeft){
				right = mid + 1;
			}
			else{
				left = mid;
			}
			lvl++;
			if (N < left || N > right){
				total += nodes / lvl;
				break;
			}
			else{
				total++;
			}
		}
	}

	return 0;
}	
