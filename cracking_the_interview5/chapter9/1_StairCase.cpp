#include<cstdio>
using namespace std;

int arr[100000] = {0, 1, 2, 4};
int countWaysRecursive(int n){
	if(n<=1) return n;
	if(n==2) return 2;
	if(n==3) return 4;
	return countWaysRecursive(n-1) + countWaysRecursive(n-2) + countWaysRecursive(n-3);
}

int countWaysIterative(int n){
	if(n<=1) return n;
	if(n==2) return 2;
	if(n==3) return 4;

	int a=1, b=2, c=4;
	for(int i=4; i<=n; i++){
		int tmp = a+b+c;
		a=b;
		b=c;
		c=tmp;
	}
	return c;
}

int main(){
	int t,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n", countWaysIterative(n));
	}
}