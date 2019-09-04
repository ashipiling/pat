#include <stdio.h>
int main(){
    int N, D; double e;
    scanf("%d %lf %d", &N, &e, &D);
    
    int K; int cnt = 0;
    int cnt_maybe = 0, cnt_conf = 0;
    double temp;
    for (int i = 0 ; i< N; i++){
        scanf("%d", &K);
        cnt = 0;
        for (int j = 0; j< K ; j++){
            scanf("%lf", &temp);
            if (temp < e){
                cnt++;
            }
        }
        if ((double)cnt/K > 0.5 && K> D){
            cnt_conf++;
        }else if((double)cnt/K > 0.5 && K<=D){
            cnt_maybe++;
        }
    }
    printf("%.1f%% %.1f%%", (double)cnt_maybe/N *100, (double)cnt_conf/N *100);
}
