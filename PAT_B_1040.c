#include <stdio.h>
int main(){
    char ch[100001];
    gets(ch);
    unsigned long length = strlen(ch);
    int cnt_p = 0, cnt_t = 0, cnt = 0;
    for (int i = 0; i < length ; i++){
        if (ch[i] == 'T'){
            cnt_t++;
        }
    }
    for (int i = 0; i < length ; i++){
        if (ch[i] == 'P'){
            cnt_p ++;
        }else if (ch[i] == 'T'){
            cnt_t --;
        }else if (ch[i] = 'A'){
            cnt += cnt_p * cnt_t ;
            if (cnt > 1000000007){
                cnt = cnt % 1000000007;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}