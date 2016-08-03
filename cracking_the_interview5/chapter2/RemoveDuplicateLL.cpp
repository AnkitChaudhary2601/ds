#include<cstdio>
#include<cstdlib>
#include<set>

using namespace std;

struct Node{
	Node* next;
	int data;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

void removeDuplicates(Node* head){
	if(!head) 
		return;

	set<int> s;

	Node* prev = NULL;
	Node* cur = head;
	while(cur){
		if(s.find(cur->data) != s.end()) {
			prev->next = cur->next;
			cur->next = NULL;
			free(cur);
			cur = prev->next; 
		} else {
			s.insert(cur->data);
			prev = cur;
			cur = cur->next;
		}
	}
}

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
	removeDuplicates(head);
	print(head);
}

