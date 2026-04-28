#include "base.h"
#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef int32_t b32;
typedef void* ptr;

#define ARENA_BASE_POS (sizeof(mem_arena))
#define ARENA_ALIGN (sizeof(void*))

//Holds pointers to the reserved memory block.
//Tracks the current position, committed memory, and total reserved size.
//Contains bookkeeping for temporary allocations.
typedef struct {
    u64 reserve_size;
    u64 commit_size;

    u64 pos;
    u64 commit_pos;
} mem_arena;

//Records the state (arena pointer and starting position) for temporary allocations.
// Allows rolling back to a previous state.
typedef struct {
    mem_arena* arena;
    u64 start_pos;
} mem_arena_temp;

//Functions for arena.c
mem_arena* arena_create(u64 reserve_size, u64 commit_size); //create memory
void arena_destroy(mem_arena* arena); //destroy memory
void* arena_push(mem_arena* arena, u64 size, b32 non_zero); //push memory
void arena_pop(mem_arena* arena, u64 size); //pop memory
void arena_pop_to(mem_arena* arena, u64 pos); //pop memory to position
void arena_clear(mem_arena* arena); //clear memory

mem_arena_temp arena_temp_begin(mem_arena* arena); //temp allocation
void arena_temp_end(mem_arena_temp temp); //end temp allocation

mem_arena_temp arena_scratch_get(mem_arena** conflicts, u32 num_conflicts); //get scratch arena
void arena_scratch_release(mem_arena_temp scratch); //release scratch arena

//macros for arena.c
#define PUSH_STRUCT(arena, T) (T*)arena_push((arena), sizeof(T), false)
#define PUSH_STRUCT_NZ(arena, T) (T*)arena_push((arena), sizeof(T), true)
#define PUSH_ARRAY(arena, T, n) (T*)arena_push((arena), sizeof(T) * (n), false)
#define PUSH_ARRAY_NZ(arena, T, n) (T*)arena_push((arena), sizeof(T) * (n), true)

u32 plat_get_pagesize(void);

void* plat_mem_reserve(u64 size);
b32 plat_mem_commit(void* ptr, u64 size);
b32 plat_mem_decommit(void* ptr, u64 size);
b32 plat_mem_release(void* ptr, u64 size);
