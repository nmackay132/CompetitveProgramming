/*
Actually problem D
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

#define sc scanf
//#define pf printf
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

int V, E;
map<string, int> dicc;

int main(){
	//int x = 8;
	//int &n = x;
	//cout << n << endl;
	////int *n = &x;
	//n = 9;
	//cout << x << endl;
	//cout << n << endl;
	//return 0;

	while (scanf("%d %d", &V, &E), V || E) {
		string city;
		for (int i = 0; i < V; i++) {
			cin >> city;
			dicc[city] = i;
		}

		vector <vii> AdjList;
		AdjList.assign(V, vii());
		vii pairs;

		for (int i = 0; i < E; i++) {
			string c1, c2;
			int w;
			cin >> c1 >> c2 >> w;
			AdjList[dicc[c1]].push_back(ii(dicc[c2], w));
			AdjList[dicc[c2]].push_back(ii(dicc[c1], w));
		}
		for (int i = 0; i < 4; i++) {
			string c1, c2;
			cin >> c1 >> c2;
			pairs.push_back(ii(dicc[c1], dicc[c2]));
		}

		int minCost = INF;
		int p[4] = { 0, 1, 2, 3 };
		vector<pair<ii*, ii> > edges;
		do {
			printf("t\n");

			vi dist(V, INF);
			priority_queue<ii> pq;
			int cost = 0;
			for (int i = 0; i < 4; i++) {
				vector< ii* > prv; ii* temp;
				prv.assign(V, temp);
				int dest = pairs[p[i]].second;
				int start = pairs[p[i]].first;
				pq.push(ii(0, start));
				dist[start] = 0;
				while (!pq.empty()) {
					ii front = pq.top(); pq.pop();
					int d = -front.first, u = front.second;
					if (d > dist[u]) continue;
					for (int j = 0; j < (int)AdjList[u].size(); j++) {
						ii v = AdjList[u][j];
						if (dist[u] + v.second < dist[v.first]) {
							//printf("v=%d\n", v);
							dist[v.first] = dist[u] + v.second;
							//printf("t2\n");
							prv[v.first] = &AdjList[u][j];
							pq.push(ii(-dist[v.first], v.second));
						}
					}
					printf("t2\n");

					u = dest;
					//set visited edges to 0
					while (u != start) {
						printf("prv[u]= (%d, %d)\n", prv[u]->first, prv[u]->second);
						cost += prv[u]->second;
						edges.push_back(make_pair(prv[u], *prv[u]));
						prv[u]->second = 0;
						u = prv[u]->first;
					}
					printf("t3\n");

				}
			}
			//reset edges back to orginial values
			for (int i = 0; i < edges.size(); i++) {
				*edges[i].first = edges[i].second;
			}
			minCost = min(minCost, cost);
		} while (next_permutation(p, p + 4));

		printf("%d\n", minCost);
	}

	return 0;
}	
