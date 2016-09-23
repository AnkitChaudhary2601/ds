//http://www.geeksforgeeks.org/print-all-interleavings-of-given-two-strings/

#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

#define MAX_LEN 1000000

void interleaving(char* str1, char* str2, char* ans, int i){
	if(*str1=='\0' && *str2=='\0'){
		printf("%s\n", ans);
		return;
	}

	if(*str1){
		ans[i] = *str1;
		interleaving(str1+1, str2, ans, i+1);
	}

	if(*str2){
		ans[i] = *str2;
		interleaving(str1, str2+1, ans, i+1);
	}
}

void interleaving(char* str1, char* str2){
	int n1 = strlen(str1);
	int n2 = strlen(str2);

	char* ans = (char*)malloc(sizeof(char)*(n1+n2+1));
	ans[n1+n2]='\0';

	interleaving(str1, str2, ans, 0);
	free(ans);
}

int main(){
	char str1[MAX_LEN], str2[MAX_LEN];
	scanf("%s %s", str1, str2);
	interleaving(str1, str2); 
}