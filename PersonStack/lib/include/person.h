#ifndef PERSON_H_
#define PERSON_H_

typedef struct Date Date;

typedef struct Person{
	char* name;
	char* surname;
	Date* birthday;
	const char* city;
} Person;

void create_random_person(Person *out);
void print_person(const Person* in);
void free_person(const Person* in);

#endif /* PERSON_H_ */
