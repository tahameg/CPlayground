#ifndef PERSONLIST_H
#define PERSONLIST_H


typedef struct Person Person;
typedef struct Node Node;

typedef struct PersonStackHandle
{
    Node *first_node;
    size_t current_size;
} PersonStackHandle;

PersonStackHandle create_list();
void push_front(PersonStackHandle *handle, const Person *per);
void pop_front(PersonStackHandle *handle);
size_t get_size(PersonStackHandle *handle);
void get_first(PersonStackHandle *handle, Person *per);
int isempty(PersonStackHandle *handle);
void print_person_list(PersonStackHandle *handle);
void make_empty(PersonStackHandle *handle);

#endif