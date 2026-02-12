#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

// 1. Helper to allocate integers easily
int* alloc_int(int value) {
    int *p = (int*)malloc(sizeof(int));
    *p = value;
    return p;
}

// 2. Destroy function required by dlist_init
void destroy_int(void *data) {
    free(data);
}

// 3. Helper to print the list in both directions
void print_list_state(DList *list) {
    DListElmt *e;
    int *data;
    
    printf("  [Forward]:  HEAD -> ");
    e = dlist_head(list);
    while(e != NULL) {
        data = (int*)dlist_data(e);
        printf("[%d] <-> ", *data);
        e = dlist_next(e);
    }
    printf("NULL\n");

    printf("  [Backward]: TAIL -> ");
    e = dlist_tail(list);
    while(e != NULL) {
        data = (int*)dlist_data(e);
        printf("[%d] <-> ", *data);
        e = dlist_prev(e);
    }
    printf("NULL\n");
    printf("  Size: %d\n\n", dlist_size(list));
}

int main() {
    DList my_list;
    DListElmt *element;
    int *data_ptr;

    // ----------------------------------------------------
    // STEP 1: Initialization
    // ----------------------------------------------------
    dlist_init(&my_list, destroy_int);
    printf("--- List Initialized ---\n");

    // ----------------------------------------------------
    // STEP 2: Handle Empty List Insertion
    // ----------------------------------------------------
    // When the list is empty, element must be NULL. 
    // It doesn't matter if we use ins_next or ins_prev here.
    
    printf("--- Inserting 10 (First Element) ---\n");
    dlist_ins_next(&my_list, NULL, alloc_int(10));
    print_list_state(&my_list);
    // List: [10]

    // ----------------------------------------------------
    // STEP 3: Insert NEXT (After)
    // ----------------------------------------------------
    // Let's insert 20 AFTER the head (10)
    
    printf("--- Inserting 20 AFTER Head (10) ---\n");
    element = dlist_head(&my_list); // Get the element [10]
    dlist_ins_next(&my_list, element, alloc_int(20));
    print_list_state(&my_list);
    // List: [10] <-> [20]

    // ----------------------------------------------------
    // STEP 4: Insert PREV (Before)
    // ----------------------------------------------------
    // Let's insert 5 BEFORE the head (10). 
    // This will become the NEW head.
    
    printf("--- Inserting 5 BEFORE Head (10) ---\n");
    element = dlist_head(&my_list); // Get the element [10]
    dlist_ins_prev(&my_list, element, alloc_int(5));
    print_list_state(&my_list);
    // List: [5] <-> [10] <-> [20]

    // ----------------------------------------------------
    // STEP 5: Complex Insertion (Middle)
    // ----------------------------------------------------
    // Let's insert 15 BEFORE the tail (20).
    
    printf("--- Inserting 15 BEFORE Tail (20) ---\n");
    element = dlist_tail(&my_list); // Get [20]
    dlist_ins_prev(&my_list, element, alloc_int(15));
    print_list_state(&my_list);
    // List: [5] <-> [10] <-> [15] <-> [20]

    // ----------------------------------------------------
    // STEP 6: Removing an item
    // ----------------------------------------------------
    // Let's remove [10]. We have to find it first or grab it via traversal.
    // We know it is the 'next' of head.
    
    printf("--- Removing [10] ---\n");
    element = dlist_next(dlist_head(&my_list)); // Head is 5, Next is 10.
    
    if (dlist_remove(&my_list, element, (void**)&data_ptr) == 0) {
        printf("Successfully removed: %d\n", *data_ptr);
        free(data_ptr); // Don't forget to free the data!
    }
    print_list_state(&my_list);
    // List: [5] <-> [15] <-> [20]

    // ----------------------------------------------------
    // STEP 7: Cleanup
    // ----------------------------------------------------
    printf("--- Destroying List ---\n");
    dlist_destroy(&my_list);
    printf("Done.\n");

    return 0;
}