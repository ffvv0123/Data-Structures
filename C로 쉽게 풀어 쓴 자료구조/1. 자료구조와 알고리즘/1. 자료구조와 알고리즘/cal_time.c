#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, stop; // clock_t: ���α׷��� ���۵ǰ� ���� �ð��� �޴� �ڷ���
	double duration;

	start = clock(); // ���α׷��� �������� ���� �ð�.

	for (int i = 0; i < 1000000; i++); // ����ð��� �ø��� ���� �ǹ̾��� ����

	stop = clock(); // ���α׷��� ������� ���� �ð�.
	duration = (double)(stop - start) / CLOCKS_PER_SEC; // ������ ���� �ð��� ���Ѵ�. ���� �ð��� CLOCKS_PER_SEC���� ������. clock() �Լ��� �ð��� �� ������ ��ȯ�ϱ� ����.
	printf("����ð��� %f�� �Դϴ�.\n", duration);

	return 0;
}