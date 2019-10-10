#include <stdio.h>
#include <string.h>
#include <math.h>
int primer(int a){
    for (int i=3;i<sqrt((double)a)+1;i++){
        if (a%i ==0){
            return 0;
        }
    }
    return 1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int m,n,cnt=1,move = 3,num = 0;
    scanf("%d %d",&m,&n);
    if (m ==1 &&n==2){
        printf("%d %d",2,3);
    }else{
    while (cnt < n){
        if (primer(move) == 1){
            cnt++;
            if (cnt >= m){
                num++;
                if(cnt!=n && (cnt - m + 1) % 10 != 0){
                    printf("%d ",move);
                }else{
                    printf("%d\n",move);}
            }
            
        }
         move += 2;
    }
    }
    return 0;
}
