#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
 
void printSorted(std::vector<int> v, int i){
	if(i >= v.size()) return;
	printSorted(v, i*2+1);
	printf("%d ", v[i]);
	printSorted(v, i*2+2);
}

int main(){
	vector<int> v;

	int n,tmp;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	printSorted(v, 0);
}