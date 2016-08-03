#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

bool isUniqueChars(string str);
int main(){
	string str;
	cin>>str;
	cout<<str<<"\n";
	cout<<isUniqueChars(str)<<"\n";
}

bool isUniqueChars(string str){
	if(str.size()==0)
		return true;

	if(str.size() > 256)
		return false;

	bool charSet[256] = {false};

	for(int i=0; i<str.size(); i++){
		char c = str[i];
		if(charSet[c])
			return false;
		charSet[c] = true;
	}
	return true;
}