#include <stdio.h>
int main(){
    int numdata[100000]; int cnt = 0; int flag = 1;
    char ch;
    int x; scanf("%d", &x); numdata[cnt] = x; ch = getchar();
    while (ch != '\n'){
        cnt ++;
        scanf("%d", &x);
        numdata[cnt] = x;
        ch = getchar();
    }
    int outdata[100000], y,z, out_cnt = 0;
    for (int i =0; i<= cnt/2; i++){
        y = numdata[2*i]*numdata[2*i+1];
        z = numdata[2*i+1]-1;
        if (z == -1){
            continue;
        }else{
            outdata[out_cnt] = y;
            out_cnt++;
            outdata[out_cnt] = z;
            out_cnt++;
        }
    }
    if (out_cnt == 0){
        printf("0 0");
    }else {
        for (int i= 0; i< out_cnt; i++){
            if (flag){
                printf("%d", outdata[i]);
                flag = 0;
            }else {
                printf(" %d", outdata[i]);
            }
        }
    }
    return 0;
}