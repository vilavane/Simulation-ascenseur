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
    return e;
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
            e->persons = del(current->person, e->persons);
            persons_exit = insert(current->person, persons_exit);
        }
        else
        { //DO NOTHING
        }
        current = current->next;
    }
    return persons_exit;
}

int len(PersonList *persons)
{
    int cpt = 0;
    PersonList *current = persons;
    while (current != NULL)
    {
        cpt++;
        current = persons->next;
    }
    return cpt;
}

PersonList *enterElevator(Elevator *e, PersonList *waitingList)
{
    int nb_persons = len(e->persons);        //number of people inside the elevator
    int nb_enter = e->capacity - nb_persons; //number of people who can enter in the elevator
    for (int i = 1; i != nb_enter; i++)
    {
        e->persons = insert(waitingList->person, e->persons); //insert the first person waiting in the elevator
        waitingList = waitingList->next;                      //remove the first person of waitingList
    }
    return waitingList;
}

void stepElevator(Building *b)
{
    while (b->elevator->currentFloor != b->elevator->targetFloor)
    {
        b->elevator->currentFloor = b->elevator->currentFloor + ((b->elevator->targetFloor - b->elevator->currentFloor) / abs(b->elevator->currentFloor - b->elevator->targetFloor));
    }
    PersonList *persons_exit = malloc(sizeof(PersonList));
    persons_exit = exitElevator(b->elevator);
    b->waitingLists[b->elevator->currentFloor] = enterElevator(b->elevator, b->waitingLists[b->elevator->currentFloor]);
}
