#include <stdio.h>
int main(){
    int a;
    int temp;
    int x, y , z;
    scanf("%d\n", &a);
    int max = -1, min = 10001;
    int max_index, min_index;
    for (int i = 0; i< a; i++){
        scanf("%d %d %d", &x, &y, &z);
        temp = y*y +z* z;
        if (temp > max){
            max = temp;
            max_index = x;
        }
        if (temp < min){
            min = temp;
            min_index = x;
        }
    }
    
    
    printf("%04d %04d", min_index, max_index);
    return 0;
}