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

Node* kthToLast(Node *head, int k){
	if(k<=0) return NULL;

	Node *tmp = head;

	for(int i=0; i<k-1; i++){
		if(tmp == NULL) return NULL;
		tmp = tmp->next;
	}

	if(tmp == NULL) return NULL;

	while(tmp->next){
		head = head->next;
		tmp = tmp->next;
	}

	return head;
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
	int k;
	scanf("%d", &k);
	Node* kth = kthToLast(head, k);
	printf("%d\n", kth!=NULL ? kth->data : -1);
}