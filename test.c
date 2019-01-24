#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "max_product.h"

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void stress_test(int N, int M){
  srand(time(NULL));   // Initialization, should only be called once.
  
  while (1) {
    int n = rand() % (N-2) + 2;      // Returns a pseudo-random integer between 0 and RAND_MAX.
  
    int *arr = malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
      arr[i] = rand() % M + 1; 
    }
    print_array(arr, n);
    
    int result1 = max_pairwise_product_naive(arr, n);
    int result2 = max_pairwise_product_fast(arr,n);
    
    if (result1==result2)
      printf("OK\n");
    else
      printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);  
    free(arr);
  }  
}

int main(int argc, char **argv ){
  if (argc < 3){
    printf("To run: test <N> <M>\n");
    return 0;
   }
   
   int N = atoi(argv[1]);
   int M = atoi(argv[2]);
   
   stress_test(N, M);
   
   return 0;
  
}
