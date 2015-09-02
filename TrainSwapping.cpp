/*
*****Solved******
UVa 299

Problem Type:
bubble sort
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

vi arr;
int N;

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		arr.clear();
		for (int i = 0; i < N; i++) {
			int num; scanf("%d", &num); 
			arr.push_back(num);
		}

		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N-1-i; j++) {
				if (arr[j] > arr[j + 1]){
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					count++;
				}
			}
		}

		printf("Optimal train swapping takes %d swaps.\n", count);
	}

	return 0;
}


/*
5
3
1 3 2
4
4 3 2 1
2
2 1
3
5 6 7
5
1 5 2 3 4
*/