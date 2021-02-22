#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, stop; // clock_t: 프로그램이 시작되고 지난 시간을 받는 자료형
	double duration;

	start = clock(); // 프로그램이 시작했을 때의 시간.

	for (int i = 0; i < 1000000; i++); // 연산시간을 늘리기 위한 의미없는 루프

	stop = clock(); // 프로그램이 종료됐을 때의 시간.
	duration = (double)(stop - start) / CLOCKS_PER_SEC; // 루프의 실행 시간을 구한다. 지난 시간을 CLOCKS_PER_SEC으로 나눈다. clock() 함수는 시간은 저 단위로 반환하기 때문.
	printf("수행시간은 %f초 입니다.\n", duration);

	return 0;
}