#include <stdio.h>
int main()
{
    int N, time, current, now;
    scanf("%d", &N);
    for(now = 0, time = 0; N--; now = current){
        scanf("%d", &current);
        if(current > now)   time += (current - now) * 6 + 5;
        else            time += (now - current) * 4 + 5;
    }

    printf("%d", time);

    return 0;
}