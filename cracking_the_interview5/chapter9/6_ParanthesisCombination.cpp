#include<cstdio>
using namespace std;

void printParen(char* str, int leftRemain, int rightRemain, int index){
	if(leftRemain < 0 || rightRemain < leftRemain) return; //Invalid state
	if(leftRemain == 0 && rightRemain == 0){
		printf("%s\n", str);
	}else{
		if(leftRemain>0){
			str[index] = '(';
			printParen(str, leftRemain-1, rightRemain, index+1);
		}

		if(rightRemain > leftRemain){
			str[index] = ')';
			printParen(str, leftRemain, rightRemain-1, index+1);
		}
	}
}
int main(){
	int pairs;
	scanf("%d", &pairs);
	char str[2*pairs+1];
	str[2*pairs] = '\0';
	printParen(str, pairs, pairs, 0);
}