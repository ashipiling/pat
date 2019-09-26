#include <stdio.h>
#include <stdlib.h>
int in_list[1000], post_list[1000];
//树的结构
struct NODE{
    int data;
    struct NODE *left;
    struct NODE *right;
};
//先序建树
struct NODE * Create(int postL, int postR, int inL, int inR){
    int k;
//跳出的条件，没有数值
    if (postL > postR){
        return NULL;
    }
    struct NODE *p = (struct NODE *)malloc(sizeof(struct NODE));
    p->data = post_list[postR];
//中序中找到后序的根
    for (k = inL; k <= inR; k++ ){
        if (in_list[k] == post_list[postR]){
            break;
        }
    }
//递归
    p->left = Create(postL, postL+(k-inL)-1, inL, k-1);
    p->right = Create(postL+(k-inL), postR-1, k+1, inR);
    return p;
}
//层序输出
void LOT(struct NODE *p){
    int flag = 1;
    struct NODE* queue[1000];
    int pre = 0, post = 1;
    queue[0] = p;
    while (1){
        if (pre == post){
            break;
        }
        if (flag){
            printf("%d", queue[pre]->data);
            flag = 0;
        }else {
            printf(" %d", queue[pre]->data);
        }
        if (queue[pre]->left){
            queue[post] = queue[pre]->left; post ++;
        }if (queue[pre]->right){
            queue[post] = queue[pre]->right; post ++;
        }
        pre++;
    }
}
int main(){
    int a; scanf("%d", &a);
    for (int i =0 ; i< a; i++){
        scanf("%d", &post_list[i]);
    }for (int i =0 ; i< a; i++){
        scanf("%d", &in_list[i]);
    }
    struct NODE *p = Create(0, a-1, 0, a-1);
    LOT(p);
    return 0;
}
