// Complex.cpp
// application of Complex class
#include "Complex.h"
#include <iostream>
#include <cmath> //così possiamo usare il pi greco M_PI
using namespace std;

extern void emptyLine();

int main(){

  // application of constructors:
  Complex z1 = Complex();
  Complex z2 = Complex::Cartesian(1, 1);
  Complex z3 = Complex::Polar(1, M_PI);
  Complex z7 = Complex::Polar(2, -M_PI*0.5);

  emptyLine();
  cout << "z1: "; // non mettiamo endl per non andare a capo
  z1.print_Cartesian();
  cout << "z2: ";
  z2.print_Cartesian();
  cout << "z3: ";
  z3.print_Polar();
  cout << "z7: ";
  z7.print_Cartesian();
  cout << "z7: ";
  z7.print_Polar();


  // application of setters:
  z1.setX(1.);
  z1.setY(-1.);

  emptyLine();
  cout << "z1: ";
  z1.print_Cartesian();


  //application of getters
  emptyLine();
  cout << "Re[z2] = " << z2.re() << endl;
  cout << "Im[z2] = " << z2.im() << endl;

  //calculation of magnitude
  cout << "|z2| = " << z2.mag() << endl;
  cout << "|z7| = " << z7.r() << endl;

  cout << "Arg(z3) = " << z3.phase() << endl;
  cout << "Arg(z7) = " << z7.phase() << endl;





  emptyLine();

  //the following sums must be the same
  Complex sum1 = z1 + z3;
  Complex sum2 = z1.operator+(z3);

  cout << "z1 + z3: \n" << endl;
  cout << "sum1: ";
  sum1.print_Cartesian();
  cout << "sum2: ";
  sum2.print_Cartesian();

  emptyLine();

  //the following multiplications must be the same
  Complex mul1 = z1 * z2;
  Complex mul2 = z1.operator*(z2);

  cout << "z1 * z2: \n" << endl;
  cout << "mul1: ";
  mul1.print_Cartesian();
  cout << "mul2: ";
  mul2.print_Cartesian();

  emptyLine();

  //the following must be the same
  Complex z4 = z2;
  Complex z5;
  z5.operator=(z2);

  cout << "z4: " << endl;
  z4.print_Cartesian();
  cout << "z5: " << endl;
  z5.print_Cartesian();


  emptyLine();

  //multiplication between a double and a Complex
  Complex mul3 = 2.5 * sum1;
  Complex mul4 = sum1 * 2.5;
  // si può fare soltanto in questo modo

  cout << "mul3: " << endl;
  mul3.print_Cartesian();
  cout << "mul4: " << endl;
  mul4.print_Cartesian();

  emptyLine();


  mul4 += mul2;
  mul3.operator+=(mul1);

  cout << "mul3: " << endl;
  mul3.print_Cartesian();
  cout << "mul4: " << endl;
  mul4.print_Cartesian();

  emptyLine();


  return 0;
}



void emptyLine(){
  cout << "\n" << endl;
}
