//http://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/

#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
	return a.second < b.second;
}

void printAnagramTogether(vector<string> &v){
	vector<pair<int, string> > dup;
	for(int i=0; i<v.size(); i++){
		string s = v[i];
		sort(s.begin(), s.end());
		dup.push_back(make_pair<int, string>(i, s));
	}
	
	sort(dup.begin(), dup.end(), cmp);

	for(int i=0; i<dup.size(); i++)
		cout<<v[dup[i].first]<<" ";
}

int main(){
	vector<string> V;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		V.push_back(s);
	}

	printAnagramTogether(V);
}