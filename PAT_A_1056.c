#include<stdio.h>
//创建结构体包含重量和排级
struct MICE{
    int weight;
    int rank;
};
int main(){
//输入
    int Np, Ng; scanf("%d %d", &Np, &Ng);
    struct MICE Mice[Np];
    int order[Np], tmp[Np];
    for (int i =0 ; i< Np; i++){
        scanf("%d", &Mice[i].weight);
    }
    for (int i = 0; i< Np; i++){
        scanf("%d", &order[i]);
    }
    int group, max,num, move;
    int Np_2= Np;
    while (1){
//分组，不足ng也分一组
        group = (Np + Ng -1) / Ng;
        move = 0;
//分组迭代查找组内最大值并用临时数组记录最大值的编号
        for (int i = 0; i< group; i++){
            max = -1;
            for (int j = i * Ng; j< i * Ng+Ng && j<Np; j++){
                Mice[order[j]].rank = group +1;
                if (Mice[order[j]].weight > max){
                    max = Mice[order[j]].weight;
                    num = order[j];
                }
            }
            tmp[move] = num;
            move ++;
        }
//把临时数组内容给order数组进行下一轮循环，并更改总数Np
        for (int i = 0; i< move; i++){
            order[i] = tmp[i];
        }
        Np = group;
//跳出循环
        if (Np == 1){
            Mice[tmp[0]].rank = 1;
            break;
        }
    }
//输出
    int flag = 1;
    for (int i = 0; i< Np_2; i++){
        if (flag){
            printf("%d", Mice[i].rank);
            flag = 0;
        }else {
            printf(" %d", Mice[i].rank);
        }
        
    }
    return 0;
}
