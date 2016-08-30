#include<cstdio>
#include<cstring>

int longestSubstringWithUniqueChars(char* str){
	int n = strlen(str);
	if(n<=1) return n;

	int ans = 0;
	int hashset[256];
	memset(hashset, -1, 256*sizeof(int));
	
	for(int i=0, start=0; i<n; i++){
		if(hashset[str[i]] != -1 && hashset[str[i]] >= start){
			start = hashset[str[i]] + 1;
		}

		hashset[str[i]] = i;

		if(i - start + 1 > ans)
			ans = i - start + 1;
	}

	return ans;
}

int main(){
	char str[1001];
	scanf("%s", str);
	printf("%d\n", longestSubstringWithUniqueChars(str));
}