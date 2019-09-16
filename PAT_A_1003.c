#include<stdio.h>

//初始化一堆东西,初始在外面，方便函数调用
int n, m, c1, c2;
int save_list[1000], way[1000][1000] = {0};
int path_num =0, min_length = 10000000, num_max = 0;
//flag避免死循环
int flag[1000] = {0};

//dfs深度搜索
void dfs(int c1, int path_length,int save_num) {
//跳出条件
    if (c1 == c2){
        if (path_length < min_length){
            min_length = path_length;
            path_num =1;
            num_max = save_num;
        }else if(path_length == min_length){
            path_num++;
            if (num_max < save_num){
                num_max = save_num;
            }
        }
        return ;
    }
//剪枝
    if (path_length > min_length){
        return ;
    }
//减少时间浪费
    flag[c1] = 1;
    for (int i = 0; i< n; i++){
        if (i != c1){
            if (way[c1][i] && flag[i] == 0){
                flag[i] = 1;
//length和num在函数中增加
                dfs(i, path_length+way[c1][i], save_num + save_list[i]);
                flag[i] = 0;
            }
        }
    }
}
int main(){
//创建二维数组来储存图，a[i][j] = a[j][i]
    int tmp_1, tmp_2;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for (int i = 0; i< n; i++){
        scanf("%d", &save_list[i]);
    }
    for (int i = 0; i< m; i++){
        scanf("%d %d", &tmp_1, &tmp_2);
        scanf("%d", &way[tmp_1][tmp_2]);
        way[tmp_2][tmp_1] = way[tmp_1][tmp_2];
    }
    
    dfs(c1, 0, save_list[c1]);
//输出
    printf("%d %d", path_num, num_max);
    return 0;
}
