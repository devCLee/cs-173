//========================================================
// getReal
// Author: Ashwath Pratheep
/// Returns the real part of the complex number.
/// parameters - float - the real part of the complex number
//========================================================
float Complex::getReal() const {
    return a;
}

//========================================================
// Copy Constructor
// Author: Ashwath Pratheep
/// Creates a new Complex object as a copy of another.
/// parameter c - the Complex object to copy
//========================================================
Complex::Complex(const Complex& c) {
    a = c.a;
    b = c.b;
}

//========================================================
// operator==
// Author: Ashwath Pratheep
/// Compares two Complex numbers for equality.
/// parameter c - the Complex number to compare with
/// Returns: True if both real and imaginary parts are equal
//========================================================
bool Complex::operator==(const Complex& c) const {
    return (a == c.a) && (b == c.b);
}

//========================================================
// operator+
// Author: Ashwath Pratheep
///Adds a float to the real part of the complex number.
/// parameter f - the float value to add
/// Returns: a new Complex object with updated real part
//========================================================

Complex Complex::operator+(float f) const {
    return Complex(a + f, b);
}

//========================================================
// operator-
// Author: Ashwath Pratheep
/// Subtracts another Complex number from this one.
/// parameter c - the Complex number to subtract
/// Returns: a new complex object representing the difference.
//========================================================
Complex Complex::operator-(const Complex& c) const {
    return Complex(a - c.a, b - c.b);
}

//========================================================
// operator*
// Author: Ashwath Pratheep
/// Multiplies this Complex number with another.
/// parameter c - the Complex number to multiply with
/// Returns: a new Complex object representing the product
//========================================================
Complex Complex::operator*(const Complex& c) const {
    float real = (a * c.a) - (b * c.b);
    float imag = (a * c.b) + (b * c.a);
    return Complex(real, imag);
}

//========================================================
// operator/
// Author: Ashwath Pratheep
/// Divides this Complex number by a float.
/// parameter f - the float divisor
/// Returns: a new Complex object representing the quotient
//========================================================
Complex Complex::operator/(float f) const {
    if (f == 0) {
        cerr << "Division by zero!" << endl;
        exit(1);
    }
    return Complex(a / f, b / f);
}

//========================================================
// operator>>
// Author: Ashwath Pratheep
/// Overloads the >> operator to read a Complex number
/// in the format (real, imaginary).
/// parameter in - input stream
/// parameter c - Complex object to populate
/// Returns: reference to input stream
//========================================================
istream& operator>>(istream& in, Complex& c) {
    char ch;
    in >> ch; // (
    in >> c.a;
    in >> ch; // ,
    in >> c.b;
    in >> ch; // )
    return in;
}

//========================================================
// Unary negation operator
// Author: Ashwath Pratheep
/// Returns the negation of the Complex number.
/// Returns: a new Complex object with both parts negated
//========================================================
Complex Complex::operator-() const {
    return Complex(-a, -b);
}
