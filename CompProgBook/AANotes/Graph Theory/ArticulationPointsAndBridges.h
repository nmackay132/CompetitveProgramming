#define UNVISITED -1

vector<vii> AdjList;
vi dfs_low, dfs_num;
int dfsNumberCounter;
vector<vi> articulation_bridge;
vi articulation_vertex
vi dfs_parent;
int rootChildren, dfsRoot;
int bridgeCounter;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;	// dfs_low <= dfs_num
	for (int i = 0; i < (int)AdjList[u].size(); i++) {
		ii v = AdjList[u][i];
		if (dfs_num[v.first] == UNVISITED) {		// a tree edge
			dfs_parent[v.first] = u;
			if (u == dfsRoot) rootChildren++;		// special case if u is root

			articulationPointAndBridge(v.first);

			if (dfs_low[v.first] >= dfs_num[u])			// for articulation point
				articulation_vertex.push_back(u);
			if (dfs_low[v.first] > dfs_num[u]) {			// for articulation bridge
				articulation_bridge[u].push_back(v.first);
			}
			dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
		}
		else if (v.first != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
	}
}

//in main()
dfs_low.assign(N, 0); dfs_num.assign(N, UNVISITED);
articulation_bridge.assign(N, vi());
dfs_parent.assign(N, 0);
dfsNumberCounter = 0;
for (int i = 0; i < N; i++) {
	if (dfs_num[i] == UNVISITED) {
		dfsRoot = i; rootChildren = 0;
		articulationBridge(i);
	}
}