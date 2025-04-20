#include <stdio.h>

/* 
    Nama: Frans Sebastian
    Nim: 2502121162
    Materi: Bubble Short
*/

int main() {

    // Declaration sample data
    int sample[] = {10, 4, 7, 9, 5};
    int n = sizeof(sample) / sizeof(int);
    
    // Loop for create new data and put at temp
    for(int i = 1; i < n; i++) {
        for(int j = n-1; j >= 1; j--) {
            if(sample[j-1] > sample[j]) {
                int temp = sample[j-1];
                sample[j-1] = sample[j];
                sample[j] = temp;
            }
        }
    }
    
    printf("Output sample setelah diolah menggunakan Bubble Short : \n");
    // This will loop data at sample and will print
    for(int i = 0; i < n; i++) {
        printf("%d ", sample[i]);
    }
    
    return 0;
}