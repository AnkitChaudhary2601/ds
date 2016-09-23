#include<cstring>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;

#define MAX_LEN 1000000
#define CHAR_SET 256

// find anargam of s in text t. 
vector<pair<int,int> > findAnagrams(char* s, char* t){
	vector<pair<int,int> > ans;
	int len1 = strlen(s);
	int len2 = strlen(t);
	if(!len1 || !len2 || len1 > len2) return ans; // return empty set

	int hashSet1[CHAR_SET] = {0};
	for(int i=0; i<len1; i++)
		hashSet1[s[i]]++; // count frequency of characters in s

	int hashSet2[CHAR_SET] = {0};
	for(int start=0, i=0; i<len2; i++){
		int ch = t[i];
		hashSet2[ch]++;
		if(hashSet2[ch] > hashSet1[ch]){ //Either ch is non-matched char or appeared more times than required 
			while(t[start]!=ch){
				hashSet2[t[start++]]--;
			}
			hashSet2[t[start++]]--;
		}

		if(i-start+1 == len1) // start will be 1 ahead of i if ch in non-matched char, hence i-start+1=0, which is not equal to non-zero len1
			ans.push_back(make_pair<int,int>(start, i));
	}
	return ans;
}

int main(){
	char text[MAX_LEN], str[MAX_LEN];
	scanf("%s %s", text, str);
	vector<pair<int,int> > v = findAnagrams(str, text);	
	for(int i=0; i<v.size(); i++)
		printf("%d %d\n", v[i].first, v[i].second);
}