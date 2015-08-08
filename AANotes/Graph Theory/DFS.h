
int visited[MAXV];
vector<vi> AdjList;

void dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!visited[v]) {
			dfs(v);
		}
	}
}