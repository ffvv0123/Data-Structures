#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, stop;
	double duration;

	start = time(NULL);	// ���� �ð��� �Ѿ�´�.

	for (int i = 0; i < 20000; i++) {			// ������ �ſ� ũ�� ������. 
		for (int j = 0; j < 100000; j++);
	}

	stop = time(NULL);	// ���� �ð��� �Ѿ�´�. 
	duration = (double)difftime(stop, start);	// ��� �ð��� �� ������ ��ȯ�ȴ�.
	printf("����ð��� %f�� �Դϴ�.\n", duration);

	return 0;
}