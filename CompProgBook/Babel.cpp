/*
UVa 11492

Problem Type:
djikstras, SSSP
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

struct word{
	string lang1, lang2;
	string w;
	bool isGoal;
};

string Start, Goal;
vector<vii> AdjList;

int main(){
	int M; 
	while (scanf("%d", &M), M){
		cin >> Start >> Goal;
		vector<word> words;
		vii starts, goals;
		for (int i = 0; i < M; i++){
			string l1, l2, str;
			cin >> l1 >> l2 >> str;
			word w;
			w.lang1 = l1;
			w.lang2 = l2;
			w.w = str;
			if (l1 == Start)
				starts.push_back(ii(str.length(), i));
			else if (l1 == Goal)
				goals.push_back(ii(str.length(), i));
			else if (l2 == Start)
				starts.push_back(ii(str.length(), i));
			else if (l2 == Goal)
				goals.push_back(ii(str.length(), i));
			
			words.push_back(w);
		}

		AdjList.assign(M, vii());
		for (int i = 0; i < M; i++) {
			for (int j = i+1; j < M; j++) {
				if (words[i].lang1 == words[j].lang1 || words[i].lang1 == words[j].lang2 ||
					words[i].lang2 == words[j].lang1 || words[i].lang2 == words[j].lang2){
					if (words[i].w[0] != words[j].w[0]){
						//printf("Test %d %d %d %d\n", i, j, words[i].w.length(), words[j].w.length());
						AdjList[i].push_back(ii(words[j].w.length(), j));
						AdjList[j].push_back(ii(words[i].w.length(), i));
					}
				}
			}
		}

		int min = INF;
		for (int j = 0; j < starts.size(); j++) {
			vi dist; dist.assign(M, INF); dist[starts[j].second] = starts[j].first;
			priority_queue<ii> pq; pq.push(ii(-starts[j].first, starts[j].second));
			while (!pq.empty()){
				ii front = pq.top(); pq.pop();
				int d = -front.first, u = front.second;
				if (d > dist[u]) continue;
				for (int i = 0; i < (int)AdjList[u].size(); i++) {
					ii v = AdjList[u][i];
					if (dist[u] + v.first < dist[v.second]) {
						dist[v.second] = dist[u] + v.first;
						pq.push(ii(-dist[v.second], v.second));
					}
				}
			}
			//for (int i = 0; i < dist.size(); i++) {
				//printf("dist[%d]=%d\n", i, dist[i]);
			//}

			for (int i = 0; i < goals.size(); i++) {
				min = MIN(min, dist[goals[i].second]);
			}
		}

		if (min >= INF){
			printf("impossivel\n");
		}
		else{
			printf("%d\n", min);
		}
	}
	return 0;
}

/*
4
portugues frances
ingles espanhol red
espanhol portugues amigo
frances ingles date
espanhol ingles actual
4
portugues alemao
ingles espanhol red
espanhol portugues amigo
frances ingles date
espanhol ingles actual
6
portugues frances
ingles espanhol red
espanhol portugues amigo
frances ingles date
frances espanhol la
portugues ingles a
espanhol ingles actual
0
*/

