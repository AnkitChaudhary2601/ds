#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

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

void preOrder(Node *root){
	if(root == NULL) return;
	printf("%d ", root->val);
	preOrder(root->left);
	preOrder(root->right);
}

Node* arrToBstUtil(vector<int> &v, int low, int high){
	if(low>high) return NULL;
	if(low == high) return new Node(v[low]);
	
	int mid = (low+high)/2;

	Node* root = new Node(v[mid]);
	root->left = arrToBstUtil(v, low, mid-1);
	root->right = arrToBstUtil(v, mid+1, high);
	return root;
}

Node* arrToBst(vector<int> &v){
	if(v.size()==0) return NULL;
	return arrToBstUtil(v, 0, v.size()-1);
}

int main(){
	int n;
	printf("Enter size of sorted array : ");
	scanf("%d", &n);
	std::vector<int> v;
	int val;
	for(int i=0;i<n;i++){
		scanf("%d", &val);
		v.push_back(val);
	}

	Node* root = arrToBst(v);
	preOrder(root);
}
