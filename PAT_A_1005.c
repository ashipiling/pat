#include <stdio.h>
#include <string.h>
#define Max 1001
char zimu[10][11] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    char ch[Max]; gets(ch); unsigned long length = strlen(ch);
    int sum = 0;
    for (int i = 0; i< length; i++){
        sum = sum + (ch[i]-'0');
    }

//特殊处理数字0并输出
    if (sum == 0){
        printf("zero");
    }else {
        char out[10]; int tmp;int cnt = 0, flag =1;
        while (sum != 0){
            tmp = sum % 10;
            sum = sum /10;
            out[cnt] = tmp;
            cnt++;
        }
        for (int i = cnt-1; i >= 0;i-- ){
            if (flag){
                printf("%s",zimu[out[i]]);
                flag = 0;
            }else{
                printf(" %s",zimu[out[i]]);
            }
            
        }
    }
    return 0;
}
