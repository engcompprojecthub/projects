#include <stdio.h>

/*O programa recebe a quantidade de dinheiro (um número real)
e dará a menor quantidade de notas e moedas possível para o valor dado*/
int main() {
    float N;
    int M, d, notas[6], moedas[6], x;

    M = d = 0;

    for (x = 0; x < 6; x++) {
        notas[x] = moedas[x] = 0;
    }

    scanf("%f", &N);

    while (N >= 2.00) {
        if (N >= 100.00) {
            notas[0] = (int) N/100;
            N -= notas[0] * 100;
        }
        else if (N >= 50.00 && N < 100.00) {
            notas[1] = (int) N/50;
            N -= notas[1] * 50;
        }
        else if (N >= 20.00 && N < 50.00) {
            notas[2] = (int) N/20;
            N -= notas[2] * 20;
        }
        else if (N >= 10.00 && N < 20.00) {
            notas[3] = (int) N/10;
            N -= notas[3] * 10;
        }
        else if (N >= 5.00 && N < 10.00) {
            notas[4] = (int) N/5;
            N -= notas[4] * 5;
        }
        else if (N >= 2.00 && N < 5.00) {
            notas[5] = (int) N/2;
            N -= notas[5] * 2;
        }
        else
            break;
    }

    M = (int) (N * 100);
    d = (int) (N * 1000);

    d = d % 1000;
    d = d % 100;
    d = d % 10;

    if (d >= 5)
        M++;
    while (M > 0) {
        if (M >= 100 && M < 200) {
            moedas[0] = (int) M/100;
            M -= moedas[0] * 100;
        }
        else if (M >= 50 && M < 100) {
            moedas[1]++;
            M -= 50;
        }
        else if (M >= 25 && M < 50) {
            moedas[2]++;
            M -= 25;
        }
        else if (M >= 10 && M < 25) {
            moedas[3]++;
            M -= 10;
        }
        else if (M >= 5 && N < 10) {
            moedas[4]++;
            M -= 5;
        }
        else if (M >= 0 && M < 5) {
            moedas[5]++;
            M--;
        }
        else
            break;
    }
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notas[0]);
    printf("%d nota(s) de R$ 50.00\n", notas[1]);
    printf("%d nota(s) de R$ 20.00\n", notas[2]);
    printf("%d nota(s) de R$ 10.00\n", notas[3]);
    printf("%d nota(s) de R$ 5.00\n", notas[4]);
    printf("%d nota(s) de R$ 2.00\n", notas[5]);
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moedas[0]);
    printf("%d moeda(s) de R$ 0.50\n", moedas[1]);
    printf("%d moeda(s) de R$ 0.25\n", moedas[2]);
    printf("%d moeda(s) de R$ 0.10\n", moedas[3]);
    printf("%d moeda(s) de R$ 0.05\n", moedas[4]);
    printf("%d moeda(s) de R$ 0.01\n", moedas[5]);

    return 0;

}
