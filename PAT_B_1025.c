#include <stdio.h>
//三个线性表代替链表
struct Primary_Data{
    int address;
    int data;
    int Next;
};
int main(){
    int Addre_1,Addre_2, N, K;
    scanf("%d %d %d", &Addre_1, &N, &K);
    struct Primary_Data a_data[100010], b_data[100010], c_data[100010];
 //将原始数据存入a中
    for (int i = 0; i< N; i++){
        scanf("%d", &Addre_2);
        scanf("%d %d", &a_data[Addre_2].data, &a_data[Addre_2].Next);
    }
//按照链表结构存入b中，并重新计算数量
    int cnt = 0;
    for (int i = Addre_1; i != -1; i = a_data[i].Next){
        b_data[cnt].address = i;
        b_data[cnt].data = a_data[i].data;
        b_data[cnt].Next = a_data[i].Next;
        cnt++;
    }
//反转并存入c中
    int y = cnt/K; int yushu = cnt%K;
    int cnt0 = cnt;
    cnt = 0;
    for (int i = 0; i < y; i++){
        for (int j = K-1; j>=0; j--){
            c_data[cnt].address = b_data[j+ K*i].address;
            c_data[cnt].data = b_data[j+ K*i].data;
            cnt++;
        }
    }
    if (yushu!= 0){
    	for (int i = cnt0-yushu; i< cnt0;i++){
        	c_data[cnt].address = b_data[i].address;
        	c_data[cnt].data = b_data[i].data;
        	cnt++;
    	}
    }
//输出
    for (int i = 0 ; i< cnt-1; i++){
        printf("%05d %d %05d\n", c_data[i].address,c_data[i].data,c_data[i+1].address);
    }
    printf("%05d %d -1\n", c_data[cnt-1].address,c_data[cnt-1].data);
    return 0;
}
