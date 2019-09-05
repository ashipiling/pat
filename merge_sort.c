#include <stdio.h>
#include <stdlib.h>
#define LEN 8
//比较函数
int min(int a, int b){
    if (a <= b){
        return a;
    }else {
        return b;
    }
}
void merge(int *list, int *tmp, int Part1Start, int Part2Start, int Part2End){
    int cnt = Part1Start, cnt1 = Part1Start;
    int Part1End = Part2Start-1;
//比较头部数字的大小直到其中一个序列用完
    while (Part1Start <= Part1End && Part2Start <= Part2End){
        if (list[Part1Start] < list[Part2Start]){
            tmp[cnt] = list[Part1Start] ;
            Part1Start++ ; cnt++ ;
        }else{
            tmp[cnt] = list[Part2Start] ;
            Part2Start++ ; cnt++ ;
        }
    }
//剩下的序列填充到tmp中
    while(Part1Start <= Part1End){
        tmp[cnt] = list[Part1Start];
        cnt++ ; Part1Start ++;
    }
    while(Part2Start <= Part2End){
        tmp[cnt] = list[Part2Start];
        cnt++ ; Part2Start ++;
    }
//tmp的值覆盖list原始值
    for (int i = cnt1; i<= Part2End; i++){
        list[i] = tmp[i];
    }
}
void merge_sort( int *list, int N ){
    int k, Part1Start, Part2Start, Part2End;
//创建含有N个int位置的临时数组
    int *tmp_list = malloc( sizeof(int) * N );
//设置步长k，初始值为1
    for( k = 1; k < N; k *= 2 ){
        Part1Start = 0;
        while( Part1Start < N - 1 ){
            Part2Start = Part1Start + k;
//Part2end从N-1和Part2Start+k-1中选一个
            Part2End = min( N-1, Part2Start + k - 1 );
            merge(list, tmp_list, Part1Start, Part2Start, Part2End );
//再定义Part1Start
            Part1Start = Part2End + 1;
        }
    }
}
int main(){
    int a[LEN] = { 5, 2, 4, 7, 1, 3, 6, 8};
    merge_sort(a, LEN);
// print array
    for (int i = 0; i < LEN; i++)
        printf("%d ", a[i]);
    return 0;
}
