// Example program
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
    node (int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
typedef struct node node;

void print_level_order_traversal(node* root) {
    queue<node*> q;
    if(root == NULL)
        return;
    q.push(root);
    while(!q.empty()){
        node *front = q.front();
        cout <<front->data<<" ";
        if (front->left !=NULL)
            q.push(front->left);
        if (front->right != NULL)
            q.push(front->right);
        q.pop();
    }
}

int main() 
{ 
    node *root= new node(10);
    root->left= new node(20);
    root->right= new node(30);
    root->left->left= new node(40);
    root->left->right= new node(50);
    root->right->left= new node(60);
    root->right->right= new node(70);
    print_level_order_traversal(root);
    return 0;
} 
