#include <stdio.h>
#include <stdlib.h>
//比较函数
int cmp(const void *a, const void *b){
    int * p= (int *)a; int * q= (int *)b;
    if (*p != *q){
        return *p - *q ;
    }else{
        return 0 ;
    }
}
int main(){
//输入并排序
    int N,p;scanf("%d %d", &N, &p);
    int data[N];
    for (int i = 0; i< N; i++){
        scanf("%d", &data[i]);
    }
    qsort(data, N,sizeof(data[0]),cmp);
//双指针移动
    int max = 0; int cnt = 0;
    int k =0 , l =0;
    while (k < N){
        if ((long long) data[k]> (long long)data[l] *p){
            cnt = k-l;
            if (cnt> max){
                max = cnt;
            }
            l++;
        }else {
            k++;
        }
    }
//最后跳出循环但没有计数的cnt值
    cnt = k - l;
    if (cnt> max){
        max = cnt;
    }
//输出
    printf("%d", max);
    return 0;
}
