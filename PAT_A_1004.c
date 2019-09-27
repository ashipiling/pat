#include <stdio.h>
//二维数组记录树
int Tree[101][101] = {0};
int level[101] = {0};
int max_depth = 0;
//dfs,记录每层的叶子树木
void dfs(int root,int level_depth){
//记录最大深度
    if (max_depth < level_depth){
        max_depth = level_depth;
    }
    int flag = 1;
    for (int i = 0; i< 101; i++){
        if (Tree[root][i]){
            flag = 0;
            dfs(i ,level_depth+1);
        }
    }
    if (flag){
        level[level_depth]++;
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
    int flag = 1;
    for (int i = 1; i<= max_depth; i++){
        if (flag){
            printf("%d", level[i]);
            flag = 0;
        }else {
            printf(" %d", level[i]);
        }
    }
    return 0;
}
