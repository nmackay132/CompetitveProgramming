//in main()
vi dist(V, INF);

void bfs(int s) {
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < (int) AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			if (dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}