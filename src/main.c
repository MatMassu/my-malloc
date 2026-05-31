#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

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
    // TEST 1 - Write to allocated memory
    for(int i=0; i<5;i++){
        printf("====== ITERATION %d ======\n", i+1);
        printf("Program break is currently at address: %p\n", sbrk(0));
        int *x = my_malloc(sizeof(int));
        printf("%ld bytes of memory assigned\n", sizeof(int));
        printf("Program break is now at address: %p\n", sbrk(0));
        if (x == NULL){
            printf("NULL value at address %p\n", x);
            return 1;
        }

        *x = i;
        printf("Value assigned\n");
        printf("Memory address %p holds the value: %d\n", x, *x);
        printf("\n");
    };

    return 0;
}