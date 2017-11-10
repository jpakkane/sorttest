#include<sorter.h>
#include<stdlib.h>

#define NUM_INTS 100000000
int numbahs[NUM_INTS];

void create_random() {
    srandom(42);
    for(int i=0; i<NUM_INTS; i++) {
        numbahs[i] = (int)random();
    }
}

int compare(const void *a , const void *b) {
    return *((const int*)a) < *((const int*)b);
}

int main(int argc, char **argv) {
    create_random();
    qsort(numbahs, NUM_INTS, sizeof(int), compare);
    return 0;
}
