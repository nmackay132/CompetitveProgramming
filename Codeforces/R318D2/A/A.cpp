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
vi candidates;

int main(){
	scanf("%d", &N);
	int v;
	int him;
	int max = 0;
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		scanf("%d", &v);
		if (i == 0) him = v;
		else {
			//candidates.push_back(v);
			//max = MAX(max, v);
			pq.push(v);
		}
	}

	int b = 0;
	while (true) {
		int a = pq.top(); pq.pop();
		if (him > a) {
			break;
		}
		//printf("a=%d him=%d\n", a, him);
		b++; a--; him++;
		pq.push(a);
	}

	printf("%d\n", b);

	//int numMax = 0;
	//vi cand;
	//for (int i = 0; i < candidates.size(); i++) {
	//	if (candidates[i] == max) {
	//		cand.push_back(max);
	//		numMax++;
	//	}
	//}



	//if (him > max) {
	//	printf("0\n");
	//	return 0;
	//}
	//else if (him == max) {
	//	printf("1\n");
	//	return 0;
	//}

	////int i = 0;
	////int bribe = 0;
	////while (true) {
	////	if (cand[i%numMax] >= him) {
	////		cand[i%numMax]--;
	////		//printf("c[%d]=%d him=%d\n", (i%numMax), cand[i%numMax], him);
	////		him++;
	////		i++;
	////		bribe++;
	////	}
	////	else {
	////		break;
	////	}
	////}
	//////printf("max=%d\n", max);

	//
	//printf("%d\n", bribe);


	return 0;
}	
