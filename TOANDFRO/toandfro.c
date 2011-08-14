#include <stdio.h>

int
main (int argc, char *argv[]) {
	int width = 0, height = 0;
	int i = 0, j = 0;
	int len = 0;
	char str[256] = { 0, };

	while (1)
	{
		scanf ("%d", &width);
		if (0 == width)
			return 0;

		scanf ("%s", str);
		len = strlen (str);
		height = len / width;
		for (i = 0; i < width; i++)
		{
			for (j = 0; j < height; j++) {
				printf ("%c", str[j*width+i]);
			}

		}
		printf ("\n");
	}
	return 0;
}
