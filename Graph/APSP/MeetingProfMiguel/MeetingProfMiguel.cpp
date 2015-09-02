/*
*****Solved*****
UVa 10171

Problem Type:
All Pair Shortest Path (APSP)
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



int main(){
	int N;
	while (scanf("%d", &N), N){
		vector<vi> adjM;
		vector<vi> adjM2;
		adjM.assign(26, vi());
		for (int i = 0; i < 26; i++) {
			adjM[i].assign(26, INF);
		}
		adjM2.assign(26, vi());
		for (int i = 0; i < 26; i++) {
			adjM2[i].assign(26, INF);
		}
		//printf("test0\n");
		for (int i = 0; i < N; i++) {
			char a, b, c, d; int w; char trash;
			scanf("%c %c %c %c %c %d", &trash,  &a, &b, &c, &d, &w);
			int u = c - 'A'; int v = d - 'A';
			if (a == 'Y'){
				if (w < adjM[u][v])
					adjM[u][v] = w;
				if (b == 'B' && w < adjM[v][u]){
					adjM[v][u] = w;
				}
			}
			else{
				if (w < adjM2[u][v])
					adjM2[u][v] = w;
				if (b == 'B' && w < adjM2[v][u]){
					adjM2[v][u] = w;
				}
			}
		}
		for (int i = 0; i < 26; i++){
			adjM[i][i] = 0;
			adjM2[i][i] = 0;
		}

		//printf("test1\n");

		for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++)	{
				for (int j = 0; j < 26; j++)	{
					adjM[i][j] = min(adjM[i][j], adjM[i][k] + adjM[k][j]);
				}
			}
		}

		for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++)	{
				for (int j = 0; j < 26; j++)	{
					adjM2[i][j] = min(adjM2[i][j], adjM2[i][k] + adjM2[k][j]);
				}
			}
		}
		//printf("test3\n");

		char a, b, trash; scanf("%c %c %c", &trash, &a, &b);
		int y = a - 'A'; int o = b - 'A';
		int min = INF;
		int sum = 0;
		int minI;
		for (int i = 0; i < 26; i++) {
			sum = adjM[y][i] + adjM2[o][i];
			if (sum < min){
				min = sum;
				minI = i;
			}
		}

		if (min >= INF) printf("You will never meet.\n");
		else{
			vi ans;
			for (int i = 0; i < 26; i++) {
				if (adjM[y][i] + adjM2[o][i] == min)
					ans.push_back(i);
			}

			sort(ans.begin(), ans.end());

			printf("%d", min);
			for (int i = 0; i < ans.size(); i++) {
				char place = 'A' + ans[i];
				printf(" %c", place);
			}
			printf("\n");
		}
	}

	return 0;
}	
