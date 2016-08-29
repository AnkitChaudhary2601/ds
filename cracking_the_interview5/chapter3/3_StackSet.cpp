#include<cstdio>
#include<vector>
#include<stack>

using namespace std; 

int STACK_SIZE = 5;

stack<int> newStack(int val){
	stack<int> s;
	s.push(val);	
return s;
}

void push(vector<stack<int> > &stacks, int val) {
	if(stacks.size() == 0 || stacks[stacks.size()-1].size() == STACK_SIZE){
		stacks.push_back(newStack(val));
} else {
	stacks[stacks.size()-1].push(val);
}
}

void pop(vector<stack<int> > &stacks){
	if(stacks.size() != 0 ){
	stacks[stacks.size()-1].pop();
	if(stacks[stacks.size()-1].size() == 0){
		stacks.pop_back();
}
} 
}

int top(vector<stack<int> > &stacks){
	if(stacks.size() != 0){
		return stacks[stacks.size()-1].top();
}
return -1;
}



int main(){
	vector<stack<int> > stacks;
	int op, val;
 	bool flag = true;
	while(flag){
		scanf("%d",&op);
		switch(op){
			case 0 : flag = false;
				break;
			case 1 : 
				scanf("%d", &val);
				push(stacks,  val);
				break;
			case 2 :
				pop(stacks);
				break;
			case 3 : 
				printf("%d\n", top(stacks));
				break;
}
}
}
