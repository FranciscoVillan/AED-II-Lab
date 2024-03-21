#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */
#include <assert.h>  /* assert() */

int main ()
{
    FILE *fptr;
    fptr = fopen("/tmp/guest-2yz3v1/Escritorio/code/lab01-kickstart/lab01/input/example-easy.in","r+");
    char buffer[100];

    if (fptr == NULL)
    {
        printf("%i",1);
    }
    
    if (fgets(buffer,100,fptr) != NULL)
    {
        printf("%s", buffer);
    }
    
    fclose(fptr);
    return 0;
    
}
