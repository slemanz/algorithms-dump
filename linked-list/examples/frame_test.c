#include <stdio.h>
#include <stdlib.h>
#include "frames.h"
#include "list.h"

void destroy_int(void *data)
{
    free(data);
}

int main()
{
    List available_frames;
    int frame_number;
    int i;

    const int TOTAL_FRAMES = 5;

    // 1. Initialize the list
    list_init(&available_frames, destroy_int);

    printf("--- Initializing Page Free Allocator ---\n");

    // 2. SEED THE POOL
    // The list is empty, which means we have 0 frames available.
    // We must populate the "free list" with frame numbers (e.g., 0 to 4).
    // We use 'free_frame' to ADD frames to the available pool.
    for(i = 0; i < TOTAL_FRAMES; i++)
    {
        if(free_frame(&available_frames, i) == 0)
        {
            printf("Made frame [%d] available.\n", i);
        }else
        {
            fprintf(stderr, "Failed to make frame available.\n");
        }
    }

    printf("Total available frames %d\n", list_size(&available_frames));
    printf("-----------------------------------------\n");

    // 3. Simulate allocating memory (alloc_frame)
    // This remove nodes from the linked list
    printf("\n--- Allocating Frames ---\n");

    // Request 3 frames
    for(i = 0; i < 3; i++)
    {
        frame_number = alloc_frame(&available_frames);
        if(frame_number >= 0)
        {
            printf("Allocated frame number> [%d]\n", frame_number);
        }else
        {
            printf("Error> No frames available!\n");
        }
    }

    printf("Frames remaining in pool: %d\n", list_size(&available_frames));

    // 4. simulate freeing memory (free_frame)
    // Let's say we are done with frame #4 (which we just allocated above).
    // This puts the node back into the linked list.
    printf("\n--- Returning Frame [4] to Pool ---\n");
    int frame_to_return = 4;

    if(free_frame(&available_frames, frame_to_return) == 0)
    {
        printf("Frame [%d] is now available again\n", frame_to_return);
    }

    printf("Frames remaining in pool: %d\n", list_size(&available_frames));

    // 5. Simulate running out of memory
    printf("\n--- Stress Test: Allocation until empty ---\n");
    while(list_size(&available_frames) > 0)
    {
        int f = alloc_frame(&available_frames);
        printf("Allocated: [%d]\n", f);
    }

    //Try one more time when empty
    int failed_frame = alloc_frame(&available_frames);
    if(failed_frame == -1)
    {
        printf("Result: Allocation failed correctly (Pool is empty).\n");
    }

    // 6. Cleanup
    list_destroy(&available_frames);

    return 0;
}