/*
*****Solved*****
UVa 11599

Problem type:
easy
*/

/*
#include <cstdio>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	int N, B, H, W;
	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
		int min = 500005;
		for (int i = 0; i < H; i++){
			int price;
			scanf("%d", &price);
			for (int i = 0; i < W; i++){
				int a;
				cin >> a;
				if (a >= N && N*price < B && N*price < min){
					min = N*price;
				}
			}
		}
		if (min < 500005){
			printf("%d\n", min);
		}
		else
			printf("stay home\n");
	}

	return 0;
}

/*
3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13
*/