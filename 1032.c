#include <stdio.h>
int main(){
    int schList[100001]={0},num,score,schname,max_sco=-1,max_sch=1;
    scanf("%d",&num);
    for (int i=0 ;i<num;i++){
        scanf("%d %d",&schname,&score);
        schList[schname] += score;
    }
    for (int k =0;k<=num;k++){
        if (schList[k] > max_sco){
            max_sco = schList[k];
            max_sch = k;
        }
    }
    printf("%d %d",max_sch,max_sco);
    
    return 0;
}
