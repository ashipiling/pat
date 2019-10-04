#include <cstdio>
#include <vector>
#include <queue>
#define maxn 1010
using namespace std;

struct NODE{
    int id;
    int layer;
};
//用vector存放边
vector<struct NODE> list[maxn];
//判断是否循环过
int flag[maxn] = {1};
//queue来协助BFS
int BFS(int root, int L){
    queue<struct NODE> q;
    int out = 0;
    struct NODE start;
    start.id = root;start.layer = 0;
    q.push(start);
    flag[start.id] = 0;
    while (!q.empty()){
        struct NODE top = q.front();
        q.pop();
        for (int i = 0; i< list[top.id].size(); i++){
            if (flag[list[top.id][i].id] && top.layer < L){
                list[top.id][i].layer = top.layer+1;
                q.push(list[top.id][i]);
                flag[list[top.id][i].id] = 0;
                out++;
            }
        }
    }
    return out;
}

int main(){
    struct NODE Node;
    int tmp1, tmp2;
    int N,L; scanf("%d %d", &N, &L);
    for (int i = 1; i<= N; i++){
        Node.id = i;
        scanf("%d", &tmp1);
        for (int j =0; j< tmp1; j++){
            scanf("%d", &tmp2);
//前后顺序问题
            list[tmp2].push_back(Node);
        }
    }
    int query_num; scanf("%d", &query_num);
    int query_tmp, out;
    for(int i = 0; i< query_num; i++){
        scanf("%d", &query_tmp);
//每次讲flag数列归位
        for (int j = 0;j< maxn; j++){
            flag[j] = 1;
        }
        out = BFS(query_tmp, L);
        printf("%d\n", out);
    }
    return 0;
}