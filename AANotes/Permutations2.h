class Permutations{
	int n;
	int level;
	vi permu;

	Permutations(int _n){
		n = _n;
		level = -1;
		permu.assign(n, -1);
		go();
	}

	void go(){

		if (level >= n - 1){
			for (int i = 0; i < n; ++i) {
				printf("%d ", permu[i]);
			}
			printf("\n");
			return;
		}
		level++;
		for (int j = 0; j < n; j++){
			if (permu[j] == -1){
				permu[j] = level;
				go();
				permu[j] = -1;
			}
		}
		level--;
	}
};