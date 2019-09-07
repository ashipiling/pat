#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    int * p = (int *)a; int * q = (int *)b;
    return *p - *q;
}
int main(){
    int cnt = 0;
    int a;scanf("%d", &a);
    int data[100000];
    for (int i = 0; i< 100000; i++){
        data[i] = -1;
    }
    int temp_a, temp_b;
//输入，夫妻关联
    for (int i = 0; i< a; i++){
        scanf("%d %d", &temp_a, &temp_b);
        data[temp_a] = temp_b;
        data[temp_b] = temp_a;
    }
//记录来访人，将没伴侣记录的人直接放入out
    int b; scanf("%d", &b);
    int out[100000];
    int temp_c;
    for (int i = 0; i < b ; i++){
        scanf("%d", &temp_c);
        if (data[temp_c] != -1){
            data[temp_c] = -2 ;
        }else {
            out[cnt] = temp_c ;
            cnt++ ;
        }
    }
//i所在位置的数字！=-2且data[data[i]] != i,表明只来了i所在的数字
    for (int i = 0; i< 100000; i++){
        if (data[i] > -1){
            if (data[data[i]] != i){
                out[cnt] = data[i];
                cnt++;
            }
        }
    }
//排序输出
    qsort(out, cnt, sizeof(out[0]), cmp);
    printf("%d\n", cnt);
    for (int i = 0; i< cnt; i++){
        if (i == 0){
            printf("%05d", out[i]);
        }else {
            printf(" %05d", out[i]);
        }
    }
    return 0;
}
