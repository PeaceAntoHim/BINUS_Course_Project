/******************************************************************************
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PRICE 2000

int main()
{
    float rentaltime, total;
    char strrentaltime[50];
    
    while (atof(strrentaltime) < 1) { // check minimum rent
        printf("Lama sewa/jam : "); fgets(strrentaltime, sizeof(strrentaltime), stdin); strtok(strrentaltime, "\n");
    }
    printf("\n");
    
    rentaltime = atof(strrentaltime); // keep valid rental time
    total = rentaltime * (double) PRICE;
    
    if (rentaltime > 5) {
        printf("Harga sewa : %g\n", total);
        printf("Diskon : 20%%\n");
        total = total - (total * ((double) 20/100));
    }
    
    printf("Total : %g", total);

    return 0;
}


