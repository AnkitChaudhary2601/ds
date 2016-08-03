#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;

// assuming str2 is non empty
void replaceBy(char str1[], char str2[], char c){
	int len1 = strlen(str1);
	if(len1 == 0) return;

	int len2 = strlen(str2);
	if(len2 == 0) return;

	printf("%d %d\n", len1, len2);
	int count = 0;
	for(int i=0; i<len1; i++){
		if(str1[i]==c) 
			count++;
	}

	int j = len1 - 1 + (len2 - 1)*count;
	str1[j+1] = '\0';
	for(int i=len1-1; j>i && i>=0; i--){
		if(str1[i]!=c){
			str1[j--]=str1[i];
		}else {
			for(int k=len2-1; k>=0; k--, j--)
				str1[j] = str2[k];
		}
	}
}
int main(){
	char str[100];
	scanf("%[^\n]s%*c", str);
	char b[] = "%20";
	replaceBy(str, b, ' ');
	printf("%s\n", str);
}