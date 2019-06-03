#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv)
{
  int *array_src = (int*) malloc(10 * sizeof(int));
  int *array_dst = (int*) malloc(5 * sizeof(int));
  // fill array_src with even numbers
  for(int i = 0; i < 10; i++)
  {
    array_src[i] = i*2;
  }

  // then copy second half of bytes from src to dst
  memcpy(array_dst, array_src+5, 5*sizeof(int));

  // output results
  printf("OUTPUT OF array_src:\n");
  for(int i = 0; i < 10; i++)
  {
    printf("value at point %d: %d\n", i, array_src[i]);
  }

  printf("\nOUTPUT OF array_dst:\n");
  for(int i = 0; i<5; i++)
  {
    printf("value at point %d: %d\n", i, array_dst[i]);
  }
  return 0;

  // dont forget to deallocate memory
  free(array_src);
  free(array_dst);
  array_src = NULL;
  array_dst = NULL;
}
