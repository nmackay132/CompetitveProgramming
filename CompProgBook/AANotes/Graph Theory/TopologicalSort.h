vector<vi> AdjList;
int visited[MAXV];
vi ts;

void toposort(int u) {
	visited[u] = true;
	for (int i = 0; i < (int)AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (!visited[v]) {
			toposort(v);
		}
	}
	ts.push_back(u);
}