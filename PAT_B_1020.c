#include<stdio.h>
#include <stdlib.h>
//创建struct,题目中是正数而不是正整数
struct MOON{
    double moon;
    double price;
    double ave;
};
//cmp函数判定条件，如果这里返回p->ave - q->ave,将一直返回0；
int cmp(const void *a, const void *b){
    struct MOON *p = (struct MOON *)a;
    struct MOON *q = (struct MOON *)b;
    if (p->ave > q->ave){
        return -1;
    }else if (p->ave < q->ave){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int N, D; scanf("%d %d", &N, &D);
    struct MOON Moon[N];
    double moon_sum = 0.0; double sum = 0.0;
    //输入数据到struct
    for (int i = 0; i< N; i++){
        scanf("%lf", &Moon[i].moon);
    }
    for (int i = 0; i< N; i++){
        scanf("%lf", &Moon[i].price);
        Moon[i].ave = (double)Moon[i].price / Moon[i].moon;
    }
    //降序排序
    qsort(Moon, N, sizeof(Moon[0]), cmp);
    for (int i= 0; i< N; i++){
        if (Moon[i].moon < D-moon_sum){
            sum += Moon[i].price;
            moon_sum += Moon[i].moon;
        }else if (moon_sum < D){
            sum += Moon[i].ave * (D - moon_sum);
            break;
        }
    }
    printf("%.2f", sum);
    return 0;
}
