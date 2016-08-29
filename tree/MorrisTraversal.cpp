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

void morrisInorderTraversal(Node* root){
	while(root){
		if(root->left == NULL){
			printf("%d ", root->val);
			root = root->right;
		} else {
			Node* precessor = root->left;
			while(precessor->right != NULL && precessor->right != root){
				precessor = precessor->right;
			}

			if(precessor->right == NULL){
				precessor->right = root;
				root = root->left;
			} else {
				precessor->right = NULL;
				printf("%d ", root->val);
				root = root->right;
			}
		}
	}
}

int main(){
	Node* root = init();
	morrisInorderTraversal(root);
}
