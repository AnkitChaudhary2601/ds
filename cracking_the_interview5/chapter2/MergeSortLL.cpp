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

// Find middle of LL
Node* findMid(Node *head){
	if(!head) 
		return head;

	Node* slow = head;
	Node* fast = head->next;
	while(fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// Merge sorted LL
Node* merge(Node* head1, Node* head2){
	if(!head1) return head2;
	if(!head2) return head1;

	Node* head = NULL;
	Node* p1 = head1;
	Node* p2 = head2;
	Node* prev = NULL;

	while(p1 && p2){
		if(p1->data < p2->data){
			if(head == NULL)
				head = p1;
			if(prev)
				prev->next = p1;
			prev = p1;
			p1 = p1->next;
			
		} else {
			if(head == NULL)
				head = p2;
			if(prev)
				prev->next = p2;
			prev = p2;
			p2 = p2->next;
		}
	}

	if(p1) prev->next = p1;
	if(p2) prev->next = p2;
	return head;
}

Node* mergeSort(Node *head){
	if(head == NULL || head->next == NULL) return head;
	Node* mid = findMid(head);
	Node* head1 = head;
	Node* head2 = mid->next;
	mid->next = NULL;
	head1 = mergeSort(head1);
	head2 = mergeSort(head2);
	return merge(head1, head2);
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
	head = mergeSort(head);
	print(head);
}