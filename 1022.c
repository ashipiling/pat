#include<stdio.h>
int main(){
  int a,b,n;
  int sum,remain,quo,out[32],num=0;
  scanf("%d %d %d",&a,&b,&n);
  sum = a+b;
  do{
    remain = sum % n;
    out[num++] = remain;
    sum = sum / n;
  }while(sum > 0);
  for (int j = num-1;j>=0;j--){
    printf("%d",out[j]);
  }
  return 0;
}