#include<cstdio>
#include<stack>

using namespace std;

void pushOnAuxStack(stack<int> &s1, stack<int> &s2, int val){
	while(!s2.empty() && s2.top() < val){
		s1.push(s2.top());
		s2.pop();
	}
	s2.push(val);
}

void sort(stack<int> &s1){
	stack<int> s2;
	while(!s1.empty()){
		int val = s1.top();
		s1.pop();	
		pushOnAuxStack(s1, s2, val);
	}

	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}

void print(stack<int> s){
	while(!s.empty()){
		printf("%d ", s.top());
		s.pop();
	}
	printf("\n");
}

int main(){
	int n,val;
	stack<int> s;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d", &val);
		s.push(val);
	}

	sort(s);
	print(s);
}