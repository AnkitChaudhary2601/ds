#include<cstdio>
#include<vector>
#include<stack>

using namespace std;

struct Tower{
	stack<int> s;
	int index;
	Tower(int i){
		index = i;
	}

	void push(int val){
		if(s.size()==0){
			printf("Pushing %d on tower %d\n", val, index);
			s.push(val);
		} else {
			if(s.top() < val){
				printf("Error, pushing %d over %d on tower %d\n", val, s.top(), index);
			} else {
				printf("Pushing %d over %d on tower %d\n", val, s.top(), index);
				s.push(val);
			}
		}		
	}

	void pop(){
		if(s.size() ==0 ){
			printf("Error, tower %d is empty, cannot pop\n", index);
		} else {
			s.pop();
		}
	}

	int top(){
		if(s.size() ==0 ){
			printf("Error, tower %d is empty, cannot get top\n", index);
		} 
		return s.top();
	}

	bool isEmpty(){
		return s.size() == 0;
	}
};

void moveDisks(int n, Tower &origin, Tower &destination, Tower &buffer){
	if(n<=0) return;
	moveDisks(n-1, origin, buffer, destination);
	destination.push(origin.top());
 	origin.pop();
 	moveDisks(n-1, buffer, destination, origin);
}

void printTower(Tower &t){
	while(!t.isEmpty()){
		printf("%d ", t.top());
		t.pop();
	}
	printf("\n");
}

int main(){
	Tower t1(1);
	Tower t2(2);
	Tower t3(3);
	int n;
	scanf("%d", &n);
	for(int i=n; i>0; i--)
		t1.push(i);
	moveDisks(n, t1, t2, t3);

	printTower(t2);
}
