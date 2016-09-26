#include<cstdio>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

void printAllPalidromePartitions(char* str, vector<int> &curr, vector<vector<int> > &v, int ind, int n){
	if(ind==n){
		curr.push_back(n);
		for(int i=0; i<curr.size()-1; i++){
			for(int j=curr[i]; j<curr[i+1]; j++){ // subtring from index curr[i] to curr[i+1]-1 is palindrome.
				printf("%c", str[j]);	// print palindrome
			}
			printf(" ");
		}
		printf("\n");
		curr.pop_back();
		return;
	}

	for(int i=0; i<v[ind].size(); i++){
		curr.push_back(ind + v[ind][i]); // next palindrome will start at ind+v[ind][i] or this palindrom extends upto ind+v[ind][i]-1
		printAllPalidromePartitions(str, curr, v, ind + v[ind][i], n);
		curr.pop_back();
	}

}

void printAllPalidromePartitions(char* str){
	int n = strlen(str);	
	bool isPalin[n][n];  // isPalin[i][j] = true, if substring(i to j) is palindrome else false
	vector<vector<int> > VV(n);  // VV[i] stores lengths of all palidroms starting from ith position
	
	isPalin[0][0] = true;
	VV[0].push_back(1);
	for(int i=1;i<n;i++){
		isPalin[i][i] = true; // 1 length palidrome
		VV[i].push_back(1);
		isPalin[i-1][i] = (str[i-1]==str[i]); // 2 length palindrome
		if(isPalin[i-1][i])
			VV[i-1].push_back(2);
	}

	for(int len = 3; len<=n; len++){
		for(int i=0; i<n-len+1; i++){
			int j = i+len-1;
			isPalin[i][j]= (str[i]==str[j]&&isPalin[i+1][j-1]);
			if(isPalin[i][j])
				VV[i].push_back(len);
		}
	}
	
	vector<int> curr; 	// subtring from index curr[i] to curr[i+1]-1 is palindrome.
	curr.push_back(0);
	printAllPalidromePartitions(str, curr, VV, 0, n);
}

int main(){
	char str[1000];
	scanf("%s", str);
	printAllPalidromePartitions(str);
}
