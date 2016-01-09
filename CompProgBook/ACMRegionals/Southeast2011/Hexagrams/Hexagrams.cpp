
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

#define sc scanf
#define pf printf
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

int nums[12];
int star[12];
bool used[12];


int countnum, lvl, target;


void permute(){
	if (lvl >= 10){
		countnum++;
		return;
	}

	lvl++;
	int exact = -1;
	for (int i = 0; i < 12; i++) {
		if (!used[lvl]){
			if (star[i] != -1) continue;
			star[i] = nums[lvl];

			if (i == 3){
				target = star[0] + star[1] + star[2] + star[3];
			}

			if (i == 5){
				exact = target - star[0] - star[4] - star[5];
				if (exact < 0) break;
			}
			if (i == 6 && target != star[0] + star[4] + star[5] + star[6]) break;

			if (i == 7){
				exact = target - star[7] - star[1] - star[4];
				if (exact < 0) break;
			}
			if (i == 8 && target != star[7] + star[1] + star[4] + star[8])

			if (i == 9){
				//printf("i=%d\n", i);
				//printf("lvl=%d\n", lvl);
				exact = target - star[8] - star[5] - star[9];
				if (exact < 0) break;
			}
			if (i == 10){
				if (target != star[8] + star[5] + star[9] + star[10]) break;
				exact = target - star[10] - star[2] - star[7];
				if (exact < 0  || exact != target - star[6] - star[9] - star[3]) break;
			}


			if (i == 11){
				//printf("i=%d\n", i);
				//printf("lvl=%d\n", lvl);
				if (target != star[6] + star[9] + star[11] + star[3]) break;
				if (target != star[10] + star[11] + star[2] + star[7]) break;
			}

		}
		permute();
		star[i] = -1;
	}
	lvl--;

}

int main(){
	MEM(nums, 0);
	while (true){
		bool ok = false;
		for (int i = 0; i < 12; i++) {
			cin >> nums[i];
			if (nums[i] > 0) ok = true;
		}
		if (!ok) break;

		countnum = 0;

		MEM(star, -1); MEM(used, false);
		star[0] = nums[0]; used[0] = true;
		lvl = -1;
		permute();

		MEM(star, -1); 
		star[1] = nums[0];
		lvl = -1;
		permute();

		printf("%d\n", countnum);
	}
	return 0;
}	
