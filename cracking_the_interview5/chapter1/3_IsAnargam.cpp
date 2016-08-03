#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

bool isAnargam(string str1, string str2){
	if(str1.size() != str2.size())
		return false;
	
	int count[256] = {0};

	for(int i=0; i<str1.size(); i++){
		count[str1[i]]++;
	}

	for(int i=0; i<str2.size(); i++){
		int val = str2[i];
		if(--count[val] < 0)
			return false;
	}

	return true;
}

int main(){
	string str1, str2;
	cin>>str1;
	cin>>str2;
	cout<<isAnargam(str1, str2)<<"\n";
}