/*


Problem Type:
union/disjoint sets
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


vi p, rk;

int findSet(int i) {
	if (i == p[i]) return i;
	return p[i] = findSet(p[i]);
}

bool isSameSet(int i, int j) {
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
	if (!isSameSet(i, j)) {
		int x = findSet(i), y = findSet(j);
		if (rk[x] > rk[y])
			p[y] = x;
		else {
			if (rk[x] == rk[y]) {
				rk[y]++;
			}
			p[x] = y;
		}
	}
}

struct circle{
	double x, y;
	int r, v;
	circle(double _x, double _y, int _r, int _v) {
		x = _x; y = _y; r = _r; v = _v;
	}
};

double dist(double x1, double y1, double x2, double y2) {
	return hypot(x2 - x1, y2 - y1);
}

int main(){
	int N;
	cin >> N;
	p.assign(N + 4, 0);
	rk.assign(N + 4, 0);
	for (int i = 0; i < N+4; i++) {
		p[i] = i;
	}
	int lt = 0, rt = 1;
	int V = 2;
	vector<circle> circles;

	while (N--) {
		double x, y; int r;
		cin >> x >> y >> r;
		circle cir(x, y, r, V);
		if (x - r <= 0) {
			unionSet(lt, V);
		}
		if (x + r >= 200) {
			unionSet(rt, V);
		}
		for (int i = 0; i < circles.size(); i++) {
			double x2 = circles[i].x;
			double y2 = circles[i].y;
			int r2 = circles[i].r;
			double d = dist(x, y, x2, y2);
			if (r + r2 > d) {
				unionSet(V, circles[i].v);
			}
		}
		circles.push_back(cir);
		//printf("p[lt] = %d\n", p[lt]);
		//printf("p[rt] = %d\n", p[rt]);
		//printf("p[%d] = %d\n\n", V, p[V]);

		if (isSameSet(lt, rt)) {
			printf("%d", V - 2);
			break;
		}
		V++;
	}
	

	return 0;
}	
