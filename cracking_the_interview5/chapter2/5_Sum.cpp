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

void insert(Node* &head, Node* &tail, int data){
	Node* node = new Node(data);
	if(head == NULL){
		head = node;
		tail = node;
	}else{
		tail->next = node;
		tail = tail->next;
	}
}

Node* sumList(Node* head1, Node* head2){
	// if(!head1) return head2;
	// if(!head2) return head1;
	int carry = 0, sum = 0;
	Node *head = NULL, *tail = NULL;
	while(head1 && head2){
		sum = head1->data + head2->data + carry;
		if(sum>9){
			sum = sum - 10;
			carry = 1;
		} else{
			carry = 0;
		}

		insert(head, tail, sum);
		head1 = head1->next;
		head2 = head2->next;
	}

	Node* itr = (head1 != NULL ? head1 : head2);
	while(itr){
		sum = itr->data + carry;
		if(sum>9){
			sum = sum - 10;
			carry = 1;
		} else{
			carry = 0;
		}

		insert(head, tail, sum);
		itr = itr->next;
	}

	if(carry){
		insert(head, tail, 1);
	}

	return head;
}

Node* init(){
	Node *head = NULL;
	int n;
	scanf("%d", &n);
	while(n--){
		int data;
		scanf("%d", &data);
		head = add(head, data);
	}
	return head;
}

int main(){
	Node* head1 = init();
	Node* head2 = init();
	Node* s = sumList(head1, head2);
	print(s);
}