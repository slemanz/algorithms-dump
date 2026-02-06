#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// 1. Define the custom data structure we want to store
typedef struct {
    char name[30];
    int id;
} Person;

// 2. Define a "Destroy" function
// This is required by list_init so the list knows how to free your specific data
void destroy_person(void *data)
{
    // Since we are just mallocing the struct, we just free it.
    // If Person contained other pointers (like char* bio), we would free them here too.
    free(data);
    printf("  [Debug] Freed memory for a Person.\n");
}

// Helper function to create a Person easier
Person *create_person(const char *name, int id)
{
    Person *new_p = (Person*)malloc(sizeof(Person));
    if(new_p == NULL)
    {
        return NULL;
    }

    strcpy(new_p->name, name);
    new_p->id = id;

    return new_p;
}

int main()
{
    List my_list;
    ListElmt *element;
    Person *p;

    // STEP 1: Initialize the list
    list_init(&my_list, destroy_person);
    printf("List initialized. Size: %d\n", list_size(&my_list));

    // STEP 2: Insert Data
    // Insertion A: Insert at the HEAD (pass NULL as the element)
    p = create_person("Alice", 101);
    list_ins_next(&my_list, NULL, p); 

    // Insertion B: Insert at the HEAD again (pushes Alice to 2nd spot)
    p = create_person("Bob", 102);
    list_ins_next(&my_list, NULL, p);

    // Insertion C: Insert at the TAIL (Append)
    // We use the list_tail macro to find the end, then insert after it.
    p = create_person("Charlie", 103);
    list_ins_next(&my_list, list_tail(&my_list), p);

    // Current State: Bob -> Alice -> Charlie

    // STEP 3: Iterate and Print
    printf("\n--- Current List Content ---\n");

    element = list_head(&my_list);
    while(element != NULL)
    {
        // We must cast the generic (void*) data back to (Person*)
        p = (Person *)list_data(element);
        printf("Name : %-10s | ID: %d\n", p->name, p->id);

        // move the next
        element = list_next(element);
    }
    printf("----------------------------\n");

    // STEP 4: Remove an element
    printf("\nRemoving the head of the list (Bob)...\n");

    void *freed_data;
    // remove the element at the head (pass NULL as element argument)
    if(list_rem_next(&my_list, NULL, &freed_data) == 0)
    {
        // NOTE: list_rem_next removes the node, but gives YOU the data back.
        // You are responsible for freeing the data now, or using it elsewhere.
        Person *removed_person = (Person*)freed_data;
        printf("Removed %s\n", removed_person->name);
        destroy_person(removed_person);
    }

    // STEP 5: Destroy the list

    printf("\nDestroying list...\n");
    // This will automatically call destroy_person() on remaining items (Alice, Charlie)
    list_destroy(&my_list); 

    printf("List destroyed.\n");

    return 0;
}
