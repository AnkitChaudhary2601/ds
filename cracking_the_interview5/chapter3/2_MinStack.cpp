#include<cstdio>
#include<stack>
#include<climits>

using namespace std;

stack<int> mainStack;
stack<int> minStack;

int min();

void push(int val){
	mainStack.push(val);
	if(minStack.empty() || val <= min())
		minStack.push(val);
}

void pop(){
	if(mainStack.empty()) return;
	int tp = mainStack.top();
	mainStack.pop();
	if(tp == minStack.top())
		minStack.pop();
}

int top(){
	if(mainStack.empty())
		return INT_MIN;
	return mainStack.top();
}

int min(){
	if(minStack.empty())
		return INT_MIN;
	return minStack.top();
}

int main(){
	int op, val;
	while(true){
		scanf("%d", &op);
		switch(op){
		// push
			case 1 :
					scanf("%d", &val);
					push(val);
					break;
			case 2 : 
					pop();
					break;

			case 3: 
					printf("Min : %d\n", min());
					break;
			case 4:
					printf("Top : %d\n", top());
					break;
			case -1 : 
					return 0;
		}
	}

}