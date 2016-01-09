/*

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
	int N;
	scanf("%d", &N);
	while (N--){
		int P; scanf("%d", &P);
		int count;
		vii nums;
		string line; stringstream ss;
		getline(cin, line);
		for (int i = 1; i <= P; i++) {
			stringstream ss; string line;
			getline(cin, line);
			ss.str(line);
			int n;
			count = 0;
			while (ss >> n){
				//printf("t %d\n", n);
				count++;
			}
			nums.push_back(ii(count, i));
		}
		sort(nums.begin(), nums.end());

		//for (int i = 0; i < nums.size(); i++) {
		//	printf("test %d %d\n", nums[i].first, nums[i].second);
		//}
		//printf("\n");

		vi ans;
		ans.push_back(nums[0].second);
		int min = nums[0].first;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i].first != min) break;
			ans.push_back(nums[i].second);
		}

		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}

	return 0;
}	
