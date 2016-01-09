

int perm[4];
bool used[4];
int c;

void permute(int lvl){

	if (lvl == 4){
		for (int i = 0; i < 4; ++i) {
			printf("%d ", perm[i]);
		}
		printf("\n");
		printf("\t%d\n", ++c);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used[i]) continue;
		perm[lvl] = i;
		if (i == 1 && perm[0] + perm[1] == 1) continue; //example of pruning (where first two are 0 and 1)
		used[i] = true;
		permute(lvl + 1);
		used[i] = false;
	}
}

int main(){
	MEM(used, false);
	MEM(perm, -1);
	c = 0;
	permute(0);
	return 0;
}
