#include <stdio.h>
#include <string.h>
int main(){
    int list[129] = {0};
    int flag = 1, flag_P = 1,flag_A =1,flag_T = 1,flag_e =1,flag_s =1,flag_t =1;
    char ch = getchar();
    while (ch != '\n'){
        list[ch] ++;
        ch  = getchar();
    }
    while (flag){
        if (list['P']){
            printf("P");
            list['P']--;
        }else{
            flag_P = 0;
        }if (list['A']){
            printf("A");
            list['A']--;
        }else{
            flag_A = 0;
        }if (list['T']){
            printf("T");
            list['T']--;
        }else{
            flag_T = 0;
        }if (list['e']){
            printf("e");
            list['e']--;
        }else{
            flag_e = 0;
        }if (list['s']){
            printf("s");
            list['s']--;
        }else{
            flag_s = 0;
        }if (list['t']){
            printf("t");
            list['t']--;
        }else{
            flag_t = 0;
        }
        if (flag_A == 0 &&flag_P ==0&& flag_e ==0 && flag_s ==0&& flag_e == 0 &&flag_t ==0 && flag_T==0){
            flag =0;
        }
    }
    return 0;
}
