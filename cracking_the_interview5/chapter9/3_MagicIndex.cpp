#include<cstdio>
#include<algorithm>

using namespace std;

int magicIndex(int arr[], int low, int high){
	if(low > high) return -1;

	int mid = (low+high)/2;
	if(arr[mid] == mid) return mid;
	if(arr[mid] > mid) return magicIndex(arr, low, mid-1);
	return magicIndex(arr, mid+1, high);
}

int magicIndexRecursve(int arr[], int n){
	return magicIndex(arr, 0, n-1);
}

int magicIndexIterative(int arr[], int n){
	int low=0, mid, high=n-1;
	
	while(low <= high){
		mid = (low+high)/2;
		if(arr[mid] == mid) {
		  return mid;
		} else if(arr[mid] > mid){
			high = mid-1;
		} else if(arr[mid] < mid){
			low = mid+1;
		}
	}
	return -1;
}

int magicIndexWithDuplicates(int arr[], int low, int high){
	if(low > high) return -1;
	int mid = (low+high)/2;
	if(arr[mid] == mid) return mid;
	
	int left = magicIndexWithDuplicates(arr, low, min(mid-1, arr[mid]));
	if(left >=0 ) return left;

	return magicIndexWithDuplicates(arr, max(mid+1, arr[mid]), high);
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d", arr+i);
	}

	int i = magicIndexWithDuplicates(arr, 0, n-1);
	printf("Ans : %d\n", i);
}