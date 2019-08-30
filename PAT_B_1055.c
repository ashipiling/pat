#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//构建结构体
typedef struct HEIGHT{
    char name[9];
    int height;
}Height;
//构建cmp函数，注意strcmp返回值
int cmp(const void *a, const void *b){
    Height * p = (Height *)a; Height * q = (Height *)b;
    if (p->height != q ->height){
        return p ->height - q ->height;
    }else {
        return strcmp(q->name, p->name);
    }
}

int main(){
    //输入数据并排序
    int N, K; scanf("%d %d", &N, &K); getchar();
    Height stu_height[N];
    for (int i = 0; i< N; i++){
        scanf("%s %d",stu_height[i].name, &stu_height[i].height); getchar();
    }
    qsort(stu_height, N, sizeof(stu_height[0]),cmp);
    
    //将名字输给一个多维数组
    int yushu = N % K; int renshu = N / K;
    char name_sort[K][yushu + renshu+1][9];
    int move, flag;
    int move_final;
    int cnt = N-1;
    for (int i = 0; i< K; i++){
        if (i == 0){
            move = 1;
            for (int j = 1; j<= renshu+yushu; j++){
                if (j %2 != 0){
                    flag = 1;
                }else {
                    flag = -1;
                }
                move_final = move *flag /2;
                move ++;
                strcpy(name_sort[i][(renshu+yushu)/2+1+move_final],stu_height[cnt].name);
                cnt--;
            }
        }else {
            move = 1;
            for (int j = 1; j<= renshu; j++){
                if (j % 2 != 0){
                    flag = 1;
                }else {
                    flag = -1;
                }
                move_final = move *flag /2;
                move ++;
                strcpy(name_sort[i][(renshu)/2+1+move_final], stu_height[cnt].name);
                cnt--;
            }
        }
    }
    
    //输出
    int shouhang =1;
    for (int i = 0; i< K; i++){
        if (i == 0){
            for (int j = 1; j<= renshu+yushu; j++){
                if (shouhang){
                    printf("%s", name_sort[i][j]);
                    shouhang = 0;
                }else {
                    printf(" %s", name_sort[i][j]);
                }
            }
            printf("\n");
        }else {
            shouhang = 1;
            for (int j = 1; j<= renshu; j++){
                if (shouhang){
                    printf("%s", name_sort[i][j]);
                    shouhang = 0;
                }else {
                    printf(" %s", name_sort[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
