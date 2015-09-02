/*
*****Solved*****
UVa 821

Problem Type:
graph, floyd warshall
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

vector<vi> AdjMat;
vi vertices;

int main(){

	int a, b;
	int c = 1;
	while (scanf("%d %d", &a, &b), (a || b)) {

		AdjMat.assign(101, vi());
		vertices.assign(101, -1);
		for (int i = 0; i < 101; i++) {
			AdjMat[i].assign(101, INF);
		}

		AdjMat[a][b] = 1;
		int min = INF;
		int max = 0;
		vertices[a] = 1; vertices[b] = 1;
		while (scanf("%d %d", &a, &b), (a || b)){
			AdjMat[a][b] = 1;
			max = MAX(max, MAX(a, b));
			min = MIN(min, MIN(a, b));
			vertices[a] = 1; vertices[b] = 1;
		}

		for (int k = min; k <= max; k++) {
			for (int i = min; i <= max; i++) {
				for (int j = min; j <= max; j++) {
					AdjMat[i][j] = MIN(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
				}
			}
		}

		int count = 0; 
		for (int i = 0; i < vertices.size(); i++) {
			if (vertices[i] == 1) 
				count++;
		}
		
		double sum = 0;
		for (int i = min; i <= max; i++) {
			for (int j = min; j <= max; j++) {
				if (i == j) continue;
				if (AdjMat[i][j] < INF){
					sum += AdjMat[i][j];
				}
			}
		}

		//printf("sum = %.3f count = %d\n", sum, count);
		printf("Case %d: average length between pages = %.3f clicks\n", c++, sum / (count * (count-1)) );
		

	}
	return 0;
}

/*
1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0
*/