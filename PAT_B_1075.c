#include<stdio.h>
struct DATA{
    int address;
    int data;
    int next;
    int flag;
};
//输入，构建3个结构体线性表
int main(){
    int initial_address; int N; int K;
    scanf("%d %d %d", &initial_address, &N, &K);
    struct DATA a[100000], b[100000], c[100000]; int site_temp;
    for (int i = 0 ; i< N; i++){
        scanf("%d", &site_temp); scanf("%d %d", &a[site_temp].data, &a[site_temp].next);
    }
//构建链表并重置总数舍弃N
    int b_cnt = 0;
    while (initial_address != -1){
        b[b_cnt].address = initial_address;
        b[b_cnt].data = a[initial_address].data;
        b[b_cnt].next = a[initial_address].next;
        b[b_cnt].flag = 1;
        initial_address = a[initial_address].next;
        b_cnt++;
    }
//b中数据重新转入c中，用过的flag标为0
    int c_cnt = 0;
    for (int i = 0; i< b_cnt; i++){
        if (b[i].data < 0){
            c[c_cnt].address = b[i].address;
            c[c_cnt].data = b[i].data;
            b[i].flag = 0;
            c_cnt++;
        }
    }for (int i = 0; i< b_cnt; i++){
        if (b[i].data >= 0 && b[i].data <= K){
            c[c_cnt].address = b[i].address;
            c[c_cnt].data = b[i].data;
            b[i].flag = 0;
            c_cnt++;
        }
    }for (int i = 0; i< b_cnt; i++){
        if (b[i].flag){
            c[c_cnt].address = b[i].address;
            c[c_cnt].data = b[i].data;
            c_cnt++;
        }
    }
//输出数据注意-1
    for(int i = 0; i<c_cnt-1; i++){
        printf("%05d %d %05d\n", c[i].address, c[i].data, c[i+1].address);
    }
    printf("%05d %d -1\n", c[c_cnt-1].address, c[c_cnt-1].data);
    return 0;
}
