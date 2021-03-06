#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;

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

void printInRange(Node* root, int k1, int k2){
	if(!root) return;
	if(root->val < k1) {
		printInRange(root->right, k1, k2);
	} else if(root->val > k2) {
		printInRange(root->left, k1, k2);
	} else {
		printInRange(root->left, k1, k2);
		printf("%d ", root->val);
		printInRange(root->right, k1, k2);
	}

}

int main(){
	Node* root = init();

	int k1, k2;
	scanf("%d %d", &k1, &k2);

	printInRange(root, k1, k2);
}