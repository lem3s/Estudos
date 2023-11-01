#include <stdio.h>
#include <math.h>


#define PI 3.14159265

double area_circulo(double raio);
double area_elipse(double a, double b);
double area_triangulo(double a, double b, double c);
double area_trapezio(double bb, double sb, double h);

int main(void){

  int n, i;

  scanf("%d", &n);
  double res[n];

  for (i=0; i < n; i++){
    double temp1, temp2, temp3;
    char identifier;
    getchar();
    scanf("%c", &identifier);

    switch(identifier){
      case('C'):
        scanf("%lf", &temp1);
        res[i] = area_circulo(temp1);
        break;
      case('E'):
        scanf("%lf %lf", &temp1, &temp2);
        res[i] = area_elipse(temp1, temp2);
        break;
      case('T'):
        scanf("%lf %lf %lf", &temp1, &temp2, &temp3);
        res[i] = area_triangulo(temp1, temp2, temp3);
        break;
      case('Z'):
        scanf("%lf %lf %lf", &temp1, &temp2, &temp3);
        res[i] = area_trapezio(temp1, temp2, temp3);
        break;
    }

    for (i=0; i < n; i++){
      printf("%.0lf\n", round(res[i]));
    } 
  }

  return 0;
}

double area_circulo(double raio){
  return PI * pow(raio,2);
}

double area_elipse(double a, double b){
  return PI * a * b;
}

double area_triangulo(double a, double b, double c){
  int p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

double area_trapezio(double bb, double sb, double h){
  return (bb + sb) * h / 2;
}

