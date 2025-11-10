#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_N 10

int count = 0;
bool columns[MAX_N];
bool diag1[2 * MAX_N];
bool diag2[2 * MAX_N];

void solve(int row, int n) {
	if(row==n) {
		count++;
		return;
	}
	for(int col=0; col<n; col++) {
		if(columns[col] || diag1[row-col+n-1] || diag2[row+col])
			continue;
		columns[col] = true;
		diag1[row-col+n-1] = true;
		diag2[row+col] = true;
		solve(row+1,n);
		columns[col] = false;
		diag1[row-col+n-1] = false;
		diag2[row+col] = false;
	}
}

int nQueen(int n) {
	count = 0;
	for(int i=0; i<MAX_N; i++)
		columns[i] = false;
	for(int i=0; i<2*MAX_N; i++)
		diag2[i] = false;
	solve(0,n);
	return count;
}

int main() {
	int n;
	scanf("%d",&n);
	if(n<2 || n>10){
		printf("0\n");
		return 0;
	}
	int sol = nQueen(n);
	printf("%d\n",sol);
	return 0;
}