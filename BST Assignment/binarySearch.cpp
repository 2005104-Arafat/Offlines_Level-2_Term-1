#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};      
Node* Insert(Node* &root, int val){
    if (root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=Insert(root->left,val);
    }else{
        root->right=Insert(root->right,val);
    }
    return root;
}

bool Find(Node* root, int value){
    if(root==NULL){
        return false;
    }
    if(root->data==value){
        return true;
    }
    else if(value > root->data){
        return Find(root->right,value);
    }
    else if(value<root->data){
        return Find(root->left,value);
    }
}
void PreOrder(Node* root,ofstream &output){
    if(root==NULL){
        return;
    }
    output<<root->data<<" ";
    PreOrder(root->left,output);
    PreOrder(root->right,output);
}
void InOrder(Node* root, ofstream & output){
    if(root==NULL){
        return;
    }
    InOrder(root->left,output);
    cout<<root->data<<" ";
    InOrder(root->right,output);
}
void PostOrder(Node* root,ofstream & output){
    if(root==NULL){
        return;
    }
    PostOrder(root->left,output);
    PostOrder(root->right,output);
    output<<root->data<<" ";
}
Node* Delete(Node* root, int value){
    if(root==NULL){
        return NULL;
    }
    root->left=Delete(root->left,value);
    root->right=Delete(root->right,value);
    if(root->data==value && root->left==NULL && root->right==NULL){
        delete(root);
        return NULL;
    }
    return root;
}
void print(Node* root, string &str){
    if (root == NULL){
        return;
    }
    str=str+to_string(root->data);
    if (!root->left && !root->right){
        return;
    }
    str=str+"(";
    print(root->left, str);
    str=str+")";
    str=str+"(";
    print(root->right, str);
    str=str+")";  
}
