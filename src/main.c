#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

// Define chunk structure
typedef struct {
    size_t header;
} chunk_t;

void *my_malloc(size_t size){

    size_t total_size;

    total_size = size + sizeof(chunk_t);
    total_size = (total_size + 15) & ~15; 

    void *break_p = sbrk(total_size);
    if (break_p == (void *)-1){
        return NULL;
    }

    chunk_t *chunk_p = (chunk_t *)break_p;    
    chunk_p->header = total_size;

    void *usable_mem = (char *)chunk_p + sizeof(chunk_t); 
    
    return usable_mem;
}

int main(void){
    int *x = my_malloc(sizeof(int));

    if (x == NULL){
        return 1;
    }

    *x = 10;

    printf("%d\n", *x);
    return 0;
}