const int UNVISITED = 0;
const int EXPLORED = 1;
const int VISITED = 2;

vector<vi> AdjList;
int visited[MAXV];
bool isCycle;

void cycle(int u) {
	visited[u] = EXPLORED;
	for (int i = 0; i < (int)AdjList[u].size(); ++i) {
		int v = AdjList[u][i];
		if (visited[v] == UNVISITED)
			cycle(v);
		else if (visited[v] == EXPLORED) {
			isCycle = true;
		}
	}
	visited[u] = VISITED;
}