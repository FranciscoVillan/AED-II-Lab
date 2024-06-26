#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i) {
    unsigned int j = i;
    while (j > 1 && a[j] < a[j-1])
    {
        swap(a,j-1,j);
        j=j+1;
    }
    
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);

        for (unsigned int j = 0u; j <= i; j++)
        {
            assert(array_is_sorted(a,length));
        }
        
    }

}
