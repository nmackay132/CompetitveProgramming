/*
C. Exams
Codeforces #274 Div. 2

Problem Type:
Binary Search
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
vi ruler;

int binSearch(int n){
	int lo = 0, mid = 0, hi = ruler.size();
	while (hi > lo){
		mid = (lo + hi) / 2;
		int x = ruler[mid];
		if (x == n) break;
		else{
			if (n < x){
				hi = mid;
			}
			else{
				lo = mid;
			}
		}
	}
	return mid;
}

int main(){
	int N, L, X, Y;
	while (scanf("%d %d %d %D") == 4){
		ruler.clear();
		for (int i = 0; i < N; i++) {
			int a; scanf("%d", &a);
			ruler.push_back(a);
		}

		bool foundX = false;
		for (int i = 0; i < N; i++) {
			int a = ruler[i];
			if (a + X > L) break;
			int res = binSearch(a + X);
			if (ruler[res] == a + X) {
				foundX = true;
			}
		}

		vi tRuler;
		if (!foundX){
			//vi tempRuler = ruler;
			bool foundY;
			for (int i = 0; i < N; i++) {
				int a = ruler[i];
				if (a + X > L) break;
				ruler.push_back(a + X);
				tRuler.push_back(a + X);
			}
			sort(ruler.begin(), ruler.end());
			int ansB2 = binSearch(Y);
			//if (ruler[ansB2] == Y)

			for (int i = 0; i < ruler.size(); i++) {
				int a = ruler[i];
				if (a + Y > L) break;
				int res = binSearch(a + Y);
				if (ruler[res] == a + Y) {
					foundY = true;
					printf("1\n%d", );
					break;
				}
			}
		}

		else{ //!foundX
			for (int i = 0; i < N; i++) {
				int a = ruler[i];
				if (a + Y > L) break;
				int res = binSearch(a + Y);
				if (ruler[res] == a + Y) {
					found = true;
				}
			}
		}
	}

	return 0;
}	
