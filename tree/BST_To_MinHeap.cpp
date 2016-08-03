#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

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

void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void preorder(Node *root){
	if(root == NULL) return;
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
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

// link list node's next is right pointer
void bstToSortedLinkList(Node* root, Node* &prev, Node* &head){
	if(root == NULL) return;
	
	bstToSortedLinkList(root->left, prev, head);
	if(!head)
		head = root;
	if(prev)
		prev->right = root;
	root->left = NULL;
	prev = root;
	bstToSortedLinkList(root->right, prev, head);
}

Node* bstToSortedLinkList(Node *root){
	Node* prev = NULL;
	Node* head = NULL;
	bstToSortedLinkList(root, prev, head);
	return head;
}

void printLinkList(Node* head){
	while(head){
		printf("%d ", head->val);
		head = head->right;
	}
	printf("\n");
}

Node* buildMinHeap(Node* head){
	if(!head) return NULL;

	Node* itr = head->right;
	queue<Node *> q;
	q.push(head);
	while(!q.empty()){
		Node* node = q.front();
		q.pop();

		node->left = itr;
		if(itr){
			q.push(itr);
			itr = itr->right;
		}

		node->right = itr;
		if(itr){
			q.push(itr);
			itr = itr->right;
		}
	}
	return head;
}

Node* bstToMinHeap(Node* root){
	Node* head = bstToSortedLinkList(root);
	printLinkList(head);
	Node* minHeap = buildMinHeap(head);
	printf("\n");
	preorder(minHeap);
	printf("\n");
	inorder(minHeap);
}

int main(){
	Node* root = init();
	bstToMinHeap(root);
}
