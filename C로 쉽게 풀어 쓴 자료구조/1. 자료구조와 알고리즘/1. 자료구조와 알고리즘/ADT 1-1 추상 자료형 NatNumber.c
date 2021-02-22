#define INT_MAX 100

typedef struct {
	int x;
	int y;
} Nat_Number;

typedef struct {
	int x;
	int y;
} Boolean;

int zero() {
	return 0;
}

int successor(int x) {
	if (x == INT_MAX)
		return x;
	return x + 1;
}

int is_zero(int x) {
	if (x)
		return 0;
	return 1;
}

int equal(int x, int y) {
	if (x == y)
		return 1;
	return 0;
}

int add(int x, int y) {
	if (x + y <= INT_MAX)
		return x + y;
	return INT_MAX;
}

int sub(int x, int y) {
	if (x < y)
		return 0;
	return x - y;
}