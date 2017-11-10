/*
 * Copyright (C) 2017 Jussi Pakkanen.
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of version 3, or (at your option) any later version,
 * of the GNU General Public License as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
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
