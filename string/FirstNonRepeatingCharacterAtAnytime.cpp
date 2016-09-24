//http://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

#include<cstdio>

using namespace std;

#define MAX_LEN 100000
#define CHAR_SET 256

// Amortized cost is O(1)
void findFirstNonRepeating(char* str){
	if(str==NULL) return;
	int hashSet[CHAR_SET] = {0};
	for(int i=0, j=0; str[j]; j++){
		hashSet[str[j]]++;
		while(i<=j && hashSet[str[i]]>1) 
			i++;
		printf("%c", i>j ? '?' : str[i]);
	}
	printf("\n");
}

int main(){
	char str[MAX_LEN];
	scanf("%s", str);
	findFirstNonRepeating(str);
}