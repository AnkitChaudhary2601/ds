#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int insertionCost;
int deletionCost;
int replacementCost;

int dp[102][102];

int min(int a, int b){
	return a < b ? a : b;
}

int min(int a, int b, int c){
	return min(min(a,b), c); 
}

int editDistance(char *x, char *y){
	int m = strlen(x);
	int n = strlen(y);
	if(m==0) return n*insertionCost;
	if(n==0) return m*deletionCost;

	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i==0) {
				dp[i][j] = j*insertionCost;
			} else if(j==0) {
				dp[i][j] = i*deletionCost;
			}
			else if(x[i-1] == y[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(deletionCost + dp[i-1][j],
								dp[i][j-1] + insertionCost,
								replacementCost + dp[i-1][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main(){
	char str1[101], str2[101];
	scanf("%s %s", str1, str2);
	printf("%s %s\n", str1, str2);
	scanf("%d %d %d", &insertionCost, &deletionCost, &replacementCost);
	int minDst = editDistance(str1, str2);
	printf("ans : %d\n", minDst);
}