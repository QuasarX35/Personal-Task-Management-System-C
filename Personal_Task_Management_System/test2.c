#include <stdio.h>
#include <stdlib.h>

#include <math.h>


int reverse(double num) {
    double final_num, pow_10;

    if (num > 0) {
        while (num != 0) {
            pow_10 = floor(log10(num));
            final_num += (fmod(num, 10)) * (pow(10, pow_10));
            num = floor(num / 10);
        }
        return floor(final_num);
    }
    return 0;
}

int main() {
    double input = 1512;
    double pow_10 = floor(log10(input));
    // printf("%f", reverse(1512));

    printf("%.f\n", pow_10);
    printf("%.f\n", (fmod(input, 10)) * (pow(10, pow_10)));
    
    char stop;
    printf("\nEnter anything to continue: ");
    scanf("%c", &stop);
    return 0;
}