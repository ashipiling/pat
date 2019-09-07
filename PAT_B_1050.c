#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//寻找到符合要求的M和N
void define(int *p, int *q, int N){
    int diff = N; int i, j;
    for (i = N; i>= sqrt(N) ; i--){
        if (N % i == 0){
            j = N/i;
            if (i -j < diff){
                diff = i - j;
                *p = i; *q = j;
            }
        }
    }
}

int cmp(const void *a, const void *b){
    int *p = (int *)a; int *q = (int *)b;
    if (*p != * q){
        return *q - *p;
    }else {return 0;}
}
int main(){
    int N; scanf("%d", &N); int data[N];
    for (int i = 0; i< N; i++){
        scanf("%d", &data[i]);}
//数组排序
    qsort(data, N, sizeof(data[0]), cmp);
    
    int m ,n;
    define(&m, &n, N);
//    printf("%d %d\n", m, n);
//二维矩阵循环
    int matrix[m][n]; int k = 0; int cnt = 0; int i = 0, j = 0;
//k< n/2??
    for (k = 0; k <= n/2; k++){
        if (cnt != N){
            for (j = k;j< n-k; j++){
                matrix[k][j] = data[cnt];
//               printf("1%d ",data[cnt]);
                cnt++;
            }
        }if (cnt != N){
            for (i = k+1; i< m-k; i++){
                matrix[i][n-k-1] = data[cnt];
                cnt++;
            }
        }if (cnt != N){
            for (j = n- k-2; j>= k; j--){
                matrix[m-k-1][j] = data[cnt];
                cnt++;
            }
        }if (cnt != N){
            for (i = m -k-2; i>= k+1; i--){
                matrix[i][k] = data[cnt];
                cnt++;
            }
        }
    }
//输出
    for (int a = 0; a< m; a++){
        for (int b = 0; b< n; b++){
            if (b== 0){
                printf("%d",matrix[a][b]);
            }else{
                printf(" %d",matrix[a][b]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
