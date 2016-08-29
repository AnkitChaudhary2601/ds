#include<cstdio>

int max(int a, int b){
	return a>b ? a : b;
}
int kaden(int arr[], int n){
	if(n==0) {
		return 0;
	}

	int sum=arr[0], ans=arr[0];
	for(int i=1;i<n;i++){
		sum = max(arr[i], arr[i]+sum);
		if(sum > ans) 
			ans = sum;
	}
	return ans;
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}

	printf("Max Contiguous Sum = %d\n", kaden(arr, n));
}