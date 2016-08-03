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

Node* init(){
	Node *root = NULL;
	do {
		int val;
		scanf("%d", &val);
		if(val == 0) break;
		root = insert(root, val);
	} while(true);
	return root;
}

Node* find(Node *root, int val){
	if(root == NULL) return NULL;
	if(root->val == val) return root;
	if(root->val > val) return find(root->left, val);
	return find(root->right, val); 
}

Node* smallestNode(Node *root){
	if(root){
		while(root->left)
			root = root->left;
	}
	return root;
}
Node* inorderSuccessor(Node *root, Node* node){
	if(root == NULL || node == NULL) return NULL;

	if(node->right){
		return smallestNode(node->right);
	}

	Node *itr = root;
	Node *ans = NULL;
	while(itr != node){
		if(itr->val > node->val){
			ans = itr;
			itr = itr->left;
		}
		else if(itr->val < node->val){
			itr = itr->right;
		}
	}

	return ans;
}

int main(){
	Node *root = init();
	int val;
	scanf("%d", &val);
	Node* ans = inorderSuccessor(root, find(root, val));
	printf("%d\n", ans!=NULL ? ans->val : -1);
}