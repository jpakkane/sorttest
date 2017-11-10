#include<sorter.h>

#define NUM_INTS 10000
int numbahs[NUM_INTS];

int main(int argc, char **argv) {
    sorter x = build_sorter("int", "int is_less(const int a, const int b) { return a < b; }");
    (*x)(numbahs, NUM_INTS);
    return 0;
}
