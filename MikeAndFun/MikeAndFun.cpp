/*
*****Solved*****
Codeforces #305 Div. 2 B.

Problem Type:
greedy, adhoc
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

int grid[510][510];
int n, m, q;
int Max = -1;
int Maxi;
int mg[510][510];


void updateMax(){
	for (int i = 1; i <= n; i++) {
		if (grid[i][0] > Max){
			Max = grid[i][0];
			Maxi = i;
		}
	}
}

void updateRow(int r){
	int prv = 0;
	int pt = 0;
	int maxt = -1;
	for (int j = 1; j <= m; j++) {
		if (grid[r][j] == 1){
			if (prv == 0){
				pt = 1;
				prv = 1;
			}
			else{ // prv == 1
				pt++;
				prv = 1;
			}
		}
		else{  //a == 0
			pt = 0;
			prv = 0;
		}
		if (pt > maxt){
			maxt = pt;
		}
	}
	grid[r][0] = maxt;
	//printf("maxt = %d\n", maxt);
	if (maxt > Max){
		Max = maxt;
		Maxi = r;
	}
	if (Maxi == r){
		Max = maxt;
	}
}


int main(){
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		int prv = 0;
		int pt = 0;
		int maxt = 0;
		for (int j = 1; j <= m; j++) {
			int a; scanf("%d", &a);
			grid[i][j] = a;
			if (a == 1){
				if (prv == 0){
					pt = 1;
					prv = 1;
				}
				else{ // prv == 1
					pt++;
					prv = 1;
				}
			}
			else{  //a == 0
				pt = 0;
				prv = 0;
			}
			if (pt > maxt){
				maxt = pt;
			}
		}
		grid[i][0] = maxt;
		if (maxt > Max){
			Max = maxt;
			Maxi = i;
		}
	}

	for (int i = 0; i < q; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		if (grid[r][c] >= 1){
			grid[r][c] = 0;
			updateRow(r);
		}
		else{
			grid[r][c] = 1;
			updateRow(r);
		}

		if (Maxi == r){
			updateMax();
		}

		printf("%d\n", Max);
	}


	return 0;
}



//int grid[510][510];
//int n, m, q;
//int Max = -1;
//int Maxi;
//int mg[510][510]; 
//
//
//void update0(int r, int c){
//	for (int i = c+1; i <= m; i++) {
//		if (mg[r][i] > 0){
//			mg[r][i] = mg[r][i - 1] + 1;
//		}
//		else{
//			break;
//		}
//	}
//}
//
//void update1(int r, int c){
//	if (c > 1){
//		mg[r][c] = mg[r][c - 1] + 1;
//	}
//	else{
//		mg[r][c] = 1;
//	}
//	for (int i = c + 1; i <= m; i++) {
//		if (mg[r][i] > 0){
//			mg[r][i] = mg[r][i-1]+1;
//		}
//		else{
//			break;
//		}
//	}
//}
//
//
//int main(){
//	scanf("%d %d %d", &n, &m, &q);
//	for (int i = 1; i <= n; i++) {
//		int prv = 0;
//		int pt = 0;
//		int maxt = 0;
//		for (int j = 1; j <= m; j++) {
//			int a; scanf("%d", &a);
//			if (a == 1){
//				if (prv == 0){
//					pt = 1;
//					prv = 1;
//				}
//				else{ // prv == 1
//					pt++;
//					prv = 1;
//				}
//			}
//			else{  //a == 0
//				pt = 0;
//				prv = 0;
//			}
//			mg[i][j] = pt;
//			if (pt > maxt){
//				maxt = pt;
//			}
//		}
//		grid[i][0] = maxt;
//		if (maxt > Max){
//			Max = maxt;
//		}
//	}
//
//	for (int i = 0; i < q; i++) {
//		int r, c;
//		scanf("%d %d", &r, &c);
//		if (mg[r][c] >= 1){
//			mg[r][c] = 0;
//			if (Maxi == r){
//				update0(r,c);
//			}
//		}
//		else{
//			grid[r][c] = 1;
//			grid[r][0]++;
//			if (grid[r][0] > Max){
//				Max = grid[r][0];
//				Maxi = r;
//			}
//		}
//	}
//
//	return 0;
//}	
