# Custom Memory Allocator
A from-scratch memory allocator that implements malloc, free and realloc in C.

### Why?
Learning exercise, to deepen my operative systems knowledge and fully understand how allocators work.

### AI?
No AI coding used, as it would diminish the exercise's learning value.

### How to build?
Clone the repo and use the `make` command. Tests and testing instructions are included.

## Current status
### Main objectives:
[x] `my_malloc` - basic allocator implemented using the sbrk() syscall. Allocates a contiguous block on the heap with a header storing block size. Returns a pointer to the usable memory past the header. No reuse of freed memory
[] `my_free` - mark a block as free using the flag bit in the header
[] **Splitting** - split a free block into two when it's larger than needed
[] `my_calloc` - allocate and zero-initialize
[] **Coalescing** - merge adjacent free blocks on `my_free` to reduce fragmentation

### Bonus objectives:
[] **Footers** - enable backward coalescing
[] `my_realloc` - resize an existing allocation
[] **Free list** - maintain a linked list of only free blocks for faster allocation
[] **Segregated free list** - separate free lists per size class for faster best-fit search
[] `mmap` for large allocations - use `mmap` for size requests above a threshold, and `sbrk` for smaller ones
[] **Thread safety** - add a mutex around allocator state for concurrent use