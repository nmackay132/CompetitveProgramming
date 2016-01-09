
//O(V^3)

// Floyd Warshall's
for (int k = 0; k < N; k++) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AdjMat[i][j] = MIN(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
		}
	}
}