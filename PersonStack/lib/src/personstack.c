#include <stdio.h>
#include <stdlib.h>
#include "personstack.h"
#include "person.h"

#define PUBLIC 
#define PRIVATE static 

typedef struct Node {
    Person* data;
    struct Node* next;
} Node;


PRIVATE Node* create_node(const Person *per);

PUBLIC PersonStackHandle create_list()
{
    PersonStackHandle handle;
    handle.first_node = NULL;
    handle.current_size = 0;
    return handle;
}

PUBLIC void push_front(PersonStackHandle *handle, const Person *per)
{
    if(isempty(handle))
    {
        handle->first_node = create_node(per);
        handle->current_size++;
        return;
    }
    
    Node* new_node = create_node(per);
    new_node->next = handle->first_node;
    handle->first_node = new_node;
    handle->current_size++;
}

PUBLIC void pop_front(PersonStackHandle *handle)
{
    if(isempty(handle))
    {
        return;
    }
    Node* temp = handle->first_node->next;
    free(handle->first_node);
    handle->first_node = temp;
    handle->current_size--;
}

PUBLIC size_t get_size(PersonStackHandle *handle)
{
    return handle->current_size;
}

PUBLIC void get_first(PersonStackHandle *handle, Person *per)
{
    per = isempty(handle) ? NULL : handle->first_node->data;
}

PUBLIC int isempty(PersonStackHandle *handle)
{
    return handle->current_size == 0;
}

PUBLIC void print_person_list(PersonStackHandle *handle)
{
    if(isempty(handle)) 
    {
        return;
    }
    Node* cursor = handle->first_node;
    while(cursor != NULL)
    {
        print_person(cursor->data);
        cursor = cursor->next;
    }
}

PUBLIC void make_empty(PersonStackHandle *handle)
{
    while (!isempty(handle))
    {
        pop_front(handle);
    }
}

PRIVATE Node* create_node(const Person* per)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (Person*)per;
    new_node->next = NULL;
    return new_node;
}