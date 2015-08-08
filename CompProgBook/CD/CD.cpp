/*
*****Solved*****
UVa 624

Problem Type:
complete search
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
	int N, T;
	while (scanf("%d %d", &N, &T) == 2){
		vi arr;
		for (int i = 0; i < T; i++) {
			int a;
			scanf("%d", &a);
			arr.push_back(a);
		}
		//printf("test1\n");

		/*for (int i = 0; i < arr.size(); i++)
		{
			printf("%d ", arr[i]);
		}*/
		//printf("\n");
		int sum;
		int diff = INF;
		int bestSum = 0;
		int bestseq;
		//printf("size %d\n", arr.size());
		for (int i = 0; i < (1 << arr.size()); i++) {
			sum = 0;
			for (int j = 0; j < arr.size(); j++) {
				if (i & (1 << j)){
					sum += arr[j];
				}
			}
			if (sum <= N && N - sum < diff){
				diff = N - sum;
				bestSum = sum;
				bestseq = i;
			}
		}

		for (int i = 0; i < arr.size(); i++) {
			if (1 << i & bestseq)
				printf("%d ", arr[i]);
		}
		printf("sum:%d\n", bestSum);
	}

	return 0;
}	
