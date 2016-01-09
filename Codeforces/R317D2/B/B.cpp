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

int N, S;
ll Buy[100010];
ll Sell[100010];
ll Order[100010];


int main(){
	//scanf("%d %d", &N, &S);
	cin >> N >> S;
	ll p, q;
	char d;
	
	//MEM(Buy, 0);
	//MEM(Sell, 0);
	MEM(Order, 0);
	ll maxS = 0, maxB = 0;
	ll minB = INF;
	for (int i = 0; i < N; i++) {
		cin >> d >> p >> q;
		if (d == 'B') {
			//Buy[p] += q;
			Order[p] += q;
			maxB = MAX(maxB, p);
			minB = MIN(minB, p);
		}
		else {
			//Sell[p] += q;
			Order[p] += q;
			maxS = MAX(maxS, p);
		}
	}
	int count = 0;
	vector<pair<int, ll> > Sell2;
	for (int i = maxB+1; i <= maxS && count < S; i++) {
		if (Order[i] > 0) {
			//printf("S %d %ld\n", i, Order[i]);
			Sell2.push_back(make_pair(i, Order[i]));
			//cout << "S " << i << " " << Order[i] << endl;
			count++;
		}
	}
	for (int i = Sell2.size()-1; i >= 0; i--) {
		cout << "S " << Sell2[i].first << " " << Sell2[i].second << endl;
	}
	count = 0;
	for (int i = maxB; i >= minB && count < S; i--) {
		if (Order[i] > 0) {
			//printf("B %d %ld\n", i, Order[i]);
			cout << "B " << i << " " << Order[i] << endl;
			count++;
		}
	}

	return 0;
}	
