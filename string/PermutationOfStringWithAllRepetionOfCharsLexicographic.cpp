//http://www.geeksforgeeks.org/print-all-permutations-with-repetition-of-characters/

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

void permut(char* str, char* ans, int i, int n){
	if(i==n){
		printf("%s\n", ans);
		return;
	}

	for(int j=0; j<n; j++){
		ans[i] = str[j];
		permut(str, ans, i+1, n);
	}
}

// Assuming unique characters in string, otherwise duplicate permutations will be printed
void permut(char* str){
	int len = strlen(str);
	if(len==0) return;
	sort(str, str+len);
	char* ans = (char*)malloc(sizeof(char)*len+1);
	ans[len]='\0';
	permut(str, ans, 0, len);
}

int main(){
	char str[10];
	scanf("%s", str);
	permut(str);
}