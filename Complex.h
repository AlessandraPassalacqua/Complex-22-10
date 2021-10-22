// Complex.h
// header file of the Complex class



class Complex {

private:

  // data members
  double x_, y_;
  // double r_, phi_;

  // constructor
  Complex(double x, double y);



public:

  //constructor
  Complex();

  // static to invoke private constructor
  static Complex Polar(double r, double phi);
  static Complex Cartesian(double x, double y);

  // utility function to display coordinates (print)
  void print_Cartesian();
  void print_Polar();

  // setter
  void setX(double x);
  void setY(double y);
  void setR(double r);
  void setPhi(double phi);

  // getters
  double re();
  double im();
  // caculation of magnitudo or modulus
  double mag();
  double r();
  // calculation of phase
  double phase();
  double phi();


  // overload + (z1+z2 corresponds to z1.operator+(z2))
  Complex operator+(Complex& rhs);


  // overload *
  Complex operator*(Complex& rhs);


  // overload =
  // it is strange because if I put Complex& it doesn't work.
  Complex operator=(Complex& rhs);

  Complex operator+=(Complex& rhs);

};

//Global function that overloads operator* between Complex and double
Complex operator*(double& lhs, Complex& rhs);
Complex operator*(Complex& lhs, double& rhs);
