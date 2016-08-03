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

int diameter(Node *root, int &height){
	if(root == NULL) {
		height = 0;
		return 0;
	}

	int lheight = 0;
	int ld = diameter(root->left, lheight);
	int rheight = 0;
	int rd = diameter(root->right, rheight);

	height = max(lheight, rheight) + 1;
	return max(max(ld, rd), lheight + rheight + 1);  
}

int diameter(Node *root){
	if(root == NULL) return 0;
	int height = 0;
	return diameter(root, height);
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

int main(){
	Node *root = NULL;
	do {
		int val;
		scanf("%d", &val);
		if(val == 0) break;
		root = insert(root, val);
	} while(true);

	int d = diameter(root);
	printf("%d\n", d);
}