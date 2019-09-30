#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};
int n;
vector<int> tree, pre, post;
void dfs(node *root, int v){
    if(root->val <= v){
        if(root->right==NULL){
            root->right = new node(v);
            return;
        } else{
            dfs(root->right, v);
        }
    } else{
        if(root->left==NULL){
            root->left = new node(v);
            return;
        } else{
            dfs(root->left, v);
        }
    }
}
void dfsmi(node *root, int v){
    if(root->val <= v){
        if(root->left==NULL){
            root->left = new node(v);
            return;
        } else{
            dfsmi(root->left, v);
        }
    } else{
        if(root->right == NULL){
            root->right = new node(v);
            return; 
        } else{
            dfsmi(root->right, v);
        }
    }
}
void preorder(node *root){
    if(root!=NULL){
        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    } else{
        return;
    }
}
void postorder(node *root){
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->val);
}
int main(){
    scanf("%d", &n);
    tree.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d", &tree[i]);
    }
    node *root = new node(tree[0]);
    if(tree[0]>tree[1]){
        for(int i=1;i<n;i++)    dfs(root, tree[i]);
    } else {
        for(int i=1;i<n;i++)    dfsmi(root, tree[i]);
    }
    preorder(root);
    for(int i=0;i<n;i++){
        if(tree[i]!=pre[i]){
            printf("NO");
            return 0;
        }
    }
    postorder(root);
    printf("YES\n%d", post[0]);
    for(int i=1;i<n;i++)    printf(" %d", post[i]);
    return 0;
} 