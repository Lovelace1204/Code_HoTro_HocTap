#include<stdio.h>

int main () {
	int m;
	scanf("%d", &m);
	
	
	
	int a[m][m];
	for ( int i = 0; i < m; i++){
		for ( int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int mid = m/2;
	for ( int i = 0; i < m; i++) {
		for ( int j = 0; j < m; j++) {
			if ( j == i || j == m-1-i ) printf("%d ", a[i][m-1-j]);
			else 						printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}