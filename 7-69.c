#include <stdio.h>
int main(){
    int a;
    scanf("%d",&a);
    int num[a];
    int num_copy[a];
    if (a == 3){
      printf("%d",2);
    }else if (a== 2){
      printf("%d",2);
    }else if (a== 1){
      printf("%d",1);
    }else{
    for (int i = 1 ;i <= a;i++){
        num[i-1] = i;
    }
    for (int i =a-1 ;i>=3;i--){
        for (int j = 3;j<=a-1;j++){
            num_copy[j-3] = num[j];
        }
        num_copy[i-2] = num[0];
        num_copy[i-1] = num[1];
        num_copy[i] = num[2];
        for (int k = 0;k<a;k++){
            num[k] = num_copy[k];
        }
    }
    printf("%d",num_copy[1]);
    }
    
    return 0;
}