//  MINIMUM SPANNING TREE


//KRUSKAL'S
class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 0); p.assign(N, 0);
		for (int i = 0; i < N; i++) p[i] = i;
	}

	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

// inside main()
vector < pair<int, ii> > EdgeList;
int totalCost = 0;
int u, v, w;
for (int i = 0; i < E; i++) {
	scanf("%d %d %d", &u, &v, &w);
	EdgeList.push_back(make_pair(w, ii(u, v)));
}

sort(EdgeList.begin(), EdgeList.end());

int mstCost = 0;
UnionFind UF(V);
for (int i = 0; i < E; i++) {
	pair<int, ii> front = EdgeList[i];
	if (!UF.isSameSet(front.second.first, front.second.second)) {
		mstCost += front.first;
		UF.unionSet(front.second.first, front.second.second);
	}
}

printf("MST cost = %d (Kruskal's)", mstCost);



// PRIM'S
vi taken;
priority_queue<ii> pq;

void process(int vtx) {
	taken[vtx] = 1;
	for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
	}
}

// inside int main()
taken.assign(V, 0);
process(0);
mst_cost = 0;
while (!pq.empty()) {
	ii front = pq.top(); pq.pop();
	u = -front.second; w = -front.first;
	if (!taken[u])
		mst_cost += w, process(u);
}
printf("MST cost = %d (Prim's)\n", mst_cost);