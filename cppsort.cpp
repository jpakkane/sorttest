#include<stdlib.h>
#include<algorithm>

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
    std::sort(numbahs, numbahs+NUM_INTS, [](const int a, const int b) { return a < b;});
    return 0;
}
