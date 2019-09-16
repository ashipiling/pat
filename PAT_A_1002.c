#include <stdio.h>
int main(){
    int tmp;
    int k1; scanf("%d", &k1);
    double data1[1100] = {0};
    for (int i = 0; i< k1; i++){
        scanf("%d", &tmp); scanf("%lf", &data1[tmp]);
    }
    int k2; scanf("%d", &k2);
    double data2[1100] = {0};
    for (int i = 0; i< k2; i++){
        scanf("%d", &tmp); scanf("%lf", &data2[tmp]);
    }


    double data_out[1100] = {0}; int cnt = 0;
    for (int i = 0; i< 1100; i++){
        if (data1[i] != 0 && data2[i]!= 0){
            data_out[i] = data1[i] + data2[i];
        }else if (data1[i] !=0 && data2[i]== 0){
            data_out[i] = data1[i];
        }else if (data1[i] == 0 && data2[i]!=0){
            data_out[i] = data2[i];
        }
    }

    for (int i = 1099; i>= 0; i--){
        if (data_out[i] != 0){
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 1099; i>= 0; i--){
        if (data_out[i] != 0){
            printf(" %d %.1f", i, data_out[i]);
        }
    }
    return 0;
}