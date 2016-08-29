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

int max(int a, int b){
	return a>b?a:b;
}

int isBalancedUtil(Node* root){
	if(!root) return 0;
	int lh = isBalancedUtil(root->left);
	if(lh<0) return lh;
	int rh = isBalancedUtil(root->right);
	if(rh<0) return rh;

	if(lh-rh>1 || rh-lh>1) return -1;
	return max(lh, rh)+1;
}

bool isBalanced(Node* root){
	return isBalancedUtil(root) >= 0;
}

int main(){
	Node* root = init();
	printf("%s\n", isBalanced(root) ? "Yes" : "No");
}
