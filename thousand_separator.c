#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* thousand_separator(const char *const num, char sep, size_t group);

int main(void) {

	char *result = thousand_separator("321654987", ',', 3);

	puts("------------------------");
	puts(result);

	puts("\nThe End ...");
	return (EXIT_SUCCESS);
}

char* thousand_separator(const char *const num, char sep, size_t group) {

	if (sep == '\0')
		sep = ',';
	if (group == 0)
		group = 3;

	const size_t zero = 0;
	const size_t one = 1;

	size_t j = zero;
	size_t i = zero;
	size_t counter = zero;

	const size_t length = strlen(num);
	const size_t mod = length % group;
	const size_t size = length + (length / group) + one;
	char *const ts = (char*) calloc(size, sizeof(char));
	if (length < 4) {
		strcpy(ts, num);
		return (ts);
	}

	memset(ts, (int) zero, size);

	while (i < mod) {
		ts[j] = num[i];
		i++;
		j++;
	}

	if (mod > zero) {
		ts[j] = sep;
		j++;
	}

	while (i < length) {
		if (counter < group) {
			ts[j] = num[i];
			i++;
			j++;
			counter++;
		} else {
			ts[j] = sep;
			j++;
			counter = zero;
		}
	}
	return (ts);
}
