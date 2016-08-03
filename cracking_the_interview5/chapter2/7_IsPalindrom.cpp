#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node{
	Node* next;
	int data;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

Node *add(Node * head, int data){
	Node *node = new Node(data);
	if(head == NULL)
		return node;

	Node *cur = head;
	while(cur->next){
		cur = cur->next;
	}
	cur->next = node;

	return head;
}

void print(Node *head){
	while(head){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

bool isPalindrome(Node* &front, Node* rear){
	if(rear == NULL)
		return true;

	bool flag = isPalindrome(front, rear->next);
	if(flag == false || front->data != rear->data)
		return false;

	front = front->next;
	return true;
}

bool isPalindrome(Node* head){
	if(head==NULL || head->next==NULL)
		return true;

	Node* front = head;
	Node* rear = head;
	return isPalindrome(front, rear);
}


int main(){
	Node *head = NULL;
	int n;
	scanf("%d", &n);
	while(n--){
		int data;
		scanf("%d", &data);
		head = add(head, data);
	}
	print(head);
	bool flag = isPalindrome(head);
	printf("%d\n", flag);
}