/*
*****Solved*****
UVa 10801

Problem Type:
djikstra, shortest path
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

int N, K;
vector<vii> AdjList;
vi elTimes;

void printDist(vi dist){
	printf("\ndist: ");
	for (int i = 0; i < dist.size(); i++)
	{
		printf("%d ", dist[i]);
	}
	printf("\n\n");
}

void printAdjList(){
	printf("\nAdjList:\n");
	for (int i = 0; i < AdjList.size(); i++)
	{
		for (int j = 0; j < AdjList[i].size(); j++)
		{
			printf("%d ", AdjList[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	while (scanf("%d %d", &N, &K) == 2){
		elTimes.clear();
		REP(N){
			int t;
			scanf("%d ", &t);
			elTimes.push_back(t);
		}

		AdjList.assign(N*100, vii());
		string line;  //getline(cin, line);
		vi floors;
		for (int i = 0; i < N; i++) {
			getline(cin, line);
			stringstream ss; ss.str(line);
			int a;
			//printf("line ");
			floors.clear();
			while (ss >> a){
				floors.push_back(a);
				//printf("%d ", a);
			}
			//printf("\n");
			for (int j = 0; j < floors.size(); j++) {
				int u = floors[j] + i * 100;
				for (int k = j+1; k < floors.size(); k++)	{
					int v = floors[k] + i * 100;
					AdjList[u].push_back(ii(v, abs(v-u)*elTimes[i]));
					AdjList[v].push_back(ii(u, abs(v-u)*elTimes[i]));
				}
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < N; j++) {
				for (int m = j+1; m < N; m++) {
					if (AdjList[i + j * 100].size() > 0 && AdjList[i + m * 100].size() > 0) {
						if (i == 0){
							AdjList[i + j * 100].push_back(ii(i + m * 100, 0));
							AdjList[i + m * 100].push_back(ii(i + j * 100, 0));
						}
						else{
							AdjList[i + j * 100].push_back(ii(i + m * 100, 60));
							AdjList[i + m * 100].push_back(ii(i + j * 100, 60));
						}
					}
				}
				
			}
		}

		//printAdjList();
		int s = 0;
		for (int i = 0; i < N; i++) {
			if (AdjList[s].size() > 0) break;
			s += 100;
		}
		
		//printf("s = %d AdjList.size() = \n", s);
		if (s > (N - 1) * 100){
			printf("IMPOSSIBLE\n");
			continue;
		}

		vi dist(N * 100, INF); dist[s] = 0;
		priority_queue<ii> pq; pq.push(ii(0, s));
		while (!pq.empty()){
			ii front = pq.top(); pq.pop();
			int d = front.first, u = front.second;
			if (d>dist[u]) continue;
			for (int i = 0; i < (int)AdjList[u].size(); i++){
				ii v = AdjList[u][i];
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}

		//printDist(dist);
		int min = INF;
		for (int i = 0; i < N; i++) {
			if (dist[K + 100*i] < min) min = dist[K + 100*i];
		}
		if (min >= INF) printf("IMPOSSIBLE\n");
		else printf("%d\n", min);

	}

	return 0;
}

/*
2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10

3 1
100 10 100
0 1
0 1
0 1

4 89
7 2 4 8
3 34 45 56 77
4 23 34 89
1 99
3 99	
*/