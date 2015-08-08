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

int N;
map<string, int> dicc;
vi money;
vector<string> names;

int main(){
	int count = 0;
	while (scanf("%d", &N) == 1) {
		if (count != 0) 
			printf("\n");
		count++;
		int V = 0;
		dicc.clear(); money.clear(); names.clear();
		string name;
		money.assign(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> name;
			names.push_back(name);
			if (dicc.count(name) == 0) {
				dicc[name] = V++;
			}
			//cout << name << endl;
		}
		
		for (int i = 0; i < N; i++) {
			int amt, M; string nameFrom, nameTo;
			cin >> nameFrom >> amt >> M;
			int quot = amt, rem = 0;
			if (M != 0) {
				quot = amt / M;
				rem = amt % M;
			}
			if (M != 0)
				money[dicc[nameFrom]] = money[dicc[nameFrom]] -amt + rem;
			
			for (int i = 0; i < M; i++) {
				cin >> nameTo;
				money[dicc[nameTo]] += quot;
			}
		}
		
		for (int i = 0; i < N; i++) {
			cout << names[i] << " " << money[i] << endl;
		}

		//printf("\n");

	}

	return 0;
}	
