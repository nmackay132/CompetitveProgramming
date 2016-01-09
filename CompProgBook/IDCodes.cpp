/*
*****Solved*****
UVa 146

Problem type:
easy
*/

/*
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
	char code[51];
	while (1){
		scanf("%s", code);
		if (strcmp(code, "#") == 0) break;
		
		if (next_permutation(code, code + strlen(code)))
			printf("%s\n", code);
		else
			printf("No Successor\n");
	}
	return 0;
}

/*
abaacb
cbbaa
#
*/