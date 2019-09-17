#include <stdio.h>
int N, M, K;

void DFS(int v, int lostcity[], int way[][1001]){
//遍历过程中将访问过的城市标记
    lostcity[v] = 1;
    for(int i = 0; i <= N; i++)
        if(way[v][i] && way[i][v] && lostcity[i]==0)
            DFS(i, lostcity, way);
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
//二维表记录图
    int way[1001][1001] = {0};
    int city1, city2;
    for(int i = 0; i < M; i++){
        scanf("%d %d", &city1, &city2);
        way[city1][city2] = 1; way[city2][city1] = 1;
    }
    
    for(int i = 0; i < K; i++){
//在for内部初始化城市访问表
        int lostcity[1001] = {0}, tmp, count = 0;
        scanf("%d", &tmp);
        lostcity[tmp] = 1;
        for(int k = 1; k <= N; k++){
//lostcity表会因dfs访问而变化
            if(lostcity[k] == 0){
                DFS(k, lostcity, way);
                count++;
            }
        }
//剩下的城市如果能够一条路走通即代表需要补充0条路
        printf("%d\n", count - 1);
    }
    return 0;
}
