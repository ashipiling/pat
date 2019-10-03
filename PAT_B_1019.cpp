/*
 给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。例如，我们从6767开始，将得到
 7766 - 6677 = 1089
 9810 - 0189 = 9621
 9621 - 1269 = 8352
 8532 - 2358 = 6174
 7641 - 1467 = 6174
 ... ...
 输入：输入给出一个 (0,10的4次方) 区间内的正整数 N
 输出：如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。
*/
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(int a , int b){
    return a > b;
}
void num_to_array(int num,int array[]){
    int i = 0;
    while (num >= 1){
        array[i] = num % 10;
        num = num / 10;
        i++;
    }
}
int array_to_num(int array[]){
    int num = 0;
    for(int i = 0; i<4;i++){
        num = num * 10 +array[i];
    }
    return num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>vi;
    int data_num,up,down;
    int data_list[4] ={0};
    //必须补零
    scanf("%d",&data_num);
    
    while (1) {
        num_to_array(data_num, data_list);
        sort(data_list, data_list+4);
        up = array_to_num(data_list);
        sort(data_list, data_list+4, cmp);
        down = array_to_num(data_list);
        data_num = down - up;
        printf("%04d - %04d = %04d\n",down,up,data_num);
        if (data_num == 6174 || data_num == 0){
            break;
        }
    }
    return 0;
}
