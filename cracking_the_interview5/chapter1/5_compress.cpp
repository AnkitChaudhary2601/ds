#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;

int digits(int n){
	int d = 0;
	while(n){
		n/=10;
		d++;
	}
	return d;
}

int compressBy(char *str, int len){
	int count = 0;
	for(int i=0, j=0; i<len; ){
		int n=1;
		for(j=i+1; j<len && str[i]==str[j]; j++)
			n++;
		count += (n-1-digits(n));
		i=j;
	}
	return count;
}

char * intToString(int n){
	int d = digits(n);
	char *str = (char*) malloc(sizeof(char)*(d+1));
	int i=0;
	while(n){
		str[i++] = n%10 + '0';
		n/=10;
	}

	str[i] = '\0';
	i--;
	for(int j=0; j<i; j++, i--){
		char tmp = str[i];
		str[i]=str[j];
		str[j]=tmp;
	}

	return str;
}

char * compress(char *str1){
	int len = strlen(str1);
	int reduceBy = compressBy(str1, len);

	if(reduceBy<=0) 
		return str1;

	char* str2 = (char*)malloc( (len - reduceBy)*sizeof(char));

	int k=0;
	for(int i=0,j=0; i<len; ){
		str2[k++]=str1[i++]; 

		int n = 1;
		for(j=i; j<len && str1[i]==str1[j] ; j++)
			n++;

		char *str3 = (char*) malloc(sizeof(char)*(digits(n)+1));
		itoa(n, str3, 10);
		char *tmp = str3;
		while(*str3){
			str2[k++] = *str3;
			str3++;
		}
		free(tmp);

		i=j;
	}
	str2[k]='\0';
	return str2;
}

int main(){
	char str[1000000];
	scanf("%s", str);

	char *s= compress(str);
	printf("%s\n", s); 
}