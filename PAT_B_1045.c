#include <stdio.h>
int main(){
//输入数值
    int a; scanf("%d", &a);
    int data[a];
    for (int i =0; i<a; i++){
        scanf("%d", &data[i]);
    }
//构建右边最小数列
    int max = 0, min = 1000000000;
    int min_list[a];
    for (int i = a-1; i>=0; i--){
        if (data[i]< min){
            min = data[i];
        }
        min_list[i] = min;
    }
//计数
    int cnt = 0, out_list[a];
    for (int i = 0; i< a; i++){
        if (i == a-1){
            if (data[i]> max){
                out_list[cnt] = data[i];
                cnt++;
            }
        }else {
            if (data[i] > max && data[i]< min_list[i+1]){
                out_list[cnt] = data[i];
                cnt++;
            }
            if (data[i]> max){
                max = data[i];
            }
        }
    }
//输出
    int flag = 1;
    printf("%d\n", cnt);
    for (int i = 0; i< cnt; i++){
        if (flag){
            printf("%d", out_list[i]);
            flag = 0;
        }else{
            printf(" %d",out_list[i]);
        }
    }
//额外加一行应对0输出
    printf("\n");
    return 0;
}
