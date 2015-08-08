/*
*****Solved*****
UVa 574

Problem Type:
generate all substrings
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
	int T, N;
	while (scanf("%d %d", &T, &N), N){
		int n;

		vi nums;
		for (int i = 0; i < N; i++) {
			scanf("%d", &n);
			nums.push_back(n);
		}

		//sort(nums.rbegin(), nums.rend());

		printf("Sums of %d:\n", T);
		bool hasAns = false;
		vector<string> sums;
		map<string, int> nMap;
		for (int i = 0; i < (1 << N); i++) {
			int sum = 0;
			vi arr;
			string str = "";
			for (int j = 0; j < N; j++) {
				if ((1<<j) & i){
					sum += nums[j];
					arr.push_back(nums[j]);
				}
			}
			if (sum == T){
				for (int i = 0; i < arr.size(); i++) {
					if (i)
						str += "+" + to_string(arr[i]);
					else
						str += to_string(arr[i]);
				}
				//cout << str << "\n";

				if (!nMap.count(str)){
					sums.push_back(str);
					//printf("\n");
					nMap[str] = 1;
				}
				hasAns = true;
			}
		}
		if (!hasAns) printf("NONE\n");
		else{
			sort(sums.rbegin(), sums.rend());
			for (int i = 0; i < sums.size(); i++) {
				cout << sums[i] << "\n";
			}
		}
	}
	return 0;
}	

/*
4 6 4 3 2 2 1 1
5 3 2 1 1
400 12 50 50 50 50 50 50 25 25 25 25 25 25
0 0
*/