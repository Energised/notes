#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv)
{
  int *array = (int*) malloc(10 * sizeof(int));
  // zero out all bytes
  memset(array, 0, 10*sizeof(int));
  // can check the values
  for(int i = 0; i < 10; i++)
  {
    printf("value at position %d: %d\n", i, array[i]);
  }
  // and deallocate the memory
  free(array);
  array = NULL;
}
