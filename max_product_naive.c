#include "max_product.h"
#define Max(x, y) (x > y ? x : y)
int max_pairwise_product_naive(int * arr, int size){
        int result = 0;
        for (int i = 0; i<size; i++){
                for (int j = i+1; j<size; j++){
                        result = Max(result, arr[i]*arr[j]);
                }
        }
        return result;
}

