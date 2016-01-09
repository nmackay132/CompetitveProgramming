#include <stdio.h>
#include <string.h>

// Does not print permutations in lexicographical order
void swap(char *i, char *j) {
	char temp = *i;
	*i = *j;
	*j = temp;
}

void permute(char *a, int left, int right) {
	if (left == right) {
		printf("%s", a);
	}
	for (int i = left; i <= right; i++) {
		swap(a + left, a + i);
										//insert a valid() method to check if new permutaion meets constraints
		permute(a, left + 1, right);
		swap(a + left, a + i);
	}
}

//example
int main() {
	char str[] = "ABC";
	permute(str, 0, strlen(str)-1);

	return 0;
}