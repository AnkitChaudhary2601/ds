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
	Node *root = new Node(5);
	root->left = new Node(2);
	root->right = new Node(4);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	return root;
}

int getLargestBSTSize(Node* root, int &min, int &max, bool &isBst){
	if(!root) {
		isBst = true;
		return 0;
	}

	if(root->left && root->right) {
		int left = getLargestBSTSize(root->left, min, max, isBst);
		int leftMin = min;
		int leftMax = max;
		bool isLeftBst = isBst;

		int right = getLargestBSTSize(root->right, min, max, isBst);

		if(isLeftBst && isBst && root->val > leftMax && root->val < min){
			min = leftMin;
			return left+right+1;
		} else {
			isBst = false;
			return left > right ? left : right;
		}
	}

	if(root->left) {
		int left = getLargestBSTSize(root->left, min, max, isBst);
		if(isBst && root->val > max){
			max = root->val;
			return left + 1;
		} else{
			isBst = false;
			return left;
		}
	}

	if(root -> right){
		int right = getLargestBSTSize(root->right, min, max, isBst);
		if(isBst && root->val < min){
			min = root->val;
			return right+1;
		} else{
			isBst = false;
			return right;
		}
	}
	
	min = max = root->val;
	isBst = true;
	return 1;
}

int main(){
	Node* root = init();
	int min = INT_MIN;
	int max = INT_MAX;
	bool isBst = true;
	printf("%d\n", getLargestBSTSize(root, min, max, isBst));
}
