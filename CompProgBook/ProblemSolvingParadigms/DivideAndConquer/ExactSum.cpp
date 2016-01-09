/*
*****Solved*****
UVa 11057

Problem Type:
binary search
*/
/*
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
using namespace std;

const int  MAX_INT = std::numeric_limits<int>::max();
const int  MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int  NEG_INF = -1000000000;

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI acos(0)*2.0
#define eps 1.0e-9
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

vector<int> price;
int M;
int diff;
int p1, p2;

void bs(int i){
	int lo = i, hi = price.size(), mid = 0;
	while (hi > lo) {
		mid = (lo + hi) / 2;
		//printf("m = %d + %d\n", price[i], price[mid]);
		if (price[i] + price[mid] == M){
			if (diff > abs(price[i] - price[mid])){
				diff = abs(price[i] - price[mid]);
				p1 = price[i]; p2 = price[mid];
			}
			break;
		}
		if (price[i] + price[mid] > M) 
			hi = mid;
		else 
			lo = mid+1;
	}
}

int main(){
	int N;
	while (scanf("%d", &N) != EOF){
		int num;
		price.clear();
		while (N--){
			scanf("%d", &num);
			price.push_back(num);
		}
		sort(price.begin(), price.end());
		scanf("%d", &M);

		diff = INF; p1 = 0; p2 = 0;
		for (int j = 0; j < price.size(); j++) {
			bs(j);
		}

		printf("Peter should buy books whose prices are %d and %d.\n\n", p1, p2);
	}
	return 0;
}

/*
2
40 40
80

5
10 2 6 8 4
10
*/