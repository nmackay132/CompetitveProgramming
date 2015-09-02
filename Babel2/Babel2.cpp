/*
*****Solved*****
UVa 11492

Problem Type:
sssp, djikstras
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

typedef pair<int, string> istring;

vector<string> words;
string Start, Goal;
vector< vector< vector<pair< ii, int> > > > AdjList;

int main(){

	int M;
	while (scanf("%d", &M), M){
		cin >> Start >> Goal;

		int V = 0;
		map<string, int> dict;
		dict[Start] = V++;
		dict[Goal] = V++;

		AdjList.assign(2 * M + 10, vector< vector<pair< ii, int> > >());
		for (int i = 0; i < 2 * M + 10; i++) {
			AdjList[i].assign(28, vector< pair<ii, int> >());
		}
		
		for (int i = 0; i < M; i++){
			string l1, l2, word;
			cin >> l1 >> l2 >> word;

			if (!dict.count(l1)) dict[l1] = V++;
			if (!dict.count(l2)) dict[l2] = V++;

			for (int i = 0; i < 28; i++) {
				AdjList[dict[l1]][i].push_back(make_pair(ii(word.length(), dict[l2]), word[0] - 'a'));
				AdjList[dict[l2]][i].push_back(make_pair(ii(word.length(), dict[l1]), word[0] - 'a'));
			}
		}

		vector<vi> dist;  
		dist.assign(2 * M + 10, vi());
		for (int i = 0; i < dist.size(); i++) {
			dist[i].assign(28, INF);
		}

		dist[dict[Start]][26] = 0;
		priority_queue<pair<ii, int> > pq; pq.push(make_pair(ii(0, dict[Start]), 26));
		while (!pq.empty()){
			ii front = pq.top().first;		
			int pu = pq.top().second;  pq.pop();
			int d = -front.first; int u = front.second;
			if (d > dist[u][pu]) continue;
			for (int i = 0; i < (int)AdjList[u][pu].size(); i++) {
				ii v = AdjList[u][pu][i].first;
				int pv = AdjList[u][pu][i].second;
				if (dist[u][pu] + v.first < dist[v.second][pv] && pu != pv) {
					dist[v.second][pv] = dist[u][pu] + v.first;
					pq.push(make_pair(ii(-dist[v.second][pv], v.second), pv));
				}
			}
		}

		int best = INF;
		for (int i = 0; i < 26; i++) {
			best = MIN(best, dist[dict[Goal]][i]);
		}

		if (best >= INF)
			printf("impossivel\n");
		else
			printf("%d\n", best);
	}
	return 0;
}

*/