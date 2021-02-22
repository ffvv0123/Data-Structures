#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, stop;
	double duration;

	start = time(NULL);	// 현재 시간이 넘어온다.

	for (int i = 0; i < 20000; i++) {			// 루프를 매우 크게 돌린다. 
		for (int j = 0; j < 100000; j++);
	}

	stop = time(NULL);	// 현재 시간이 넘어온다. 
	duration = (double)difftime(stop, start);	// 경과 시간이 초 단위로 반환된다.
	printf("수행시간은 %f초 입니다.\n", duration);

	return 0;
}