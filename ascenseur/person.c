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

PersonList *del(Person *p, PersonList *list)
{
    PersonList *prev = NULL;
    PersonList *current = list;
    while (current != NULL)
    {
        if (p->src == current->person->src && p->dest == current->person->dest)
        {
            prev->next = current->next;
        }
        else
        {
            //DO NOTHING
        }
        prev = current;
        current = current->next;
    }
    return list;
}
