#include <stdio.h>

/* 
    Nama: Frans Sebastian
    Nim: 2502121162
    Materi: Selection Sort
*/

int main() {
    
    // Declaration sample data
    int sample[] = {10, 4, 7, 9, 5};
    int n = sizeof(sample) / sizeof(int);
    
    // Loop for create new data and put at temp
    for(int i = 0; i < n-1; i++) {
        int key_id = i;
        for(int j = i+1; j < n; j++) {
            if(sample[key_id] > sample[j]) key_id = j;
        }
            if(key_id > i) {
            int temp = sample[i];
            sample[i] = sample[key_id];
            sample[key_id] = temp;
        }
    }
    
    printf("Output sample setelah diolah menggunakan Selection Sort : \n");
     // This will loop data at sample and will print
    for(int i = 0; i < n; i++) {
        printf("%d ", sample[i]);
        
    }

    return 0;
}
