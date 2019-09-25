#include <stdio.h>
int main(){
    int M, N ,K; scanf("%d %d %d", &M, &N, &K);
    int stack[1000], data[1000];
    for (int i = 0; i< K; i++){
        int top = 0;
        int move = 0;
        int flag = 1;
        for (int j = 0; j< N; j++){
            scanf("%d", &data[j]);
        }
        for (int j = 1; j<= N; j++){
            top++;
            stack[top] = j;
            if (top > M){
                flag = 0;
                break;
            }
            while(top > 0 && stack[top] == data[move]){
                top --;
                move ++;
            }
        }
        if (top == 0 && flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
