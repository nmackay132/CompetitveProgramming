/*
*****Solved*****
UVa 10114

Problem type:
easy
*/

/*
#include <iostream>
#include <stdlib.h>
#include <cstdio>

using namespace std;

double depr[110];

int main(){

	while (true){
		int numMonths;
		int N;
		double downpayment, total;

		scanf("%d %lf %lf %d", &numMonths, &downpayment, &total, &N);
		/*printf("monthlyRate %lf, total %lf\n", monthlyRate, total);

		if (numMonths < 0) break;
		fill_n(depr, 110, 0);

		for (int i = 0; i < N; i++) {
			int month;
			double rate;
			cin >> month >> rate;
			depr[month] = 1 - rate;
		}

		//printf("depr[1] %fl\n", depr[1]);
		double monthly_payment = total/numMonths;
		double loan = total;
		double value = total + downpayment;
		int i = 0;
		double rate = depr[0];
		value *= rate;
		//printf("value %lf\n", value);
		if (loan < value) {
			printf("0 months\n");
		}
		else{
			for (i = 1; i < 110; i++){
				if (loan < value) {
					//printf("loan %d, value %d\n", loan, value);
					break;
				}
				loan -= monthly_payment;
				if (depr[i] > 0) rate = depr[i];
				value *= rate;
				//printf("value %lf rate %lf\n", value, rate);
				//printf("loan %lf\n", loan);
				if (loan < value) {
					//printf("loan %d, value %d\n", loan, value);
					break;
				}
			}

			if (i == 1)
				printf("%d month\n", i);
			else
				printf("%d months\n", i);
		}
	}
}

/*
30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1
*/