#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>

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

void pushLeftNodes(stack<Node*> &s, Node* root){
	while(root){
		s.push(root);
		root = root->left;
	}
}

Node* getNextInorderSuccessor(stack<Node*> &s){
	if(s.empty()) return NULL;
	
	Node* curr = s.top()->right;
	s.pop();
	pushLeftNodes(s, curr);
	
	if(s.empty()) return NULL;

	return s.top();
}

void commonNodes(Node* root1, Node* root2){
	if(root1 == NULL || root2 == NULL)
		return;

	stack<Node*> s1;
	stack<Node*> s2;

	pushLeftNodes(s1, root1);
	pushLeftNodes(s2, root2);

	root1 = s1.top();
	root2 = s2.top();
	
	while(root1 && root2){
		if(root1->val == root2->val){
			printf("%d ", root1->val);
			root1 = getNextInorderSuccessor(s1);
			root2 = getNextInorderSuccessor(s2);
		}
		else if(root1->val < root2->val){
			root1 = getNextInorderSuccessor(s1);
		} else {
			root2 = getNextInorderSuccessor(s2);
		}
	}
 }

int main(){
	Node* root1 = init();
	Node* root2 = init();
	commonNodes(root1, root2);
}
