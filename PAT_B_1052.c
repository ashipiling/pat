#include <stdio.h>
int main(){
    char hand[10][5], eye[10][5], mouth[10][5];
    char temp;temp = getchar();
    int cnt_1 = 0; int cnt2 = 0;
    while(temp != '\n'){
        if (temp == '['){
            scanf("%[^]]", hand[cnt_1]);
            cnt_1++;
        }
        temp = getchar();
    }
    
    temp = getchar();int cnt_2 = 0;
    while(temp != '\n'){
        if (temp == '['){
            scanf("%[^]]", eye[cnt_2]);
            cnt_2++;
        }
        temp = getchar();
    }
    temp = getchar();int cnt_3= 0;
    while(temp != '\n'){
        if (temp == '['){
            scanf("%[^]]", mouth[cnt_3]);
            cnt_3++;
        }
        temp = getchar();
    }
    //输入要求
    int a; scanf("%d", &a);
    int out_list[a][5];
    for (int i = 0; i< a; i++){
        for (int j= 0; j< 5; j++){
            scanf("%d", &out_list[i][j]);
        }
    }
    //输出
    for (int i = 0; i< a; i++){
        if (out_list[i][0] > cnt_1 || out_list[i][1] > cnt_2|| out_list[i][2] > cnt_3 || out_list[i][3]> cnt_2 || out_list[i][4] > cnt_1|| out_list[i][0] <= 0 || out_list[i][1] <= 0 || out_list[i][2] <= 0 || out_list[i][3] <= 0 || out_list[i][4] <= 0){
            printf("Are you kidding me? @\\/@\n");
        }else{
            printf("%s(%s%s%s)%s\n", hand[out_list[i][0]-1], eye[out_list[i][1]-1],mouth[out_list[i][2]-1], eye[out_list[i][3]-1], hand[out_list[i][4]-1]);
        }
    }
    
    return 0;
}
