/*
*****Solved*****
UVa 11292

Problem Type:
greedy, with sorting
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
	int N, M;
	while (scanf("%d %d", &N, &M), N || M){
		vi dragons, knights;
		for (int i = 0; i < N; i++) {
			int d; scanf("%d", &d);
			dragons.push_back(d);
		}
		for (int i = 0; i < M; i++) {
			int k; scanf("%d", &k);
			knights.push_back(k);
		}

		sort(dragons.begin(), dragons.end());
		sort(knights.begin(), knights.end());

		int total = 0;
		int di=0, ki=0;
		bool allSlayed = false;
		while (true){
			if (di >= dragons.size()){
				allSlayed = true;
				break;
			}
			if (ki > knights.size()){
				break;
			}
			if (knights[ki] >= dragons[di]){
				//printf("k=%d d=%d\n", knights[ki], dragons[di]);
				total += knights[ki];
				di++;
			}
			ki++;
		}

		if (allSlayed){
			printf("%d\n", total);
		}
		else{
			printf("Loowater is doomed!\n");
		}
	}

	return 0;
}	
