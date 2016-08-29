#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>

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

void preorder(Node *root){
	if(root == NULL) return;
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
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

Node* preorderToBST(std::vector<int> &v, int min, int max, int &i){
	if(i >= v.size()) return NULL;
	Node* root = NULL;
	if(v[i] > min && v[i] < max){
		root = new Node(v[i]);
		i++;
		root->left = preorderToBST(v, min, root->val, i);
		root->right = preorderToBST(v, root->val, max, i);
	}
	return root;
}

Node* preorderToBST(vector<int> &v){
	int index = 0;
	return preorderToBST(v, INT_MIN, INT_MAX, index);
}

int main(){
	vector<int> preorderList;
	int n;
	printf("Enter size of tree: ");
	scanf("%d ", &n);
	while(n--){
		int val;
		scanf("%d", &val);
		preorderList.push_back(val);
	}

	Node* root = preorderToBST(preorderList);
	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
}
