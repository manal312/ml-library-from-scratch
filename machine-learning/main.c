#include "arena.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    
    mem_arena* perm_arena = arena_create(GiB(10), MiB(1));   
    
    while (1)
    {
        printf("allocating 16 MiB...\n");
        arena_push(perm_arena, MiB(16), false);
        getc(stdin);
    }
    
       
    // 5. Destroy the arena
    arena_destroy(perm_arena);

    return 0;
}