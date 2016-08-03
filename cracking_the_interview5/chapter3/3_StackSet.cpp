#include<cstdio>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

vector<stack<int> > v;
int capacity = 5;

int getLastStackIndex(){
	if(v.size()==0){
		stack<int> s;
		v.push_back(s);
		return 0;
	} else {
		return v.size() - 1;
	}
}

void push(int val){
	int index = getLastStackIndex();
	stack<int> s = v[index];
	if(s.size() == capacity){
		stack<int> s1;
		v.push_back(s1);
		s1.push_back(val);
	}else{
		s.push(val);
	}
}
