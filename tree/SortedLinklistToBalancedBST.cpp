#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct Node {
	int val;
	Node *left;
	Node *right;

	Node(int val){
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int val){
		this->val = val;
		next = NULL;
	}
	/* data */
};

void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

Node *insert(Node *root, int val){
	if (root == NULL) {
		return new Node(val);
	} 
 
 	if (root->val >= val) {
 		root->left = insert(root->left, val);
 	} else {
 		root->right = insert(root->right, val);
 	}
 	
 	return root;
}

Node * init(){
	Node *root = NULL;
	do {
		int val;
		scanf("%d", &val);
		if(val == 0) break;
		root = insert(root, val);
	} while(true);
	return root;
}

ListNode* createLinkList(){
	int n;
	printf("Enter list size : ");
	scanf("%d", &n);

	ListNode *head = NULL;
	ListNode *tail = NULL; 
	int val;
	for(int i=0;i<n;i++){
		scanf("%d", &val);
		if(tail){
			tail->next = new ListNode(val);
			tail = tail->next;
		}else{
			head = new ListNode(val);
			tail = head;
		}
	}
	return head;
}

int size(ListNode* head){
	int n = 0;
	while(head){
		head = head->next;
		n++;
	}
	return n;
}

Node* linklistToBST(ListNode* &head, int n);
Node* linklistToBST(ListNode* head){
	return linklistToBST(head, size(head));
}

Node* linklistToBST(ListNode* &head, int n){
	if(n<=0) return NULL;

	Node* left = linklistToBST(head, n/2);
	Node* root = new Node(head->val);
	root->left = left;
	head = head->next;
	root->right = linklistToBST(head, n - n/2 -1);
	return root;
}

void preOrder(Node* root){
	if(!root) return;
	printf("%d ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}

int main(){
	 ListNode* head = createLinkList();
	 Node* root = linklistToBST(head);
	 inorder(root);
	 printf("\n");
	 preOrder(root);
}
