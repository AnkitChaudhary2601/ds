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


bool isBST(Node *root, Node* &prev){
	if(root == NULL) return true;
	
	
	if(isBST(root->left, prev) == false)
		return false;
	
	printf("%d %d\n", root->val, prev!=NULL ? prev->val : -1);
	if(prev != NULL && root->val <= prev->val)
		return false;	

	prev = root;
	return isBST(root->right, prev);

}

bool isBST(Node *root){
	Node *prev = NULL;
	return isBST(root, prev);
}

int main(){
	Node *root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(4);
	inorder(root);
	printf("%d\n", isBST(root));
}
