#include <stdio.h>
int main(){
    int m,n,A,B,T;
    scanf("%d %d %d %d %d",&m,&n,&A,&B,&T);
    int x;
    for (int i= 0; i< m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &x);
            if (j == 0){
                if (x >= A && x<= B){
                    printf("%03d", T);
                }else {
                    printf("%03d", x);
                }
            }else {
            if (x >= A && x<= B){
                printf(" %03d", T);
            }else {
                printf(" %03d", x);
            }
        }
        }
        printf("\n");
    }
    return 0;
}