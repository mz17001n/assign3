#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Note, the bits are counted from right to left. 
// Return the bit states of x within range of [start, end], in which both are inclusive.
// Assume 0 <= start & end <= 31
unsigned * get_bits(unsigned x, unsigned start, unsigned end) {

  unsigned * a = malloc(sizeof(int)*(end-start+1));
  int index = 0;
  for (int i = start; i <= end; i++) {
    if ((x >> i) & 1) {
      a[index] = 1;
      index++;
    } else {
      a[index] = 0;
      index++;
    }
  // get_bits dynamically allocates an array a and set a[i] = 1 when (i+start)-th bit
  // of x is 1, otherwise set a[i] = 0;
  // At last, get_bits returns the address of the array.
  }
  return a;
}