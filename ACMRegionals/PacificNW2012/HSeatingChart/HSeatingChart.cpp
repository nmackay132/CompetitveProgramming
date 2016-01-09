/*
*****Solved******

Problem Type:
merge sort, count swaps
*/
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <limits>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;

const int  MAX_INT = std::numeric_limits<int>::max();
const int  MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int  NEG_INF = -1000000000;

#define sc scanf
#define pf printf
#define MAX(a,b)(a>b?a:b)
#define MIN(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define REP(n)int decrement = n;while(decrement--)
#define PI acos(0)*2.0
#define EPS 1.0e-9
#define are_equal(a,b)fabs(a-b)<EPS
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b){ return a*(b / gcd(a, b)); }



//----------------------------------------------------------------------//

int arr[100010];
int temp[100010];
int N;
ll numSwaps;

void merge(int left, int middle, int right) {
	for (int i = left; i <= right; i++) {
		temp[i] = arr[i];
	}
	int l = left, r = middle + 1;
	int p = left;
	while (l <= middle && r <= right) {
		if (temp[l] < temp[r]) {
			arr[p++] = temp[l++];
		}
		else if(temp[r] < temp[l]) {
			numSwaps += middle - l + 1;
			arr[p++] = temp[r++];
		}
	}
	while (l <= middle) {
		arr[p++] = temp[l++];
	}
	while (r <= right) {
		arr[p++] = temp[r++];
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int middle = (right + left) / 2;
		mergeSort(left, middle);
		mergeSort(middle + 1, right);
		merge(left, middle, right);
	}
}

int main(){

	while (true) {
		cin >> N;
		if (N == 0) break;
		numSwaps = 0;
		map<string, int> dicc;
		string str;
		for (int i = 1; i <= N; i++) {
			cin >> str;
			dicc[str] = i;
		}
		for (int i = 1; i <= N; i++) {
			cin >> str;
			arr[i] = dicc[str];
		}

		//printf("Input:\n");
		//for (int i = 1; i <= N; i++) {
		//	printf("%d ", arr[i]);
		//}
		//printf("\n");

		mergeSort(1, N);

		printf("%ld\n", numSwaps);
		//for (int i = 1; i <= N; i++) {
		//	printf("%d ", arr[i]);
		//}
		//printf("\n");
	}
	return 0;
}	
