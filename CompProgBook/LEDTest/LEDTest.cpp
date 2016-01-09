/*
*****Solved*****
UVa 416

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

int G[10][7] = {{ 1, 1, 1, 1, 1, 1, 0 },
				{ 0, 1, 1, 0, 0, 0, 0 },
				{ 1, 1, 0, 1, 1, 0, 1 },
				{ 1, 1, 1, 1, 0, 0, 1 },
				{ 0, 1, 1, 0, 0, 1, 1 },
				{ 1, 0, 1, 1, 0, 1, 1 },
				{ 1, 0, 1, 1, 1, 1, 1 },
				{ 1, 1, 1, 0, 0, 0, 0 },
				{ 1, 1, 1, 1, 1, 1, 1 },
				{ 1, 1, 1, 1, 0, 1, 1 }
				};
vector<vi> nums;
int N;
int On[7];

bool compare(int row, int ind){
	bool result = true;
	for (int i = 0; i < 7; i++) {
		//printf("row=%d\n", row);
		if (G[row][i] == 1 && nums[ind][i] == 0){
			//printf("i=%d\n",i);
			On[i] = 0;
		}
		else if (G[row][i] == 0 && nums[ind][i] == 1){
			result = false;
		}
		else if (G[row][i] == 1 && nums[ind][i] == 1 && On[i] == 0){
			//printf("k=%d\n",i);
			result = false;
		}
	}
	return result;
}

bool comp(int row){
	memset(&On, 1, sizeof(On));
	for (int i = 0; i < N; i++) {
		//printf("row=%d i=%d row-i=%d\n", row, i, row - i);
		if (!compare(row - i, i))
			return false;
	}
	return true;
}

int main(){
	while (scanf("%d", &N), N){
		string line;
		nums.clear();
		nums.assign(N, vi());
		//MEM(On, 1);
		memset(&On, 1, sizeof(On));
		for (int i = 0; i < N; i++){
			cin >> line;
			for (int j = 0; j < 7; j++) {
				if (line[j] == 'Y'){
					nums[i].push_back(1);
				}
				else{
					nums[i].push_back(0);
				}
			}
		}

		bool okay = false;
		for (int i = 9; i >= N-1; i--) {
			if (comp(i)){
				okay = true;
			}
		}

		if (okay)
			printf("MATCH\n");
		else
			printf("MISMATCH\n");

	}

	return 0;
}	
