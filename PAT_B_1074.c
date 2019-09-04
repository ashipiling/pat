#include<stdio.h>
#include<string.h>
int main(){
//补充前导零，统一操作
    char a1[21],x1[21],y1[21],x[23]={'0','0'},y[23]={'0','0'},a[23]={'0','0'};
    int t=0,i;
    scanf("%s%s%s",a1,x1,y1); strcpy(a+2,a1);
    int chax=strlen(a)-strlen(x1),chay=strlen(a)-strlen(y1);
    for(i=0;i<chax;i++){
        x[i]='0';
    }
    for(i=0;i<chay;i++){
        y[i]='0';
    }
    strcpy(x+chax,x1); strcpy(y+chay,y1);


    int lena=strlen(a);
    int now,jin=0,z[21];
    for(i=1; i<=lena; i++){
        now=x[lena-i]-'0'+y[lena-i]-'0'+jin;
        if(a[lena-i]=='0') a[lena-i]+=10;
        jin=now/(a[lena-i]-'0');
        z[t++]=now%(a[lena-i]-'0');
    }
    for(i=t-1;i>=0;i--){
        if(z[i]==0){
            t--;
        }else{
            break;
        }
    }
    int fg=0;//结果为零时，单独处理
    for(i=t-1; i>=0; i--){
        printf("%d",z[i]);
        fg=1;
    }
    if(fg==0){
        printf("0");
    }//结果为零时，单独处理
    return 0;
}
