#include<cstring>
#include<cstdio>
#include<utility>

#define MAX_LEN 100000
#define CHAR_SET 256

using namespace std;

// return smallest substring of s1 having all characters of s2
pair<int,int> minWindow(char* s1, char* s2){
	pair<int,int> p = make_pair<int,int>(-1,-1);

	// Check base conditions
	int len1 = strlen(s1); if(!len1) return p;
	int len2 = strlen(s2); if(!len2) return p;
	if(len1 < len2) return p;

	int set1[CHAR_SET] = {0}, set2[CHAR_SET] = {0};
	for(int i=0; i<len2; i++) set2[s2[i]]++;

	int start=0;
	// find first matching character of s2 in s1
	while(start<len1 && set2[s1[start]]==0) start++;

	// If no matching character found
	if(start==len1) return p; 

	// Find first substring starting from index 'start', having all characters of s2
	int j=start, count=0;
	for(; j<len1 && count<len2; j++){ // At end of loop j will be 1 ahead of sub-string end
		int ch = s1[j];
		if(set1[ch] < set2[ch]) count++;
		set1[ch]++;
	}

	// If all characters of s2 is not present in s1
	if(count<len2) return p; 

	p.first=start; p.second=j-1;
	int minLen = j - start;

	for(; j<len1; j++){
		int ch = s1[j];
		set1[ch]++;
		// If first and last characters are same, then move start ahead till we have all chars of s2
		if(s1[start] == ch){
			while(set1[ch] > set2[ch]){ // Till we have extra chars at start of sub-string, move ahead
				set1[ch]--;
				ch = s1[++start];
			}

			if(j-start+1 < minLen){
				minLen = j-start+1;
				p.first = start;
				p.second = j;
			}
		}
	}
	
	return p;
}

int main(){
	char s1[MAX_LEN], s2[MAX_LEN];
	scanf("%s", s1);
	scanf("%s", s2);

	// printf("%s %s\n", s1, s2);

	pair<int,int> p = minWindow(s1, s2);

	if(p.first==-1) printf("No matching sub-string found\n");
	else {
		for(int i=p.first; i<=p.second; i++)
			printf("%c", s1[i]);
		printf("\n");
	}
}