#include <cstdio>
using namespace std;
//定义全局变量
#define maxn 1000
#define INF 1000000000
int n, m, start, end, Graph[maxn][maxn] = {0}, C[maxn][maxn] = {0};
int d[maxn], c[maxn], flag[maxn], pre[maxn];

void Dijakastra(int s){
//初始化d数组和flag数组
    for (int i = 0; i< maxn; i++){
        flag[i] = 1;
        d[i] = INF;
        c[i] = INF;
        pre[i] = i;
    }
//push_back start位置
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; i++){
        int k = -1;int min = INF;
        for (int j = 0; j< n; j++){
            if (flag[j] && d[j] < min){
                k = j;
                min = d[j];
            }
        }
//如果该条路的位置用完了
        if (k == -1) return;
//标记位点k
        flag[k] = 0;
//加入新的路径并将之前的路径更新
        for (int j = 0; j< n; j++){
            if (flag[j] && Graph[k][j]){
                if(d[k] + Graph[k][j] < d[j]){
                    d[j] = d[k] + Graph[k][j];
                    c[j] = c[k] + C[k][j];
                    pre[j] = k;
                }else if (d[k] + Graph[k][j] == d[j]){
                    if (c[j] > c[k] + C[k][j]){
                        c[j] = c[k] + C[k][j];
                        pre[j] = k;
                    }
                }
            }
        }
    }
}
void DFS(int v){
    if (v == start){
        printf("%d ", v);
        return;
    }
    DFS(pre[v]);
    printf("%d ", v);
}
int main(){
    int city1, city2, dist, cost;
    scanf("%d %d %d %d", &n, &m, &start, &end);
//二维矩阵记录有向图的边权
    for (int i= 0; i< m; i++){
        scanf("%d %d %d %d", &city1, &city2, &dist, &cost);
        Graph[city1][city2] = dist; Graph[city2][city1] = dist;
        C[city1][city2] = cost; C[city2][city1] = cost;
    }
    
    Dijakastra(start);
//输出

    DFS(end);
    printf("%d %d", d[end], c[end]);
    return 0;
}
