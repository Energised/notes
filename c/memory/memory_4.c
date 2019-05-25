#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv)
{
  //allocate initial array
  int *array = (int*) malloc(5*sizeof(int));
  for(int i = 0; i<5; i++)
  {
    array[i] = i*2;
  }
  // extend and populate
  int *new_array = (int*) realloc(array, 10*sizeof(int));
  memcpy(new_array, array, 5*sizeof(int));
  free(array);
  array = new_array;
  new_array = NULL;
  for(int i=5; i<10; i++)
  {
    array[i] = i*2;
  }

  // output new array
  printf("OUTPUT OF EXTENDED array\n");
  for(int i=0; i<10; i++)
  {
    printf("value at position %d: %d\n", i, array[i]);
  }

  //deallocate memory
  free(array);
  array = NULL;

  return 0;

}
