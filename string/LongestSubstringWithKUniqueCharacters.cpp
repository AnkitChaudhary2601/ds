//http://www.geeksforgeeks.org/find-the-longest-substring-with-k-unique-characters-in-a-given-string/

#include<cstdio>
using namespace std;

#define CHAR_SET 256
#define MAX_LEN 1000000

int longestSubstr(char* str, int k){
	if(k<=0 || *str=='\0') return 0; // If k <=0 or string is empty then return 0

	int hashSet[CHAR_SET]; // stores latest index of character while traversing string from left to right
	for(int i=0; i<CHAR_SET; i++)
		hashSet[i]=-1;

	int i=0, ans=0;
	for(int i=0; str[i] && ans<k; i++){
		if(hashSet[str[i]]==-1) ans++; // found str[i] first time, then increment ans
		hashSet[str[i]]=i;
	}

	if(ans<k) return 0; // if number of characters in whole string is less than k

	for(int low=0; str[i]; i++){	// low is start index of window
		if(hashSet[str[i]]<low){ // If current character is not present in window, then we have to remove some character from left side	
			while(low<i && hashSet[str[low]]!=low)	
				low++;
			low++;
		} else if(ans < i-low+1)
			ans = i-low+1;

		hashSet[str[i]] = i;
	}

	return ans;
}

int main(){
	int k;
	scanf("%d", &k);
	char str[MAX_LEN];
	scanf("%s", str);
	printf("%d\n", longestSubstr(str, k));
	return 0;
}