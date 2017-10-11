#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>
#include<stdbool.h>

uint64_t** del_line(uint64_t line, uint64_t *size_column, uint64_t** d);

void print_array(uint64_t size_column, uint64_t size_line, uint64_t** a)
{
	for (uint64_t col = 0; col < size_column; col++)
	{
		for (uint64_t line = 0; line < size_line; line++)
		{
			printf("%llu ", a[col][line]);
		}
		printf("\n");
	}
	printf("\n");
}



void randomarray(uint64_t size_line, uint64_t* a)
{
	for (uint64_t st = 0; st < size_line; st++)
	{
		a[st] = rand() % 9-0;
	}
}



uint64_t** make_array(uint64_t size_column, uint64_t size_line)
{
	uint64_t** array = (uint64_t**)malloc(size_column * sizeof(uint64_t*));
	for (uint64_t i = 0; i < size_column; i++)
	{
		array[i] = (uint64_t*)malloc(size_line * sizeof(uint64_t));
		randomarray(size_line, array[i]);
	}

	return array;

}

uint64_t** sum_two(uint64_t size_column, uint64_t size_line, uint64_t** a, uint64_t**b)
{
	uint64_t** array = (uint64_t**)malloc(size_column * sizeof(uint64_t*));
	for (uint64_t i = 0; i < size_column; i++)
	{
		array[i] = (uint64_t*)malloc(size_line * sizeof(uint64_t));
	}
	for (uint64_t col = 0; col < size_column; col++)
	{
		for (uint64_t line = 0; line < size_line; line++)
		{
			array[col][line] = a[col][line] + b[col][line];
		}
	}
	print_array(size_column, size_line, array);
	return array;
	for (uint64_t i = 0; i < size_column; i++)
	{
		free(array[i]);
	}
	free(array);
}

void** zero_del(uint64_t *size_column, uint64_t size_line, uint64_t** d)
{
	for (uint64_t col = 0; col < *size_column; )
	{
		bool temp = false;
		for (uint64_t line = 0; line < size_line; line++)
		{
			if (d[col][line] == 0)
			{
				d = del_line(col, size_column, d);
				temp=true;
				break;
			}
		}
		if (!temp)
		{
			col++;
		}
	}
}


uint64_t** del_line(uint64_t col, uint64_t *size_column, uint64_t** d)
{
	free(d[col]);
	for (uint64_t i = col; i < *size_column - 1; i++)
	{
		d[i] = d[i + 1];
	}
	*size_column = *size_column - 1;
	uint64_t** array = (uint64_t**)realloc(d, (*size_column) * sizeof(uint64_t*));
	return array;
}


void free_function(uint64_t size_column, uint64_t** a)
{
	for (uint64_t i = 0; i < size_column; i++)
	{
		free(a[i]);
	}
	free(a);
}


uint64_t main()

{
	uint64_t **a;
	uint64_t **b;
	uint64_t **c;
	uint64_t **d;
	uint64_t size_column = 0;

	uint64_t size_line = 0;

	printf("Enter size of column\n");

	scanf_s("%llu", &size_column);

	printf("Enter size of line\n");

	scanf_s("%llu", &size_line);

	srand(time(NULL));

	a = make_array(size_column, size_line);

	print_array(size_column, size_line, a);

	b = make_array(size_column, size_line);

	print_array(size_column, size_line, b);

	c = sum_two(size_column, size_line, a, b);

	free_function(size_column, a);
	free_function(size_column, b);
	free_function(size_column, c);

	d = make_array(size_column, size_line);

	print_array(size_column, size_line, d);

	zero_del(&size_column, size_line, d);

	print_array(size_column, size_line, d);

	free_function(size_column, d);

    system("pause");

	return 0;

}