// Complex.cc
// Implementation of the Complex class

#include "Complex.h"
#include <iostream>
#include <cmath>


//constructors
Complex::Complex(double x, double y){
  x_=x;
  y_=y;
}

Complex::Complex(){
  x_=0.;
  y_=0.;
}


//static constructors
Complex Complex::Polar(double r, double phi){
  if(r>=0.){
    return Complex(r*cos(phi), r*sin(phi));
  }
  else {
    std::cout << "\n IL MODULO DEL NUMERO COMPLESSO DEVE ESSERE POSITIVO \n" << std::endl;
    return Complex(0,0);
  }
}

Complex Complex::Cartesian(double x, double y){
  return Complex(x, y);
}


//utility
void Complex::print_Cartesian(){
  if(y_>0 || y_==0){
    if(y_==1){
      std::cout << "z = " << x_ << " + i" << std::endl;
    }
    else if(y_==0){
      std::cout << "z = " << x_ << std::endl;
    }
    else{
      std::cout << "z = " << x_ << " + " << y_ << "*i" << std::endl;
    }
  }

  else if(y_<0){
    if(y_==-1){
      std::cout << "z = " << x_ << " - i" << std::endl;
    }
    else{
      std::cout << "z = " << x_ << " " << y_ << "*i" << std::endl;
    }
  }
}
void Complex::print_Polar(){
  if(phase()>=0){
    std::cout << "z = " << mag() << "* exp{i * "<< phase() <<"}" << std::endl;
  }
  else {
    std::cout << "z = " << mag() << "* exp{-i * "<< fabs(phase()) <<"}" << std::endl;
  }
}


//setters
void Complex::setX(double x){
  x_=x;
}
void Complex::setY(double y){
  y_=y;
}


//getters
double Complex::re(){
  return x_;
}
double Complex::im(){
  return y_;
}


//calculation of magnitudo or modulus
double Complex::mag(){
  return sqrt(x_*x_+y_*y_);
}
double Complex::r(){
  return Complex::mag();
}

//calculation of phase
double Complex::phase(){
  if(x_>0){
    return atan(y_/x_);
  }
  else if(x_<0){
    if(y_<0){
      return ( atan(y_/x_) - M_PI );
    }
    else return ( atan(y_/x_) + M_PI );
  }
  else { // if(x==0)
    if(y_>0){
      return M_PI*0.5;
    }
    else if(y_<0){
      return -M_PI*0.5;
    }
    else return 0.;
  }
}
double Complex::phi(){
  return Complex::phase();
}





//Overload +
Complex Complex::operator+(Complex& rhs){ // l'argomento è un indirizzo
  double valX = x_+rhs.x_;
  double valY = y_+rhs.y_;
  return Complex::Cartesian(valX, valY);
}

//Overload *
Complex Complex::operator*(Complex& rhs){
  Complex This= *this;
  double R = This.mag() * rhs.mag();
  double Phi = This.phi() + rhs.phi();
  return Complex::Polar(R, Phi);
}
/* We could do it in one another way using: (a+ib)(c+id)=(ac-bd)+i(bc+ad)
//Overload *
Complex Complex::operator*(Complex& rhs){
  X = (x_ * rhs.x_) - (y_ * rhs.y_);
  Y = (y_ * rhs.x_) + (x_ * rhs.y_);
  return Complex::Cartesian(X, Y);
}
*/


//Overload =
Complex Complex::operator=(Complex& rhs){
  x_ = rhs.x_;
  y_ = rhs.y_;
  return *this;
}

Complex Complex::operator+=(Complex& rhs){
  x_ += rhs.x_;
  y_ += rhs.y_;
  return *this;
}




//global functions
//product between a double and a Complex
Complex operator*(double& lhs, Complex& rhs){
return Complex::Cartesian(lhs*rhs.re(), lhs*rhs.im());
}

Complex operator*(Complex& lhs, double& rhs){
return operator*(rhs, lhs);
}
