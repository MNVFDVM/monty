#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *c;
	FILE *f;
	size_t s = 0;
	ssize_t read = 1;
	stack_t *stac = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	bus.file = f;
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		c = NULL;
		read = getline(&c, &s, f);
		bus.content = c;
		count++;
		if (read > 0)
		{
			execute(c, &stac, count, f);
		}
		free(c);
	}
	free_stack(stac);
	fclose(f);
return (0);
}
