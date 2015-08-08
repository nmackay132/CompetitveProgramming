/*

*/
/*
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
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

typedef struct {
	ii pair;
	string name;
} point;

vector<point> points;

double calcArea(ii p1, ii p2, ii p3){
	return abs(0.5*( (p3.second - p1.second)*(p2.first - p1.first)-(p2.second-p1.second)*(p3.first-p1.first) ) );
}

int main(){

	int V;
	while (scanf("%d", &V), V){
		int u, v;
		string name;
		for (int i = 0; i < V; i++) {
			scanf("%s %d %d", &name, &u, &v);
			point p;
			p.pair = ii(u, v);
			p.name = name;
			points.push_back(p);
		}

		for (int i = 0; i < V; i++) {
			for (int j = i+1; j < V; j++) {
				for (int k = j+1; k < V; k++) {
					ii p1 = points[i].pair;
					ii p2 = points[j].pair;
					ii p3 = points[k].pair;
					double area = calcArea(p1, p2, p3);
					for (int m = 0; m < V; m++) {
						if (m != i && m != j && m != k){
							ii p4 = points[m].pair;
							double a1 = calcArea(p1, p2, p4);
							double a2 = calcArea(p1, p3, p4);
							double a3 = calcArea(p2, p3, p4);

						}
					}
				}
			}
		}

	}


	return 0;
}
*/