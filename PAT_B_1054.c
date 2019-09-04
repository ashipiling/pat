#include <stdio.h>
#include <string.h>
//比较字符差异
int cmp(char a[][100], char b[], int pos){
    unsigned long length = strlen(a[pos]);
    unsigned long length1 = strlen(b);
    for (int i = 0; i< length; i++){
        if (length > length1 || a[pos][i] != b [i]){
            return 0;
        }
    }
    return 1;
}

int main(){
//输入数据（空格和换行符）扩大字符串大小避免读入错误
    int a; scanf("%d", &a);getchar();
    char ch_list[a][100];
    for (int i =0; i< a-1; i++){
        scanf("%[^ ]",ch_list[i]);
        getchar();
    }
    scanf("%[^\n]",ch_list[a-1]);
//sscanf与sprintf转换
    double num_temp = 10000; char ch_temp[100];
    double sum = 0.0; int cnt = 0;
    for (int i = 0; i< a; i++){
        sscanf (ch_list[i], "%lf" ,&num_temp);
        sprintf (ch_temp, "%.2f", num_temp);
        if (cmp(ch_list, ch_temp, i) == 0 || num_temp >1000 || num_temp < -1000){
            printf("ERROR: %s is not a legal number\n", ch_list[i]);
        }else {
            sum += num_temp;
            cnt++;
        }
    }
//输出cnt=1，s去掉（0的时候却不去除）
    if (cnt == 1){
        printf("The average of %d number is %.2f\n", cnt, sum/cnt);
    }
    else if (cnt > 1){
        printf("The average of %d numbers is %.2f\n", cnt, sum/cnt);
    }else{
        printf("The average of 0 numbers is Undefined\n");
    }
    return 0;
}
