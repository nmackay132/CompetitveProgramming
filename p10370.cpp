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



int main(){
	int T; scanf("%d", &T);
	while (T--){
		//printf("run %d\n", T);
		int N; scanf("%d", &N);
		double avg = 0;
		vi grades;
		for (int i = 0; i < N; i++)	{
			int g; scanf("%d", &g);
			grades.push_back(g);
			avg += g;
		}
		avg /= N;
		sort(grades.begin(), grades.end());
		int totalBigger = 0;
		for (int i = 0; i < N; i++) {
			if (grades[i] > avg) totalBigger++;
		}
		double ans = 100*(totalBigger / (double) N);
		printf("%.3f", ans);
		cout << "%" << "\n";
	}

	return 0;
}

/*
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91
*/