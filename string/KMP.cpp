#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

void computeLPS(char* str, int lps[]) {
	int i=1, j=0;
	lps[0]=0;
	int n = strlen(str);
	while(i<n) {
		if(str[i]==str[j]) {
			lps[i]=j+1;
			i++;
			j++;
		} else if(j!=0) {
			j = lps[j-1];
		} else {
			lps[i]=0;
			i++;
		}
	}
}

vector<int> kmp(char* text, char* pattern) {
	vector<int> index;
	int n = strlen(text);
	int m = strlen(pattern);
	if(m==0 || n==0 || m > n) return index;

	int lps[m];
	computeLPS(pattern, lps);
	
	
	int i=0, j=0;
	while(i<n) {
		if(text[i]==pattern[j]) {
			i++; j++;
			if(j==m) {
				j = lps[j-1];
				index.push_back(i-m);
			}
		}
		else if(j!=0) {
			j = lps[j-1];
		} else {
			i++;
		}
	}
	return index;
}

int main(){
	char pattern[1000], text[100000];
	scanf("%s %s", text, pattern);
	vector<int> ans = kmp(text, pattern);
	for(int i=0; i<ans.size(); i++){
		printf("Match found at : %d\n", ans[i]);
	}
}