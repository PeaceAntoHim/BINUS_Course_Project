#include<stdio.h>  
int fib(int);  
void main () {  
  int num=20,fibo;  
  printf("Membuat program sederhana fibonacci memakai recursive function \n\n");
  fibo = fib(num);  
  printf("Hasil perhitungan: %d",fibo);  
} 

int fib(int num) {  
    
  if (num==0) {  
    return 0;  
  } else if(num == 1) {  
    return 1;   
  } else {  
    return fib(num-1)+fib(num-2);  
  }  
  
}
