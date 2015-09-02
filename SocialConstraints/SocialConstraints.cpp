/*
UVa 11742

Problem Type:
Complete Search, try all permutations
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
	int n, m;
	while (scanf("%d %d", &n, &m), n || m){

		if (m == 0){
			int prod = 1;
			for (int i = 1; i <= n; i++) {
				prod *= i;
			}
			printf("%d\n", prod);
			continue;
		}
		for (int j = 0; j < m; j++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);

			int pa, pb, p[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
			int count = 0;
			do{
				//printf("arr: %d %d %d\n", p[0], p[1], p[2]);
				//printf("abc=%d %d %d\n", a, b, c);
				for (int i = 0; i < n; i++) {
					if (p[i] == a) pa = i;
					if (p[i] == b) pb = i;
				}
				if (c > 0){
					if (abs(pa - pb) <= c) count++;
				}
				else if (c < 0){
					if (abs(pa - pb) >= abs(c)) {
						count++;
						//printf("pa pb %d %d\n", pa, pb);
					}
				}


			} while (next_permutation(p, p+n));
			printf("%d\n", count);
		}
	}

	return 0;
}	
