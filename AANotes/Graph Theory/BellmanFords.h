//Bellman Ford's algorithm
//O(V*E)

//faster
vector<vii> AdjList;

vi dist(N, INF); dist[0] = 0;
bool modified = true;
for (int i = 0; i < N && modified; i++) {
	modified = false;
	for (int u = 0; u < N; u++) {
		for (int j = 0; j < AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if (dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
				modified = true;
			}
		}
	}
}


// regular
vector<vii> AdjList;

vi dist(N, INF); dist[0] = 0;
for (int i = 0; i < N; i++) {
	for (int u = 0; u < N; u++) {
		for (int j = 0; j < AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			dist[v.first] = MIN(dist[v.first], dist[u] + v.second);
		}
	}
}

//check for Negative Cyles
//performed after Bellman Ford's Algorithm
bool negativeCycle = false;
for (int i = 0; i < N; i++) {
	for (int u = 0; u < N; u++) {
		for (int j = 0; j < AdjList[u].size(); j++) {
			ii v = AdjList[u][j];
			if (dist[v.first] > dist[u] + v.second)		// if this is still possible then negative cycle exists
				negativeCycle = true;
		}
	}
}