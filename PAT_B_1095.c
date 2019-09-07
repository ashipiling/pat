#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct DATA{
    char id[20]; int room; int time; int students; int score;
};
struct TIME{
    int k; int l;
};
//字符串数字转换
int toroom(char *ch){
    int temp = 0;
    for (int i = 1; i<=3; i++){
        temp= temp *10 + (ch[i]- '0');
    }
    return temp;
}
int totime(char *ch){
    int temp = 0;
    for (int i = 4; i <= 9; i++){
        temp= temp *10 + (ch[i]- '0');
    }
    return temp;
}
//构建两个cmp函数
int cmp(const void *a, const void *b){
    struct DATA * p = (struct DATA *)a; struct DATA * q = (struct DATA *)b;
    if (p ->score != q ->score){ return (q->score - p ->score);}
        else if(strcmp(p->id, q->id) !=0 ){
            return (strcmp(p->id, q->id));
        }else{ return 0;}
}
int cmp_time(const void *a, const void *b){
    struct TIME * p = (struct TIME *)a; struct TIME * q = (struct TIME *)b;
    if (p->l != q->l){
        return q->l - p->l; }
    else if (p->k != q->k){
        return p->k - q->k; }
    else{return 0;}
}

int main(){
//输入，转化，并排序
    int N, M; scanf("%d %d", &N, &M);getchar();
    struct DATA Data[N];
    for (int i = 0; i< N; i++){
        scanf("%s %d", Data[i].id, &Data[i].score);
        Data[i].room = toroom(Data[i].id);
        Data[i].time = totime(Data[i].id);
    }
    qsort(Data, N, sizeof(Data[0]),cmp);

    int index; char ch_1; int point; int time_list[1000] ={0}; int time_flag = 0; int flag_A = 1;int flag_room = 1; int cnt_room = 0; int cnt_room_score= 0;
    struct TIME Time_struc[1000]; int cnt_time = 0;
    
    for (int i = 0; i< M; i++){
        scanf("%d", &index);getchar();
        if (index == 1){
            flag_A = 1;
            scanf("%c", &ch_1);getchar();
            printf("Case %d: %d %c\n", i+1, index, ch_1);
            for (int j = 0 ;j < N; j++){
                if (Data[j].id[0] == ch_1){
                    printf("%s %d\n", Data[j].id, Data[j].score);
                    flag_A = 0;
                }}
            if (flag_A){
                printf("NA\n");
            }
        }else if (index == 2){
//中间数据重置处理，注意答案为0的结果
            cnt_room = 0; cnt_room_score= 0; flag_room = 1;
            scanf("%d", &point);getchar();
            printf("Case %d: %d %d\n", i+1, index, point);
            for(int j = 0; j< N; j++){
                if (Data[j].room == point){
                    cnt_room ++; cnt_room_score = cnt_room_score + Data[j].score;
                    flag_room = 0;
                }
            }
            if (flag_room){
                printf("NA\n");
            }else{printf("%d %d\n", cnt_room, cnt_room_score);}
        }else{
//中间数据重置处理
            time_flag = 1; cnt_time  =0;
            for (int j = 0; j< 1000; j++) time_list[j] = 0;
            scanf("%d", &point);getchar();
//注意日期输出
            printf("Case %d: %d %06d\n", i+1, index, point);
            for(int j = 0; j< N; j++){
                if (Data[j].time == point){
                    time_list[Data[j].room] ++;
                    time_flag = 0;
                }
            }for (int j =0 ; j< 1000; j++){
                if (time_list[j] != 0){
                    Time_struc[cnt_time].k = j; Time_struc[cnt_time].l = time_list[j]; cnt_time ++;}
            }
            qsort(Time_struc, cnt_time, sizeof(Time_struc[0]), cmp_time);
            if (time_flag){
                printf("NA\n");}
            else{for (int j = 0; j< cnt_time; j++){
                printf("%d %d\n", Time_struc[j].k, Time_struc[j].l); }}
        }
    }
    return 0;
}
