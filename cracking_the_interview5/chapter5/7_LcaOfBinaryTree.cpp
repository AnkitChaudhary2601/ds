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

Node* search(Node* root, int val){
	if(root == NULL) return NULL;
	if(root->val == val) return root;
	
	Node* result = search(root->left, val);
	if(result != NULL) return result;

	return search(root->right, val);
}

Node* lca(Node* root, int n1, int n2, int& found){
	if(root == NULL) return NULL;
	
	if(root->val == n1){ 
		if(search(root, n2) != NULL) return root;
		found = 1;
		return NULL;
	}

	if(root->val == n2){
	 	if(search(root, n1) != NULL) return root;
		found = 2;
		return NULL;
	}

	Node* result = lca(root->left, n1, n2, found);
	if(result != NULL) return result;

	if(found == 1){
		if(search(root->right, n2) != NULL) return root;
		return NULL;
	}

	if(found == 2){
		if(search(root->right, n1) != NULL) return root;
		return NULL;
	}

	return lca(root->right, n1, n2, found);
}

Node* lca(Node* root, int n1, int n2){
	int found = 0;	
	return lca(root, n1, n2, found);
}

int main(){
	Node* root = init();
	while(true){
		printf("Enter nodes for LCA: ");
		int val1, val2;
		scanf("%d %d", &val1, &val2);
		if(val1 == 0 || val2 == 0) break;
		Node* node = lca(root, val1, val2);
		printf("Lca : %d\n", node!=NULL?node->val:-1);
	}
}
