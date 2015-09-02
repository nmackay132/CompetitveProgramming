int mf, f, s, t;
vi p;
int res[40][40];

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge; return;
	}
	else if (p[v] != -1) {
		augment(p[v], MIN(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

mf = 0;
while (true) {
	f = 0;
	vi dist(MAXV, INF); dist[s] = 0;
	queue<int> q; q.push(s);
	p.assign(MAXV, -1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int v = 0; v < MAXV; v++) {
			if (res[u][v] > 0 && dist[v] == INF) {
				dist[v] = dist[u] + 1;
				q.push(v); p[v] = u;
			}
		}
	}
	augment(t, INF);
	if (f == 0) break;
	mf += f;
}