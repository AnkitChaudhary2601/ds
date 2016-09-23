//http://www.geeksforgeeks.org/remove-a-and-bc-from-a-given-string/

#include<cstring>
#include<cstdio>

using namespace std;

#define MAX_LEN 1000000

void removeBandAC(char* str){
	if(str == NULL || *str == '\0') return; // If string is empty, then return
	int i=-1; // i points to last valid character
	for(int j=0; str[j]; j++){
		if(str[j]=='c'){
			// If current character is 'c' and last valid character was 'a', then remove 'a', i.e. i--
			if(i>=0 && str[i]=='a')  
				i--;
			else  // If last valid was not 'a', then copy 'c' to output.
				str[++i] = str[j];
		} else if(str[j]!='b'){
			// If current character is not 'b', then just copy it to output.
			str[++i] = str[j];
		}
	}
	str[++i]='\0';
}

int main(){
	char str[MAX_LEN];
	scanf("%s", str);
	removeBandAC(str);
	printf("%s\n", str);
}