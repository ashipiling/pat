#include <stdio.h>
#include <math.h>
#define Max 1002
//必须定义在外部，用于独特判断
int matrix[2 << 24] = {0};
int isUnique(int arr[][Max], int x, int y, int TOL) {
    if (   abs(arr[x][y] - arr[x-1][y-1]) <= TOL
        || abs(arr[x][y] - arr[x][y-1]) <= TOL
        || abs(arr[x][y] - arr[x+1][y-1]) <= TOL
        || abs(arr[x][y] - arr[x-1][y]) <= TOL
        || abs(arr[x][y] - arr[x-1][y+1]) <= TOL
        || abs(arr[x][y] - arr[x][y+1]) <= TOL
        || abs(arr[x][y] - arr[x+1][y+1]) <= TOL
        || abs(arr[x][y] - arr[x+1][y]) <= TOL){
        return 0;
    }
    return 1;
}
int main(){
    int M, N, tol; scanf("%d %d %d", &M, &N, &tol);
//外围包0；
    int data[Max][Max] = {0};
    for (int i = 1; i<= N; i++){
        for (int j = 1; j<= M; j++){
            scanf("%d", &data[i][j]);
            matrix[data[i][j]]++;
        }
    }
    int cnt = 0;int lie, hang; long long color;
    for (int i = 1; i<= N; i++){
        for (int j = 1; j<= M; j++){
            if (matrix[data[i][j]] == 1){
                if (isUnique(data, i, j, tol)){
                    lie = j; hang = i; color = data[i][j];
                    cnt++;
                }
                if (cnt>= 2){
                    break;
                }
            }
        }
    }
//输出
    if (cnt == 1){
        printf("(%d, %d): %lld\n", lie, hang, color);
    }else if (cnt> 1){
        printf("Not Unique\n");
    }else{
        printf("Not Exist\n");
    }
    return 0;
}
