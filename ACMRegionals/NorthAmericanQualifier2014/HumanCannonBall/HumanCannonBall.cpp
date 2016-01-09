/*
*****Solved*****

Problem Type:
djikstras, sssp
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

#define mp make_pair
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
typedef pair<double, double> dd;
typedef pair<double, int> di;
typedef vector<di> vid;


vector<dd> points;
vector<vid> g;
vector<double> dist;

double distForm(dd p1, dd p2) {
	return hypot(p1.first - p2.first, p1.second - p2.second);
}

double calcDist(dd p1, dd p2) {
	double d = distForm(p1, p2);
	double d1 = d / 5.0;
	double d2 = (fabs(d - 50) /5.0) + 2;
	return MIN(d1, d2);
}

int main(){

	dd start, end;
	int sI = 0, eI = 1;
	cin >> start.first >> start.second >> end.first >> end.second;
	points.push_back(start);
	points.push_back(end);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		dd p; cin >> p.first >> p.second;
		points.push_back(p);
	}
	g.assign(points.size(), vid());
	dist.assign(points.size(), INF);

	for (int i = 0; i < points.size(); i++) {
		for (int j = 0; j < points.size(); j++) {
			double d = distForm(points[i], points[j]);
			double d1 = d / 5.0;
			double d2 = INF;
			if (i>1)
				d2 = (fabs(d - 50) / 5.0) + 2;
			g[i].push_back(di(MIN(d1, d2), j));
			d2 = INF;
			if (j>1)
				d2 = (fabs(d - 50) / 5.0) + 2;
			g[j].push_back(di(MIN(d1,d2), i));
		}
	}
	
	priority_queue<di> pq; pq.push(di(0, sI));
	dist[sI] = 0;
	while (!pq.empty()) {
		di front = pq.top(); pq.pop();
		double d = -front.first; int u = front.second;
		if (d > dist[u]) continue;
		for (int i = 0; i < g[u].size(); i++) {
			double w = g[u][i].first;
			int v = g[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push(di(-dist[v], v));
			}
		}
	}

	printf("%lf\n", dist[eI]);
	return 0;
}	
