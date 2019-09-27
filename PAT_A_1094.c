#include <stdio.h>
//二维数组记录树
int Tree[101][101] = {0};
int level[101] = {0};
//dfs,到每层计数+1
void dfs(int root,int level_depth){
    level[level_depth] ++;
    for (int i = 0; i< 101; i++){
        if (Tree[root][i]){
            dfs(i ,level_depth+1);
        }
    }
}

int main(){
//建树
    int N, M; scanf("%d %d", &N, &M);
    int tmp_1,tmp_2; int num;
    for (int i =0; i< M; i++){
        scanf("%d %d", &tmp_1, &num);
        for (int j = 0; j< num; j++){
            scanf("%d", &tmp_2);
            Tree[tmp_1][tmp_2] = 1;
        }
    }
//dfs
    dfs(1, 1);
//输出
    int max = 0;
    int max_index = 0;
    for (int i = 0; i< 101; i++){
        if (level[i]> max){
            max = level[i];
            max_index = i;
        }
    }
    printf("%d %d", max, max_index);
    return 0;
}
