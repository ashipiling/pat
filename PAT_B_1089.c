#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, people[101];
    int data[101], lie[101];
    int i, j, k, l, count;
    
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", data + i);
    }
//直接假设谁是狼人
    for (i = 1; i <= n; i++){
        for (j = i + 1; j <= n; j++){
//重置people数组
            for (l = 1; l <= n; l++){
                people[l] = 1;
            }
            people[i] = -1;
            people[j] = -1;
            count = 0;
//寻找说谎者
            for (k = 1; k <= n; k++){
                if (data[k] * people[abs(data[k])] < 0)
                    lie[count++] = k;
            }
//判断说谎者身份并输出
            if (count == 2 && people[lie[0]] + people[lie[1]] == 0) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    
    return 0;
}
