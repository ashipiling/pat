#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void change_char(char *a){
    unsigned long length = strlen(a);
    for (int i = 0; i< length; i++){
        if(a[i]>='A' && a[i]<= 'Z'){
            a[i] = a[i] +('a' - 'A');
        }
    }
}
struct SCHOOL_score{
    double score;
    char school[7];
    int count;
};
int cmp_school(const void *a, const void *b){
    struct SCHOOL_score *p = (struct SCHOOL_score *) a;
    struct SCHOOL_score *q = (struct SCHOOL_score *) b;
    if(strcmp(p->school, q->school) !=0){
        return (strcmp(p->school, q->school));
    }else {
        return 0;
    }
}
int cmp_score(const void *a, const void *b){
    struct SCHOOL_score *p = (struct SCHOOL_score *) a;
    struct SCHOOL_score *q = (struct SCHOOL_score *) b;
    int m = (int)p->score; int n = (int)q->score;
    if(m != n){
        return n - m;
    }else if(p ->count != q->count){
        return p->count - q->count;
    }else if(strcmp(p->school, q->school) !=0){
        return (strcmp(p->school, q->school));
    }else{
        return 0;
    }
}

int main(){
    int N ; scanf("%d", &N);getchar();
    struct SCHOOL_score School_score[N];
    char ID_temp[7], school_temp[7]; double score_temp;
    for (int i = 0; i< N; i++){
        scanf("%s %lf %s", ID_temp, &score_temp, school_temp);getchar();
//小写
        change_char(school_temp);
//成绩加工
        if (ID_temp[0] == 'T'){
            score_temp = score_temp * 1.5;
        }else if (ID_temp[0] == 'B'){
            score_temp = score_temp / 1.5;
        }
//写入结构体并排序
        School_score[i].score = score_temp;
        strcpy(School_score[i].school, school_temp);
    }
    qsort(School_score, N, sizeof(School_score[0]), cmp_school);
//合并数据
    struct SCHOOL_score merge_score[N]; char name_temp[7];
    int cnt = 0;
    for(int i =0; i< N; i++){
        if (i == 0){
            merge_score[cnt].count = 0;
            strcpy(name_temp, School_score[i].school);
            strcpy(merge_score[cnt].school, School_score[i].school);
            merge_score[cnt].score += School_score[i].score;
            merge_score[cnt].count++;
        }else{
            if (strcmp(name_temp, School_score[i].school) != 0){
                strcpy(name_temp, School_score[i].school);
                cnt++;
                merge_score[cnt].count = 0;
                strcpy(merge_score[cnt].school, School_score[i].school);
                merge_score[cnt].score += School_score[i].score;
                merge_score[cnt].count++;
            }else {
                merge_score[cnt].score += School_score[i].score;
                merge_score[cnt].count++;
            }
        }
    }
    cnt++;
//输出
    printf("%d\n", cnt);
    qsort(merge_score, cnt,sizeof(merge_score[0]),cmp_score);
//out_cnt用于输出排名 cnt2用于累计排名
    int out = 1000000000; int out_cnt = 0; int cnt2 =1;
    for (int i = 0; i<cnt;i++){
        if ((int)merge_score[i].score < out){
            out_cnt = out_cnt +cnt2;
            cnt2=1;
            out = (int)merge_score[i].score;
            printf("%d %s %d %d\n",out_cnt, merge_score[i].school, (int)merge_score[i].score, merge_score[i].count);
            
        }else {
            printf("%d %s %d %d\n",out_cnt, merge_score[i].school, (int)merge_score[i].score, merge_score[i].count);
            cnt2++;
        }
    }
    return 0;
}
