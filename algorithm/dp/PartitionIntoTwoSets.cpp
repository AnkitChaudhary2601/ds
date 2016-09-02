#include<cstdio>
#include<cstring>

// arr contains positive elements
bool isSumSetPossible(int arr[], int n, int sum){
	if(sum == 0 && n==0) return true;
	if(sum == 0 && n!=0) return false;
	int totalSum = 0;
	for(int i=0; i<n; i++)
		totalSum+=arr[i];
	if(totalSum < sum) return false;
	if(totalSum == sum) return true;
	// dp[i][j] = true, if sum j can be achived using some of i elements of array.
	// using 1D array for storing states(optimized)
	bool dp[sum+1], tmp[sum+1];
	memset(dp, 0, sizeof(dp)/sizeof(bool));
	memset(tmp, 0, sizeof(tmp)/sizeof(bool));

	for(int i=0; i<n ;i++){
		for(int j=1; j<=sum ; j++){
			dp[j] = tmp[j];           // dp[i-1][j] = tmp[j]
			if(j == arr[i]) 
				dp[j] = true;
			else if(j > arr[i])
				dp[j] = dp[j] || tmp[j-arr[i]];  // dp[i][j] = dp[i][j] || dp[i-1][j - arr[i]] and dp[i-1] is tmp array
		}

		if(dp[sum]) return true; // can break loop if found sum
		
		for(int j=1; j<=sum; j++)
			tmp[j] = dp[j];
	}

	return dp[sum];
}

// This will work for array of integers.
bool isSumSetPossible2(int arr[], int n, int sum){
	if(sum == 0 && n==0) return true;
	
	int low=0, high=0;
	for(int i=0; i<n; i++){
		if(arr[i] > 0)
			high += arr[i];
		else 
			low += arr[i];
	}

	if(sum<low || sum>high) return false;
	if(sum==low || sum==high) return true;

	// dp[i][j] = true, if sum j can be achived using some of i elements of array.
	// using 1D array for storing states(optimized)
	int size = high - low + 1;
	int baseIndex = -low;
	printf("%d %d\n", sum, baseIndex);
	bool dp[size], tmp[size];
	memset(dp, 0, sizeof(dp)/sizeof(bool));
	memset(tmp, 0, sizeof(tmp)/sizeof(bool));

	for(int i=0; i<n ;i++){
		for(int j=low; j<=high ; j++){
			dp[j+baseIndex] = tmp[j+baseIndex];           // dp[i-1][j] = tmp[j]
			if(j == arr[i])
				dp[j+baseIndex] = true;
			else if(j-arr[i]>=low && j-arr[i]<=high)
				dp[j+baseIndex] = dp[j+baseIndex] || tmp[j + baseIndex - arr[i]];  // dp[i][j] = dp[i][j] || dp[i-1][j - arr[i]] and dp[i-1] is tmp array
		}
		
		if(dp[sum + baseIndex]) return true;
		for(int j=0; j<size; j++)
			tmp[j] = dp[j];
	}

	return dp[sum + baseIndex];
} 

bool isPartionable(int arr[], int n){
	if(n==0) return true;
	int sum = 0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
	}

	if(sum & 1) return false; // if sum is odd return false;
	return isSumSetPossible(arr, n, sum/2);
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d", arr+i);
	// printf("%s\n", isPartionable(arr, n) ? "Yes" : "No");
	int sum;
	scanf("%d", &sum);
	printf("%s\n", isSumSetPossible2(arr, n, sum) ? "Yes" : "No");
}