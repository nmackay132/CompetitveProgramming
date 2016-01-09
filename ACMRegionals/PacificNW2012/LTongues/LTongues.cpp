/*
*****Solved*****
Cipher
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

char consonants[] = { 'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f' };
char vowels[] = { 'a', 'i', 'y', 'e', 'o', 'u' };

bool isAlpha(char c){
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		return true;
}

int main(){
	string line; 
	while (getline(cin, line)){
		for (int i = 0; i < line.size(); i++) {
			if (!isAlpha(line[i])) continue;
			bool switched = false;
			for (int j = 0; j < 6; j++) {
				if (line[i] == vowels[j]){
					line[i] = vowels[(j - 3 + 6) % 6];
					switched = true; break;
				}
			}
			for (int j = 0; j < 6 && !switched; j++) {
				if (line[i] == vowels[j]-32){
					line[i] = vowels[(j - 3 + 6) % 6]-32;
					switched = true; break;
				}
			}
			for (int j = 0; j < 20 && !switched; j++) {
				if (line[i] == consonants[j]){
					line[i] = consonants[(j - 10 + 20) % 20];
					switched = true; break;
				}
			}
			for (int j = 0; j < 20 && !switched; j++) {
				if (line[i] == consonants[j]-32){
					line[i] = consonants[(j - 10 + 20) % 20] - 32; break;
				}
			}
		}
		cout << line << endl;
	}
	return 0;
}	
