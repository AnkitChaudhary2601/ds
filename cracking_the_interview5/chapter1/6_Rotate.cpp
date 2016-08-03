#include<cstdio>
using namespace std;
int arr[10][10] = {0};

void print(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

void rotate(int i, int n);
void rotate(int n){
	int start = 0;
	while(n>1){
		for(int i=start;i<n;i++)
			rotate(i, n);
		print(n);
		start++;
		n-=2;
	}
}

int nextIndex(int, int, int);
void rotate(int start, int n){
	int prevVal = arr[start/n][start%n];
	int direction = 0;
	int current = nextIndex(start, direction, n);

	while(current!=start){
		printf("current : %d\n", current);
		int i = current/n;
		int j = current%n;
		int tmp = arr[i][j];
		arr[i][j] = prevVal;
		prevVal = tmp;

		direction = (direction+1)%4;

		current = nextIndex(current, direction, n);
	} 
	printf("current : %d\n", current);
	arr[current/n][current%n] = prevVal;
}

int nextIndex(int currentIndex, int direction, int n){
	int i = currentIndex/n;
	int j = currentIndex%n;
	n--;
	if(direction == 0){
		i = j;
		j = n;
	} else if(direction == 1){
		j = j- i;
		i = n;
	} else if(direction == 2){
		i = i - j;
		j = 2*j - n;
	} else if(direction == 3){
		j = i;
		i = 2*i - n;
	}

	n++;
	return i*n + j;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			arr[i][j] = i*n + j;
	}

	print(n);
	rotate(n);
	print(n);
}