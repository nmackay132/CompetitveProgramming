/*
*****Solved*****
UVa 10927

Problem Type:
geometry, sorting points
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

typedef pair<int, ii> iii;

void toRatio(ii &s){
	int d = gcd(s.first, s.second);
	d = abs(d);

	if (s.first == 0)
		s.second = s.second / abs(s.second);
	else if (s.second == 0)
		s.first /= abs(s.first);
	else{
		s.first /= d;
		s.second /= d;
	}
}

double dist(ii a, ii b){
	return hypot(a.first - b.first, a.second - b.second);
}

bool distcmp(iii a, iii b){
	return dist(a.second, ii(0, 0)) < dist(b.second, ii(0, 0));
}

int main(){
	int N; 
	int C = 1;
	while (scanf("%d", &N), N){
		int x, y, z; 
		map<ii, vector<iii> > m;
		int V = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &x, &y, &z);
			ii slope(x,y);
			
			toRatio(slope);

			if (m.count(slope) == 0) m[slope] = vector<iii>();

			m[slope].push_back(iii(z, ii(x, y)));
		}

		vector<ii> unseen;
		for (map < ii, vector<iii> >::iterator it = m.begin(); it != m.end(); ++it){

			sort(it->second.begin(), it->second.end(), distcmp);

			int maxH = -1;
			for (int i = 0; i < it->second.size(); i++) {
				int h = it->second[i].first;
				if (h <= maxH){
					unseen.push_back(it->second[i].second);
				}
				maxH = MAX(maxH, h);
			}
		}
		
		printf("Data set %d:\n", C++);
		if (unseen.size() == 0){
			printf("All the lights are visible.\n");
			continue;
		}
		sort(unseen.begin(), unseen.end());
		printf("Some lights are not visible:\n");
		for (int i = 0; i < unseen.size(); i++) {
			printf("x = %d, y = %d", unseen[i].first, unseen[i].second);
			if (i != unseen.size() - 1)
				printf(";\n");
		}
		printf(".\n");
		
	}

	return 0;
}	
