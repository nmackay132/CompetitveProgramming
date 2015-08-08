/*
UVa 787

Problem Type:
Maximum 1D Range Sum
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

	string line; 
	while (getline(cin, line), line != ""){
		stringstream ss; ss.str(line);
		int n;
		vi nums;
		while (true){
			ss >> n;
			if (n == -999999) break;
			nums.push_back(n);
		}

		ll prod;
		ll maxProd = MIN_INT;
		for (int i = 0; i < nums.size(); i++) {
			prod = 1;
			for (int j = i; j < nums.size(); j++) {
				prod *= nums[j];
				maxProd = MAX(maxProd, prod);
			}
		}

		printf("%d\n", maxProd);
	}

	return 0;
}	
