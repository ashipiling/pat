#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int ID;
    int score1;
    int score2;
    int sum;
    int iflag;
}Student;

int cmp(const void *a, const void *b){
    Student *p = (Student *)a;
    Student *q = (Student *)b;
    if (p->iflag != q -> iflag){
        return p -> iflag - q-> iflag;
    }else if (p -> iflag != q -> iflag){
        return  q -> iflag - p -> iflag;
    }else if (p -> sum != q -> sum){
        return  q -> sum - p -> sum;
    }else if (p -> score1 != q -> score1){
        return  q -> score1 - p -> score1;
    }else {
        return  p -> ID -  q -> ID;
    }

}

int main(){
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    Student HH[N];
    int temp_ID, temp_sc1, temp_sc2;
    int cnt = 0,cnt2 = 0;

    for (int i = 0 ; i< N; i++){
        scanf("%d %d %d", &temp_ID, &temp_sc1, &temp_sc2);
        HH[cnt].ID = temp_ID; HH[cnt].score1 = temp_sc1; HH[cnt].score2 = temp_sc2; HH[cnt].sum = temp_sc1 + temp_sc2;
        if (temp_sc1 < L || temp_sc2 < L){
            HH[cnt].iflag = 5;
            cnt++;
            cnt2++;
        }
        else if (temp_sc1 >= H && temp_sc2 >= H){
            HH[cnt].iflag = 1;
            cnt++;
        }else if (temp_sc1 >= H && temp_sc2 < H){
            HH[cnt].iflag = 2;
            cnt++;
        }else if (temp_sc1 >= temp_sc2){
            HH[cnt].iflag = 3;
            cnt++;
        }else {
            HH[cnt].iflag = 4;
            cnt++;
        }
    }
    printf("%d\n", cnt-cnt2);
    qsort(HH, cnt, sizeof(HH[0]), cmp);
    for (int i = 0; i< cnt-cnt2; i++){
        printf("%d %d %d\n", HH[i].ID, HH[i].score1,HH[i].score2);
    }
    return 0;
}
