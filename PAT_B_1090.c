#include <stdio.h>
#include <stdlib.h>
//cmp函数
int cmp(const void *a, const void *b){
    int *p = (int *)a; int *q = (int *)b;
    return *p - *q;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int list[10001][2] = {0};
    for (int i = 0; i< a; i++){
        scanf("%d %d", &list[i][0], &list[i][1]);
    }
    for (int i = 0; i< b; i++){
        int x; scanf("%d", &x);
        int flag = 1;
        int data[x];
        for (int j = 0; j < x; j++){
            scanf("%d", &data[j]);
        }
        qsort(data,x,sizeof(data[0]),cmp);
        for (int j = 0; j < a; j++){
//依次在货物中二分查找禁忌表中配对的两个物品名称
            if ((bsearch(&list[j][0], data,x, sizeof(data[0]),cmp)) && (bsearch(&list[j][1], data,x, sizeof(data[0]),cmp))){
                printf("No\n");
                flag = 0;
                break;
            }
        }
        if (flag){
            printf("Yes\n");
        }
    }
    return 0;
}
