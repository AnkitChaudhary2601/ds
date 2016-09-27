//http://www.geeksforgeeks.org/print-ways-break-string-bracket-form/
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

void printUtil(char* str, char* output, int i){
	if(*str=='\0'){
		output[i]='\0';
		printf("%s\n", output);
		return;
	}

	output[i++]='(';
	for(int j=0; str[j]; j++){
		output[i++]=str[j];
		output[i]=')';
		printUtil(str+j+1, output, i+1);
	}
}

void printAllBrackets(char* str){
	int n = strlen(str);
	if(n==0) return;
	char* output = (char*)malloc(sizeof(char)*(3*n+1));
	printUtil(str, output, 0);
}

int main(){
	char str[1000];
	scanf("%s", str);
	printAllBrackets(str);
}