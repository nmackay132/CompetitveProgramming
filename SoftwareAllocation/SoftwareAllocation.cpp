/*
*****Semi-solved******
UVa 259

Problem Type:
Max-flow
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
#define FOR(i,s,n)for(i=s;i<n;i++)
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

int res[40][40];
vi p;
int S = 0, T = 37;
int f;
//char line[50];

void augment(int v, int minEdge){
	if (v == S){
		f = minEdge; return;
	}
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int mf(){
	int mf = 0;
	while (true){
		f = 0;
		vi dist; dist.assign(40, INF); dist[S] = 0;
		queue<int> q; q.push(S);
		p.assign(38, -1);
		//printf("q");
		while (!q.empty()){
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int v = 0; v < 40; v++) {
				if (res[u][v] > 0 && dist[v] == INF){
					//printf("dist[%d]=%d\n",v,dist[v]);
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
					//printf("u=%d v=%d dist[%d]=%d\n", u, v, v,dist[v]);
				}
			}
		}
		augment(T, INF);
		if (f == 0) break;
		//printf("f=%d\n", f);
		mf += f;
	}
	return mf;
}

void resetGraph(){
	memset(&res, 0, sizeof(res));
	p.clear();
	for (int i = 27; i <= 36; i++) {
		res[i][T] = 1;
	}
}

void done(int sum){
	int maxflow = mf();
	if (maxflow != sum){
		printf("!\n");
	}
	else{
		vector<char> comp;
		for (int i = 27; i <= 36; i++) {
			bool added = false;
			for (int j = 1; j <= 26; j++) {
				if (res[i][j] == 1){
					int c = j-1;
					comp.push_back(c + 'A');
					added = true;
				}
			}
			if (!added){
				comp.push_back('_');
			}
		}
		for (int i = 0; i < comp.size(); i++) {
			printf("%c", comp[i]);
		}
		printf("\n");
	}

}

int main(){
	string line;
	resetGraph();
	int sum = 0;
	int num = 1;
	while (getline(cin, line)){
		if (line == ""){
			done(sum);
			resetGraph();
			sum = 0;
		}
		else {
			int u = line[0] - 'A' + 1;
			int c = line[1] - '0';
			sum += c;
			//printf("u=%d\n", u);
			res[S][u] = c;
			int ind = 3;
			while (line[ind] != ';'){
				int v = line[ind] - '0';
				res[u][v + 27] = INF;
				//printf("u=%d v=%d\n", u, v);
				ind++;
			}
		}
	}
	printf("test\n");
	done(sum);
	return 0;
}	



// 259 - Software Allocation
// Maxflow

////----------------------------------------------------------------------//
//const int SOURCE = 0;
//const int TARGET = 37;
//const int MAX_V = 40;
//int res[MAX_V][MAX_V], s, f;
//vi p;
//
//void augment(int u, int minEdge){
//	if (u == SOURCE){
//		f = minEdge;
//	}
//	else if (p[u] != -1){
//		augment(p[u], min(minEdge, res[p[u]][u]));
//		res[p[u]][u] -= f;
//		res[u][p[u]] += f;
//	}
//}
//
//
//int maxflow(){
//	int mf = 0;
//	while (1){
//		f = 0;
//		queue<int> q;
//		vi dist;
//		dist.assign(40, INF);
//		p.assign(40, -1);
//		q.push(0);
//		dist[0] = 0;
//
//		while (!q.empty()){
//			int u = q.front();
//			q.pop();
//
//			if (u == TARGET)break;
//			for (int v = 0; v < MAX_V; v++){
//				if (res[u][v] > 0 && dist[v] == INF){
//					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
//				}
//			}
//		}
//		augment(TARGET, INF);
//		if (f == 0)break;
//		mf += f;
//	}
//
//	return mf;
//}
//
//void reset(){
//
//	p.clear();
//	MEM(res, 0);
//
//	res[27][TARGET] = 1;
//	res[28][TARGET] = 1;
//	res[29][TARGET] = 1;
//	res[30][TARGET] = 1;
//	res[31][TARGET] = 1;
//	res[32][TARGET] = 1;
//	res[33][TARGET] = 1;
//	res[34][TARGET] = 1;
//	res[35][TARGET] = 1;
//	res[36][TARGET] = 1;
//}
//
//void done(int sum){
//	int mf = maxflow();
//	if (mf == sum){
//		int i, j;
//		FOR(i, 27, 37){
//			bool empty = true;
//			FOR(j, 1, 27){
//				//						printf("(%d,%d) = %d, (%d,%d) = %d\n",i,j,res[i][j],j,i,res[j][i]);
//				if (res[i][j] == 1){
//					printf("%c", (char)(j - 1 + 'A')); empty = false; break;
//				}
//			}
//			if (empty)
//				printf("_");
//		}
//	}
//	else{
//		printf("!");
//	}
//
//	printf("\n");
//	reset();
//}
//
//int main(){
//
//	string line;
//	reset();
//	int sum = 0;
//	while (getline(cin, line)){
//		if (line == ""){
//			done(sum);
//			sum = 0;
//		}
//		else{
//			int app_node = line[0] - 'A' + 1;
//			int users = line[1] - '0';
//
//			// Source to app
//			res[SOURCE][app_node] = users;
//
//			// App to Computer
//			for (int i = 3; i < (int)line.size() - 1; i++){
//				int  computer_node = line[i] - '0' + 27;
//				res[app_node][computer_node] = INF;
//			}
//			sum += users;
//		}
//	}
//
//	done(sum);
//
//	return 0;
//}