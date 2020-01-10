#include <stdio.h>
#include <math.h>

/*Recebe  os argumentos a, b e c e dois ponteiros, todos double*/
/*e resolve uma equação da forma ax² + bx + c = 0*/
int solucao(double a, double b, double c, double *r1, double *r2) {
   double delta;

   delta = (b * b) - (4 * a * c);
   if (delta >= 0) {
      *r1 = (-b - sqrt(delta)) / (2 * a);
      *r2 = (-b + sqrt(delta)) / (2 * a);
      return 1;
   }
   else
      return 0;
}

int main() {
   double a, b, c, r1, r2;
   a = b = c = r1 = r2 = 0;
   printf("ax² + bx + c = 0\n");
   printf("Informe a, b e c:\n");
   scanf("%lf %lf %lf", &a, &b, &c);
   if (solucao(a, b, c, &r1, &r2)) {
      printf("R1 = %f e R2 = %f", r1, r2);
      printf("\n");
   }
   else
      printf("Nao ha solucao\n");

   return 0;
}
