#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv)
{
  // allocate initial array
  int *array = (int*) malloc(5 * sizeof(int));
  for(int i=0; i<5; i++)
  {
    array[i] = i*2;
  }

  // extend and further populate the array

  array = (int*) realloc(array, 10 * sizeof(int));
  for(int i=5; i<10; i++)
  {
    array[i] = i*2;
  }

  // check output
  printf("OUTPUT FOR REALLOCATED array\n");
  for(int i=0; i<10; i++)
  {
    printf("value at position %d: %d\n", i, array[i]);
  }

  // and free memory
  free(array);
  array = NULL;

  return 0;

}
