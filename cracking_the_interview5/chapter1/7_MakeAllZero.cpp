#include<stdio.h>
using namespace std;
int arr[10][10];

void print(int m, int n){
	for(int i=0; i<m ;i++){
		for(int j=0; j<n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void markZero(int m, int n){
	bool firstRow = false, firstColum  = false;

	for(int i=0; i<n; i++){
		if(arr[0][i]==0){
			firstRow = true;
			break;
		}
	}

	for(int i=0; i<m; i++){
		if(arr[i][0]==0){
			firstColum = true;
			break;
		}
	}

	for(int i=1; i<m; i++){
		for(int j=1; j<n; j++){
			if(arr[i][j]==0){
				arr[i][0] = arr[0][j] = 0;
			}
		}
	}

	for(int i=1; i<m ;i++){
		for(int j=1; j<n; j++){
			if(arr[i][0]==0 || arr[0][j]==0)
				arr[i][j] = 0;
		}
	}

	if(firstRow){
		for(int i=0;i<n;i++)
			arr[0][i] = 0;
	}

	if(firstColum){
		for(int i=0;i<m;i++)
			arr[i][0] = 0;
	}
}

int main(){
	int m,n;
	scanf("%d %d", &m, &n);
	for(int i=0;i<m;i++)
		for(int j=0; j<n;j++)
			scanf("%d", &arr[i][j]);

	// print(m, n);
	markZero(m, n);
	printf("\n");
	print(m, n);
}