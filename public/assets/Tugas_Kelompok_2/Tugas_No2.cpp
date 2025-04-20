#include <stdio.h>

int main()
{
    int A = 2, B = 3, C = 4, K = 5, L = 6, M = 7;
 	
    printf("D=(4+2 > A&&B–2 > 3+2 || B+2 <= 6+2) = %s\n", ((4 + 2 > A) && (B - 2 > 3 + 2) || (B + 2 <= 6 + 2)) ? "true" : "false");
    printf("D=K+5 < M || (C*M <L&&2*M–L > 0 = %s\n",  ((K + 5 < M) || (C * M < L) && (2 * M - L > 0)) ? "true" : "false");
    printf("D=L+5<M || C*K < L&&2*K–L > 0 = %s\n", ((L + 5 < M) || (C * K < L) && (2 * K - L > 0)) ? "true" : "false"); 
    printf("D=A*4 <= 3*M+B = %s\n", (A * 4 <= 3 * M + B) ? "true" : "false");
    printf("D=K+10 > A&&L–2 > 4*C = %s", ((K + 10 > A) && (L - 2 > 4 * C)) ? "true" : "false");

    return 0;
}



