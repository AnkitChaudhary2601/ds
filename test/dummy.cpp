#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(){
	string s(10, '1');
	for(int i=0; i<10;i++){
		if(s[i]=='\0')
			cout<<i;
		else
			cout<<s[i];
	}
}