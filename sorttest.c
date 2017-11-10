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

int main(int argc, char **argv) {
    create_random();
    sorter x = build_sorter("int", "(const int a, const int b) { return a < b; }");
    (*x)(numbahs, NUM_INTS);
    return 0;
}
