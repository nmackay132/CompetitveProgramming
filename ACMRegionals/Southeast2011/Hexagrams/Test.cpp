
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

class Permutations{
public:
	int n;
	int level;
	vi permu;
	int count;

	Permutations(int _n){
		n = _n;
		level = -1;
		permu.assign(n, -1);
		count = 0;
		go();
	}

	void go(){
		if (level >= n - 1){
			for (int i = 0; i < n; ++i) {
				printf("%d ", permu[i]);
			}
			printf("\n");
			count++;
			printf("\t%d\n", count);
			return;
		}
		level++;
		for (int j = 0; j < n; j++){
			if (permu[j] == -1){
				permu[j] = level;
				if (!(j == 1 && level == 0)){
					
				//if (j == 1 && permu[0] + permu[1] > 4){
					//permu[1] = -1;
					go();
					//break;
				}
				permu[j] = -1;
			}
		}
		level--;
	}
};

int main(){
	Permutations(4);
}
