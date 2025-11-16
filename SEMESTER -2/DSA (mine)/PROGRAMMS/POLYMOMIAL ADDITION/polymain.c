#include <stdio.h>
#include "poly.h"
int main(){
  POLY A, B, C;
  printf("\nEnter the details of polynomial A");
  A = createPoly();
  printf("\nEnter the details of polynomial B");
  B = createPoly();
  printf("\nPolynomial A: ");
  displayPoly(A);
  printf("\nPolynomial B: ");
  displayPoly(B);
  C = addPoly(A, B);
  
  printf("\nPolynomial C: ");
  displayPoly(C);
  deletePoly(A);
  deletePoly(B);
  deletePoly(C);
  return 0;  
}
