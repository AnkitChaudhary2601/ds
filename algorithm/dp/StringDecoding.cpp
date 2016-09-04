#include<cstdio>
#include<cstring>

using namespace std;

// Assuming empty string = 1 way
// Assuming string has digits from 0 to 9 and string is valid
int countDecodings(char* str){
	int n = strlen(str);
	if(n<=1) return 1;

	// a = dp[i-2], b = dp[i-1], c = dp[i]
	int a=1,b=1,c=0;
	for(int i=1; i<n; i++){
		if(str[i]=='0'){
			c = a;
		} else {
			c = b;
			if(str[i-1]=='1' || (str[i-1]=='2' && str[i] < '7')) {
				c += a;
			}
		}

		a = b;
		b = c;
	}
	return c;
}

int main(){
	char str[100];
	scanf("%s", str);
	printf("%d\n", countDecodings(str)); 
}
