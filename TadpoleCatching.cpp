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

struct point_i{ // use when points are integers
	int x, y;
	point_i(){ x = y = 0; }
	point_i(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (point_i other) const {	// override less than operator
		if (x < other.x)		// useful for sorting
			return x < other.x;				// first criteria, by x-coordinate
		return y < other.y;					// second criteria, by y-coordinate
	}
	bool operator == (point_i other) const{
		return (x == other.x && y == other.y);
	}
};

double dist(point_i p1, point_i p2){
	return hypot(p1.x - p2.x, p1.y - p2.y); // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
}

int main(){
	int T;
	scanf("%d", &T);
	REP(T){
		int N, D; scanf("%d %d", &N, &D);

	}

	return 0;
}