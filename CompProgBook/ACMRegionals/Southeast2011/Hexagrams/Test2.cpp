
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

int perm[4];
bool used[4];
int c;

void permute(int lvl){
	
	if (lvl == 4){
		for (int i = 0; i < 4; ++i) {
			printf("%d ", perm[i]);
		}
		printf("\n");
		printf("\t%d\n", ++c);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used[i]) continue;
		perm[lvl] = i;
		if (i==1 && perm[0] + perm[1] == 1) continue;
		used[i] = true;
		permute(lvl + 1);
		used[i] = false;
	}
}

int main(){
	MEM(used, false);
	MEM(perm, -1);
	c = 0;
	permute(0);
	return 0;
}
