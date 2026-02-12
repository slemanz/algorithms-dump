#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

// 1. Define our data (A Player)
typedef struct {
    int id;
    int energy;
} Player;

// 2. Destroy function
void destroy_player(void *data) {
    free(data);
}

// Helper to create players
Player *create_player(int id, int energy) {
    Player *p = (Player*)malloc(sizeof(Player));
    p->id = id;
    p->energy = energy;
    return p;
}

int main() {
    CList game_circle;
    CListElmt *element;
    Player *p;

    // STEP 1: Initialize
    clist_init(&game_circle, destroy_player);
    printf("--- Game Initialized ---\n");

    // STEP 2: Insert Players (Building the Circle)
    // Player 1 (The first one, so we pass NULL as the 'element' to insert after)
    p = create_player(1, 100);
    clist_ins_next(&game_circle, NULL, p);

    // Player 2 (Insert AFTER the head/Player 1)
    // List: P1 -> P2 -> P1
    p = create_player(2, 100);
    clist_ins_next(&game_circle, clist_head(&game_circle), p);

    // Player 3 (Insert AFTER Player 2)
    // To keep order 1->2->3, we insert after P2.
    // P2 is currently 'head->next'.
    CListElmt *p2_element = clist_next(clist_head(&game_circle));
    
    p = create_player(3, 100);
    clist_ins_next(&game_circle, p2_element, p);

    printf("Players joined: %d\n", clist_size(&game_circle));
    // Current Circle: P1 -> P2 -> P3 -> (back to P1)

    // STEP 3: Simulate "Round Robin" Turns
    printf("\n--- Starting Game Loop (2 Cycles) ---\n");
    
    element = clist_head(&game_circle);
    
    // We will simulate 6 turns (2 full rounds for 3 players)
    // Notice: We don't check for NULL. We just follow ->next.
    for (int i = 0; i < 6; i++)
    {
        p = (Player*)clist_data(element);
        
        printf("Turn %d: Player [%d] (Energy: %d) acts.\n", i+1, p->id, p->energy);
        p->energy -= 10; // Use some energy

        // Move to the next player in the circle
        element = clist_next(element);
    }

    // STEP 4: Remove a Player
    // Let's say Player 2 is disqualified.
    // clist_rem_next removes the element *AFTER* the one you pass.
    // To remove P2, we must pass P1 (which is the head).
    
    printf("\n--- Player 2 Disqualified ---\n");
    
    void *freed_data;
    if (clist_rem_next(&game_circle, clist_head(&game_circle), &freed_data) == 0) {
        Player *removed = (Player*)freed_data;
        printf("Removed Player [%d]\n", removed->id);
        destroy_player(removed);
    }

    // STEP 5: Verify the new circle
    // Expectation: P1 -> P3 -> P1
    printf("\n--- Remaining Players ---\n");
    element = clist_head(&game_circle);
    for(int i=0; i < clist_size(&game_circle); i++) {
        p = (Player*)clist_data(element);
        printf("Player [%d]\n", p->id);
        element = clist_next(element);
    }

    // STEP 6: Cleanup
    clist_destroy(&game_circle);
    printf("\nGame Over. List destroyed.\n");

    return 0;
}