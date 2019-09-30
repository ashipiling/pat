#include <stdio.h>
#include <stdlib.h>
int CBT[1000];
int data[1000];
int Index = 0;
int n;
int cmp(const void *a, const void *b){
    int *p = (int *)a; int *q = (int *)b;
    if (*p != *q){
        return *p - *q;
    }else {
        return 0;
    }
}
//用数组来储存完全搜索二叉树
void cbt(int root){
    if (root > n){
        return;
    }
    cbt(2*root);
    CBT[root] = data[Index];
    Index++;
    cbt(2*root+1);
}
int main(){
    scanf("%d", &n);
    for (int i = 0; i< n ; i++){
        scanf("%d", &data[i]);
    }
    qsort(data, n, sizeof(data[0]), cmp);
    cbt(1);
//直接输出即为层序排序
    int flag = 1;
    for (int i = 1; i<= n; i++){
        if (flag){
            printf("%d", CBT[i]);
            flag = 0;
        }else {
            printf(" %d", CBT[i]);
        }
    }
    return 0;
}
