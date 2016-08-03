#include<cstdio>
// #include<cstring>
using namespace std;

int strlen(char *str){
	if(str == NULL) return 0;
	int i=0;
	while(str[i]) i++;
	return i;
}

void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char *str){
	int len = strlen(str);
	if(len<=1) return;

	int i=0, j=len-1;
	while(i<j){
		swap(str+i, str+j);
		i++;
		j--;
	}
}

int main(){
	char str[1000];
	scanf("%s",str);
	reverse(str);
	printf("%s\n",str);
}