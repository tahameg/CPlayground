#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "person.h"
#include "personstack.h"

#define COUNT 50


int main()
{
	srand(time(NULL));
	Person persons[COUNT];
	PersonStackHandle handle = create_list();

	for(int i = 0; i < COUNT; i++)
	{
		create_random_person(persons + i);
		push_front(&handle, persons + i);
		print_person(persons + i);
	}

	putchar('\n');

	print_person_list(&handle);
	pop_front(&handle);

	putchar('\n');
	print_person_list(&handle);
	make_empty(&handle);
	getchar();

	//free resources
	for(int i = 0; i < COUNT; i++)
	{
		free_person(persons + i);
	}
	return 0;
}

