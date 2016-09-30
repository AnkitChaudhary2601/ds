#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<utility>

using namespace std;

#define CHAR_SET 256

bool isValid(int frequency[], int n){
	if(n&1){
		bool foundOdd=false;
		for(int i=0; i<n; i++){
			if(frequency[i]&1){ // if found odd frequency 
				if(foundOdd) return false;
				foundOdd = true;
			}
		}
	} else {
		for(int i=0; i<n; i++){
			if(frequency[i]&1) 
				return false;
		}
	}
	return true;
}

void print(vector<pair<char, int> > &v, char* output, int low, int high){
	if(low>high){
		printf("%s\n", output);
		return;
	}

	for(int i=0; i<v.size(); i++){
		if(v[i].second>1 || (v[i].second==1 && low==high)){ // if there frequecy is more than 2 or if it is 1 then it should be middle element, i.e low==high
			output[low]=output[high]=v[i].first;  // put same character at low and high and decrement its ferequency by 2
			v[i].second = v[i].second-2;
			print(v, output, low+1, high-1); // corner characters are fixed, now permute rest of the smaller substring
			v[i].second = v[i].second+2;     // restore previous state
		} 
	}
}

/*
	The idea is to find frequency of all chars and first validate it.
	Then set corner characters and recursively go for smaller string.
*/

void printAllPalindromePermutations(char* str){
	if(str==NULL) return;
	int n = strlen(str);

	int frequency[CHAR_SET] = {0};
	for(int i=0; i<n; i++){
		frequency[str[i]]++;
	}

	if(!isValid(frequency, n)) return;
	char* output = (char*) malloc(sizeof(char)*(n+1));
	output[n]='\0';

	vector<pair<char, int> > v;
	for(int i=0; i<CHAR_SET; i++){
		if(frequency[i])
			v.push_back(make_pair<char, int>(i, frequency[i]));
	}
	print(v, output, 0, n-1);
	free(output);
}

int main(){
	char str[1000];
	scanf("%s", str);
	printAllPalindromePermutations(str);
}