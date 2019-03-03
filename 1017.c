#include <stdio.h>
#include <string.h>
int main(){
    char list[1001];
    int a,q=0,d;
    scanf("%s %d",list,&a);
    for(int i=0;i<strlen(list);i++){
        d = (list[i]-'0')+(q*10);
        if (d >= a){
            printf("%d",(d/a));
            q = d % a;
        }else{
            if(strlen(list) == 1){printf("0");}
            else if (i){
                printf("0");
            }
            q = d;
        }
    }
    
    printf(" %d\n",q);
    return 0;
}
