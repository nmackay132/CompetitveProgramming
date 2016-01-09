/*
*****Solved******
CodeForces #274 Div.2

Problem Type:
greedy
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



int main(){

	int N;
	while (scanf("%d", &N) == 1){
		vii arr;
		for (int i = 0; i < N; i++)	{
			int a, b;
			scanf("%d %d", &a, &b);
			arr.push_back(ii(a, b));
		}

		sort(arr.begin(), arr.end());

		int prv = MIN(arr[0].first, arr[0].second);
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i].second >= prv){
				prv = arr[i].second;
			}
			else{
				prv = arr[i].first;
			}
		}

		printf("%d\n", prv);
	}
	return 0;
}	
