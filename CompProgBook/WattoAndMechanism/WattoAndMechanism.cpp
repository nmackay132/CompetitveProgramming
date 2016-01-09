/*
Codeforces #291 Div 2 C
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

int N, M;

int main(){

	cin >> N >> M;
	map<string, int> dicc;
	int V = 0;
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		if (!dicc.count(line)){
			dicc[line] = V++;
		}
	}

	for (int j = 0; j < M; j++) {
		cin >> line;
		bool ok = false;
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == 'a'){
				//cout << "line1=" << line << endl;
				line[i] = 'b';
				//cout << "line2=" << line << endl;
				if (dicc.count(line) > 0){
					printf("YES\n");
					ok = true;
					break;
				}
				line[i] = 'c';
				if (dicc.count(line) > 0){
					printf("YES\n");
					ok = true;
					break;
				}
				line[i] = 'a';
			}
			else if (line[i] == 'b'){
				//cout << "line1=" << line << endl;
				line[i] = 'a';
				//cout << "line2=" << line << endl;
				if (dicc.count(line) > 0){
					printf("YES\n");
					ok = true;
					break;
				}
				line[i] = 'c';
				if (dicc.count(line) > 0){
					printf("YES\n");
					ok = true;
					break;
				}
				line[i] = 'b';
			}
			else if (line[i] == 'c'){
				line[i] = 'a';
				if (dicc.count(line) > 0){
					printf("YES\n");
					ok = true;
					break;
				}
				line[i] = 'b';
				if (dicc.count(line) > 0){
					printf("YES\n");
					ok = true;
					break;
				}
				line[i] = 'c';
			}
		}
		if (!ok){
			printf("NO\n");
		}
	}
	return 0;
}	
