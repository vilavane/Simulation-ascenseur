#include "person.h"
#include <stdio.h>
#include <stdlib.h>

Person *createPerson(int src, int dest)
{
    Person *p = malloc(sizeof(Person));
    p->src = src;
    p->dest = dest;
    return p;
}

PersonList *insert(Person *p, PersonList *list)
{
    PersonList *res = malloc(sizeof(PersonList));
    res->person = p;
    res->next = list;
    return res;
}