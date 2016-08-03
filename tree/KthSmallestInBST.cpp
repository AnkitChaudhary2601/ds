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

Node* kthSmallest(Node *root, int &k){
	if(!root) return NULL;
	Node* tmp = kthSmallest(root->left, k);
	if(tmp) return tmp;
	if(--k == 0) return root;
	return kthSmallest(root->right, k);
}

int main(){
	Node *root = init();
	int k;
	scanf("%d", &k);
	Node* ans = kthSmallest(root, k);
	printf("%d\n", ans!=NULL ? ans->val : -1);
	return 0;
}
