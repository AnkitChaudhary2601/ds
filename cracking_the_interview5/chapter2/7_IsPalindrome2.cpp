#include<cstdio>
#include<cstdlib>	
#include<utility>

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

int length(Node* head){
	int n = 0;
	while(head){
		head = head->next;
		n++;
	}
	return n;
}

pair<Node*, bool> isPalindrome(Node* head, int length){
	if(length==0){
		return make_pair<Node*, bool>(head, true);
	}
	
	if(length==1){
		return make_pair<Node*, bool>(head->next, true);
	}
	
	pair<Node*, bool> p = isPalindrome(head->next, length-2);
	if(p.second == false || (p.first)->data != head->data) {
		p.second = false;
		return p;
	}
	
	p.first = p.first->next;
	return p;
}

bool isPalindrome(Node* head){
	if(head==NULL || head->next==NULL)
		return true;

	pair<Node*, bool> p = isPalindrome(head, length(head));
	return p.second;
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