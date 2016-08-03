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


// partition around x
Node* partition(Node* head, int x){
	if(head == NULL || head->next == NULL)
		return head;

	Node* head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;
	while(head){
		if(head->data < x){
			if(head1 == NULL){
				head1 = head;
				tail1 = head;
			}else{
				tail1->next = head;
				tail1 = tail1->next;
			}
		}else{
			if(head2 == NULL){
				head2 = head;
				tail2 = head;
			}else{
				tail2->next = head;
				tail2 = tail2->next;
			}
		}
		head = head->next;
	}

	if(head1 == NULL)
		return head2;

	if(tail2)
		tail2->next = NULL;

	tail1->next = head2;
	return head1;
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
	int x;
	scanf("%d", &x);
	head = partition(head, x);
	print(head);
}