#include "elevator.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>

Elevator *create_elevator(int capacity, int currentFloor, PersonList *persons)
{
    Elevator *e = malloc(sizeof(Elevator));
    e->capacity = capacity;
    e->currentFloor = currentFloor;
    e->persons = persons;
    return lift;
}

Building *create_building(int nbFloor, Elevator *elevator, PersonList **waitingLists)
{
    Building *b = malloc(sizeof(Building));
    b->nbFloor = nbFloor;
    b->elevator = elevator;
    b->waitingLists = waitingLists;
    return b;
}

PersonList *exitElevator(Elevator *e)
{
    PersonList *persons_exit = malloc(sizeof(PersonList));
    PersonList *current = e->persons;
    while (current != NULL)
    {
        if (current->person->dest == e->currentFloor)
        {
            insert(current->person, persons_exit);
        }
        else
        { //DO NOTHING
        }
        current = current->next;
    }
    return persons_exit;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList)
{
}