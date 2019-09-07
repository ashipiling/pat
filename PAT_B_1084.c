#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void waiguan(char *ch, char *out){
	unsigned long length = strlen(ch);
	char c = ch[0]; int ch_cnt = 1; int cnt = 0;
//ch_cnt复原
	for (int i =1 ; i < length-1; i++){
		if (ch[i] != c){
			out[cnt] = c; cnt++;
			out[cnt] = '0'+ ch_cnt; cnt++;
			c = ch[i];
			ch_cnt = 1;
		}else{
			ch_cnt++;
		}
	}
	if (ch[length -1] == c){
		ch_cnt++;
		out[cnt] = c; cnt++;
		out[cnt] = '0'+ ch_cnt; cnt++;
	}else{
		out[cnt] = c; cnt++;
		out[cnt] = '0'+ ch_cnt; cnt ++;
		out[cnt] = ch[length-1]; cnt++;
		out[cnt] = '1'; cnt ++;
	}
	for (int i = 0; i<cnt; i++){
		ch[i] = out[i];
	}
	ch[cnt] = '\0';
}

int main(){
	int d , N; scanf("%d %d", &d, &N);

	char ch[100000];
	ch[0] = '0' +d; ch[1] = '1'; ch[2] = '\0';
	char out[100000];

	if (N == 1){
		printf("%d\n", d);
	}else{
		for (int i = 2; i< N; i++){
			waiguan(ch, out);
		}
        printf("%s", ch);
	}
//输出

	return 0;
}