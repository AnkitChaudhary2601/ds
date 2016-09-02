#include<cstdio>

int max(int a, int b){
	return a>b?a:b;
}

int maxValue(int itemValues[], int itemWeights[], int capacity, int n){
	if(n==0 || capacity==0) return 0;
	int dp[capacity+1][n+1];

	for(int i=0; i<=capacity; i++){
		for(int j=0; j<=n; j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			} else if(itemWeights[j-1] > i){ // if weight of jth(1 based index) item is greater than capacity i, then cannot put this item to knapsack
				dp[i][j] = dp[i][j-1]; // so answer is same as of with same capacity(i) and not taking jth item i.e dp[i][j-1]
			} else {
				dp[i][j] = max(dp[i-itemWeights[j-1]][j-1] + itemValues[j-1],  dp[i][j-1]);
			}
		}
	}

	return dp[capacity][n];
}

int main(){
	int capacity, n;
	printf("Enter knapsack capacity and number of items: ");
	scanf("%d %d", &capacity, &n);
	int weights[n], value[n];
	printf("Enter weights : ");
	for(int i=0;i<n;i++){
		scanf("%d", weights + i);
	}

	printf("Enter values : ");
	for(int i=0;i<n;i++){
		scanf("%d", value + i);
	}

	printf("ans : %d\n", maxValue(value, weights, capacity, n));
}
