#include<stdio.h>
#include<string.h>
int main(){
    char a[1000],b[1000],c[1000];
    int len1,len2,i,j,k=0,t=0,m=0,d[1000];
    scanf("%s",a);
    scanf("%s",b);
    len1=strlen(a);
    len2=strlen(b);
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(a[i]!=b[j]){
                k++;
                if(k==len2){
                c[t]=a[i];
                t++;
                }
            }
         }
         k=0; 
    }  
    k=0;
    for(i=0;i<t;i++){
        if(c[i]>=97&&c[i]<=122){
            c[i]=c[i]-32;
        }
    }
    for(i=0;i<t;i++){
        for(j=i+1;j<t;j++){
            if(c[i]==c[j]){
            d[k]=j;
            k++;    
            }
        }
    }
    for(i=0;i<t;i++){
        for(j=0;j<k;j++){
           if(i!=d[j]){
            m++;
            if(m==k){
                printf("%c",c[i]);
               }
           }
        }
        m=0;
    }
    return 0;
}