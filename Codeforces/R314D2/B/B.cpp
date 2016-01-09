/*


Problem Type:

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
#define PI (acos(0)*2.0)
#define EPS (1.0e-9)
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

int N;
int visitors[1000010];

int main(){
	//scanf("%d", &N);
	cin >> N;
	MEM(visitors, 0);
	vector<pair<char, int> > visits;
	int startCount = 0;
	for (int i = 0; i < N; i++) {
		char dir; int v;
		cin >> dir >> v;
		if (dir == '-' && visitors[v] == 0) {
			startCount++;
		}
		else {
			if (visitors[v] == 0) {
				visitors[v] = 1;
			}
			else {
				visitors[v] = 0;
			}
		}
		visits.push_back(make_pair(dir, v));
	}
	//cout << startCount << endl;
	int count = startCount;
	int max = count;
	for (int i = 0; i < N; i++) {
		max = MAX(max, count);
		if (visits[i].first == '+') {
			count++;
		}
		else {
			count--;
		}
	}
	max = MAX(max, count);

	cout << max << endl;

	return 0;
}	
