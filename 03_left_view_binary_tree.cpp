// https://ideone.com/NzJ67Z
// int &max_level -- should be called by reference. Its a variable passed from main and should be incremented. second call for right subtree sould get incremented value of max_level.

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};


typedef struct node node;

void leftView(node *root, int level, int &max_level){
	if(root==NULL) return;
	else {
		if(max_level < level)
		    //cout <<level << endl;
		    //cout <<max_level << endl;
			cout << root->data << endl;
			max_level = level;
	}
	leftView(root->left, level+1, max_level);
	leftView(root->right, level+1, max_level);
}

int main() {
	// your code goes here
	node *root = new node(10);
	root->left = new node(20);
	root->right = new node(30);
	root->left->left = new node(40);
	root->left->right = new node(50);
	root->left->right->right = new node(60);
	root->left->right->right->left = new node(70);
	root->left->right->right->left->right = new node(80);
	int level = 1;
	int max_level = 0;
	leftView(root, level, max_level);
	return 0;
}