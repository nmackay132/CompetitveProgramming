/*
*****Solved*****
UVa 11799

Problem type:
easy
*/

/*
#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	int caseNo = 0;
	while (caseNo++ < T) {
		int N;
		cin >> N;
		int max = 0;
		for (int i = 0; i < N; i++) {
			int s;
			cin >> s;
			max = s > max ? s : max;
		}
		printf("Case %d: %d\n", caseNo, max);
	}
	return 0;
}

/*
2
5 9 3 5 2 6
1 2
*/