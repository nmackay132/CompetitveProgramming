/*
UVa 10152

Problem Type:
sorting
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
	int T;
	scanf("%d", &T);
	while (T--){
		int N; scanf("%d", &N);
		string str; getline(cin, str);

		vector<string> original;
		for (int i = 0; i < N; i++) {
			getline(cin, str);
			original.push_back(str);
		}

		map<string, int> dicc;
		map<int, string> rdicc;
		int V = 0;
		for (int i = 0; i < N; i++) {
			getline(cin, str);
			dicc[str] = V;
			rdicc[V] = str;
			V++;
		}

		vi arr;
		for (int i = 0; i < N; i++) {
			string str = original[i];
			int n = dicc[str];
			arr.push_back(n);
		}

		vi added;
		for (int i = 0; i < arr.size(); i++) {
			int min = INF;
			int minI = -1;
			for (int j = i; j < arr.size(); j++) {
				if (arr[j] < min){
					min = arr[j];
					minI = j;
				}
			}
			if (minI != i){
				int temp = arr[minI];
				arr.erase(arr.begin() + minI);
				arr.insert(arr.begin(), temp);
				added.push_back(temp);
			}
		}

		for (int i = added.size()-1; i >= 0; i--) {
			string str = rdicc[added[i]];
			cout << str << "\n";
		}

		int ind = 0;
		int j = 0;
		vi nums;
		while (dicc[original[ind]] == j){
			nums.push_back(j);
			j++;
			ind++;
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			string str = rdicc[nums[i]];
			cout << str << "\n";
		}

		printf("\n");
	}

	return 0;
}	
