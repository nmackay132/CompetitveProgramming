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


struct point{ // use when points are doubles
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {	// override less than operator
		if (fabs(x - other.x) > EPS)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

struct circle{
	point c;
	double r;
	circle(point _c, double _r) : c(_c), r(_r) {}
};

// rotate p by theta degress CCW with respect to origin
point rotate(point p, double theta) {
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

// calc distance between two points
double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

vector<circle> circles;
vector<vi> g;
vi num;
int const EXPLORED = 1, UNVISITED = 0, VISITED = 2;
vi path;
vector<vi> cycles;
map<vi, int> dicc;
int C;

void cycleCheck(int u, int par) {
	num[u] = EXPLORED;
	path.push_back(u);
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (num[v] == UNVISITED) {
			cycleCheck(v, u);
			path.pop_back();
		}
		else if (num[v] == EXPLORED && v != par) {
			vi cycle;
			int i = path.size() - 1;
			while (true) {
				int n = path[i--];
				cycle.push_back(n);
				if (n == v) break;
			}
			vi temp = cycle;
			sort(temp.begin(), temp.end());
			if (dicc.count(temp) == 0) {
				dicc[temp] = C++;
				cycles.push_back(cycle);
			}
			path.pop_back();
		}
	}
	num[u] = VISITED;
}


int main(){
	int N;
	while (true) {
		path.clear();
		g.clear();
		circles.clear();
		num.clear();
		dicc.clear();
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			double x, y, r;
			cin >> x >> y >> r;
			circles.push_back(circle(point(x, y), r));
		}

		g.assign(N, vi());
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				circle c1 = circles[i], c2 = circles[j];
				if (dist(c1.c, c2.c) < c1.r + c2.r) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}

		C = 0;
		num.assign(N, 0);
		for (int i = 0; i < N; i++) {
			cycleCheck(i, -1);
			path.clear();
			num.assign(N, 0);
		}

		for (int i = 0; i < cycles.size(); i++) {
			printf("cycle %d: ", i);
			for (int j = 0; j < cycles[i].size(); j++) {
				printf("%d ", cycles[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}	
