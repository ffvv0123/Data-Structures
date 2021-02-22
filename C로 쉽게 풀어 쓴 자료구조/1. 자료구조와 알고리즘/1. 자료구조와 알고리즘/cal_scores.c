#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];	// Data Structures

int get_max_score(int n) {
	int i, largest;
	largest = scores[0];	// Algorithm

	for (i = 0; i < n; i++) {
		if (scores[i] > largest)
			largest = scores[i];
	}
	return largest;
}