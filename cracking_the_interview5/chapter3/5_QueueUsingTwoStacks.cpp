#include<cstdio>
#include<stack>

using namespace std;

stack<int> stackNewest; //top will contain newest element
stack<int> stackOldest; //top will contain oldest element

/*
In this approach, stackNewest has the newest elements on top and stackOldest has the oldest elements on top. 
When we dequeue an element, we want to remove the oldest element first, and so we dequeue from stackOldest. 
If stackOldest is empty, then we want to transfer all elements from stackNewest into this stack in reverse order.
To insert an element, we push onto stackNewest, since it has the newest elements on top.
*/

void push(int val){
	stackNewest.push(val);
}

void shiftStack(){
	if(stackOldest.empty()){
		while(!stackNewest.empty()){
			stackOldest.push(stackNewest.top());
			stackNewest.pop();
		}
	}
}

void pop(){
	shiftStack();
	stackOldest.pop();
}

int peek(){
	shiftStack();
	return stackOldest.top();
}

int main(){
	int op, val;
 	bool flag = true;
	while(flag){
		scanf("%d",&op);
		switch(op){
			case 0 : flag = false;
				break;
			case 1 : 
				scanf("%d", &val);
				push(val);
				break;
			case 2 :
				pop();
				break;
			case 3 : 
				printf("%d\n", peek());
				break;
		}
	}
}