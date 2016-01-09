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

struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}
	bool operator < (point o) const {
		if (x != o.x){
			return x < o.x;
		}
		return y < o.y;
	}
};

struct line{
	double a, b, c;
	//line () : a(0), b(0), c(0){}
	bool operator < (line o) const{
		if (fabs(a - o.a) > EPS)
			return a < o.a;
		if (fabs(b - o.b) > EPS)
			return b < o.b;
		return c < o.c;
	}
};


void pointsToLine(point p1, point p2, line &l){
	if (p1.x == p2.x){
		l.a = 1.0; l.b = 0.0; l.c = -p1.x;
	}
	else{
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}
//
//bool areParallel(line l1, line l2){
//    return (fabs(l1.a-l2.a) < eps) && (fabs(l1.b-l2.b) < eps);
//}
//
//bool areSame(line l1, line l2){
//    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < eps);
//}

int main(){
	int T; scanf("%d", &T);
	string str; getline(cin, str);
	getline(cin, str);
	while (T--){
		int x, y;
		vector<point> points;
		while (getline(cin, str) && str != ""){
			stringstream ss; ss.str(str);
			ss >> x;
			ss >> y;
			//scanf("%d %d", &x, &y);
			points.push_back(point(x, y));
		}

		//        for (int i = 0; i < points.size(); ++i) {
		//            printf("point %d %d\n", points[i].x, points[i].y);
		//        }

		vector<line> lines;
		map<line, int> lineMap;
		int MAX = 0;
		for (int i = 0; i < points.size(); i++) {
			for (int j = i + 1; j < points.size(); j++) {
				line l;
				pointsToLine(points[i], points[j], l);
				if (lineMap.count(l) == 0) lineMap[l] = 1;
				else lineMap[l]++;
				MAX = max(lineMap[l], MAX);
				//lines.push_back(l);
			}
		}

		int total = MAX;

		int ans1 = (1 + sqrt(1 + 8 * total)) / 2;
		int ans2 = (1 - sqrt(1 + 8 * total)) / 2;
		int ans = 0;
		if (ans1 > 0) ans = ans1;
		else ans = ans2;

		printf("%d\n", ans);
		if (T) printf("\n");
	}
	return 0;
}


//        sort(lines.begin(), lines.end());
//
////        for (int i = 0; i < (int) lines.size(); i++) {
////            printf("line %lf %lf %lf\n", lines[i].a, lines[i].b, lines[i].c);
////        }
////        printf("\n\n");
//
//        int total = 0;
//        for (int i = 0; i  < (int) lines.size(); i++) {
//            int count = 1;
//            for (int j = i+1; j < (int) lines.size(); j++) {
//                if(areSame(lines[i], lines[j]))
//                    count++;
//            }
//            total = max(total, count);
//        }