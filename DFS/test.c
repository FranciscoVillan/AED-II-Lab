#include <stdio.h>
#include <stdlib.h>

struct Tupla
{
    int elem;
    int win_count;
};


void put_last(int length, int* a, int j )
{
    if(a[0]==j){
        for(int i =1; i < length; i++)
        {
            a[i-1]=a[i];
        }
        a[length-1]=j;
    }
    
    else if (a[1]==j)
    {
        for(int i =2; i < length; i++)
        {
            a[i-1]=a[i];
        }
        a[length-1]=j;
    }
    
}
/*
void array_dump(int a[], unsigned int length) {
    printf("[");
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
        if (i < length -1)
        {
            printf(", ");
        }
        
    }
    printf("]");
}
*/
int winner_counter(struct Tupla array_counter[], int k )
    {
        for (int i = 0; i < 100000; i++)
        {
            if (array_counter[i].win_count == k)
            {
                return array_counter[i].elem;
            }
            else continue;
            
        }
        return 0;
        
    }

int getWinner(int* arr, int arrSize, int k) {
    int count=0;
    struct Tupla array_counter[100000];
    while (winner_counter(array_counter,k) == 0)
    {
        if (arr[0]>arr[1])
        {
            put_last(arrSize, arr, arr[1]);
            array_counter[count].elem = arr[0];
            array_counter[count].win_count++;
        }
        else if (arr[0]<arr[1])
        {
            put_last(arrSize,arr,arr[0]);
            array_counter[count].elem = arr[1];
            array_counter[count].win_count++;
        }
        
            
        
    }
    return winner_counter(array_counter,k);
}


int main ()
{
    int a[7] = {2,1,3,5,4,6,7};
    printf("%d\n", getWinner(a,7,2));

}