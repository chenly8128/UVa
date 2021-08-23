#include <stdio.h>
int main (void) {
	int c;
	_Bool b = 0;
	while ((c = getchar ()) != EOF) {
		if (c == '"') {
			printf ("%s",b ? "''" : "``");
			b = !b;
		}
		else printf ("%c",c);
	}
	return 0;
}
