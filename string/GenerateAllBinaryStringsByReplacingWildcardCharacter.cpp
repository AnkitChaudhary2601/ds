//http://www.geeksforgeeks.org/generate-all-binary-strings-from-given-pattern/
#include<cstdio>
using namespace std;

void printBinary(char* str, int i){
	if(!str[i]){
		printf("%s\n", str);
		return;
	}

	if(str[i]=='?'){
		str[i]='0';
		printBinary(str, i+1);
		str[i]='1';
		printBinary(str, i+1);
		str[i]='?';
	} else printBinary(str, i+1);
}

int main(){
	char str[1000];
	scanf("%s", str);
	printBinary(str, 0);
}