#ifndef RATIO_H_INCLUDED
#define RATIO_H_INCLUDED
#include <iostream>

class Ratio {
   private:
    long num, den;

   public:
    /*
    no default ctor
    The default (no-argument) ctor for Ratio must fail to compile. This is not a run-time error; it’s a compile-time error.
    */
    Ratio() = delete;

    /*
    no floating-point ctors
    Ratio(float), Ratio(double), and Ratio(long double) must all fail to compile.
    */
    Ratio(float) = delete;
    Ratio(double) = delete;
    Ratio(long double) = delete;

    /*
    Ratio(long numerator, long denominator)
    Create a ratio representing the fraction numerator/denominator. If the denominator is not given, assume a denominator of one. If the denominator is zero, throw a runtime_error with an appropriate string.
    */
    Ratio(long numerator, long denominator = 1l);

    /*
    Ratio(int numerator, int denominator)
    Same as above, but using ints rather than longs.
    */
    Ratio(int numerator, int denominator = 1);

    /*
    Copy constructor
    Copy all information from another object of the same class.
    */
    Ratio(const Ratio&);

    /*
    Assignment operator
    Copy all information from another object of the same class, replacing any previous information.
    */
    Ratio operator=(const Ratio&);

    /*
    Destructor
    Destroy.
    */
    ~Ratio();

    /*
    .numerator()
    Return the numerator as a long.
    */
    long numerator() const;

    /*
    .numerator(long)
    Set the numerator.
    */
    void numerator(long numer);

    /*
    .denominator()
    Return the denominator as a long.
    */
    long denominator() const;

    /*
    .denominator(long)
    Set the denominator. If the denominator is zero, throw a runtime_error with an appropriate string, and leave the object unchanged.
    */
    void denominator(long deno);

    /*
    .ratio()
    Return a long double representing the fraction. For example, Ratio(3,4).ratio() would return a long double with the value 0.75L.
    */
    long double ratio() const;

    /*
    .normalize()
    Every operation must result in a normalized  Ratio:
    It must be reduced to lowest terms (66660/88880 becomes 3/4).
    The denominator must be positive (−4/−3 becomes 4/3, and 9/−100 becomes −9/100).
    If the numerator is zero, a non-zero denominator must be one (0/4627 becomes 0/1).
    */
    void normalize();

    /*
    Add/subtract/multiply/divide the two ratios, yielding another Ratio, returned by value. Do not modify either operand. If division results in a divisor of zero, throw a runtime_error with an appropriate string.
    short/int/long +/-* Ratio
    Either operand can also be short, int, or long. For example, for a Ratio r, r+3 and 435L/r are valid. Some might be definable as methods or as functions         
    */

    /*
    Ratio + Ratio
    */
    Ratio operator+(const Ratio& r) const;

    /*
    Ratio - Ratio
    */
    Ratio operator-(const Ratio& r) const;

    /*
    Ratio * Ratio
    */
    Ratio operator*(const Ratio& r) const;

    /*
    Ratio / Ratio
    */
    Ratio operator/(const Ratio& r) const;

    /*
    Ratio + long/int/short
    */
    Ratio operator+(const long& l) const;

    /*
    Ratio - long/int/short
    */
    Ratio operator-(const long& l) const;

    /*
    Ratio * long/int/short
    */
    Ratio operator*(const long& l) const;

    /*
    Ratio / long/int/short
    */
    Ratio operator/(const long& l) const;

    /*
    Combine the two operands with the corresponding arithmetic operation, and replace the left-hand side with the resulting value. Do not modify the right-hand operand. The right-hand operand can also be short, int, or long.
    */

    /*
    Ratio += Ratio
    */
    Ratio operator+=(const Ratio& r);

    /*
    Ratio -= Ratio
    */
    Ratio operator-=(const Ratio& r);

    /*
    Ratio *= Ratio
    */
    Ratio operator*=(const Ratio& r);

    /*
    Ratio /= Ratio
    */
    Ratio& operator/=(const Ratio& r);

    // /*
    // Ratio += long/int/short
    // */
    // Ratio& operator+=(const long &l);

    // /*
    // Ratio -= long/int/short
    // */
    // Ratio& operator-=(const long &l);

    // /*
    // Ratio *= long/int/short
    // */
    // Ratio& operator*=(const long &l);

    // /*
    // Ratio /= long/int/short
    // */
    // Ratio& operator/=(const long &l);

    /*
    Compare two ratios, return true if the condition is true. Ether operand can also be any of short, int, long, float, double or long double.
    // */

    /*
    Ratio == Ratio
    */
    friend bool operator==(const Ratio& r1, const Ratio& r2);

    /*
    Ratio != Ratio
    */
    friend bool operator!=(const Ratio& r1, const Ratio& r2);

    /*
    Ratio <  Ratio
    */
    friend bool operator<(const Ratio& r1, const Ratio& r2);

    /*
    Ratio <= Ratio
    */
    friend bool operator<=(const Ratio& r1, const Ratio& r2);

    /*
    Ratio >  Ratio
    */
    friend bool operator>(const Ratio& r1, const Ratio& r2);

    /*
    Ratio >= Ratio
    */
    friend bool operator>=(const Ratio& r1, const Ratio& r2);

    /*
    Ratio == long double
    */
    friend bool operator==(const Ratio& r1, const long double& d);

    /*
    Ratio != long double
    */
    friend bool operator!=(const Ratio& r1, const long double& d);

    /*
    Ratio <  long double
    */
    friend bool operator<(const Ratio& r1, const long double& d);

    /*
    Ratio <= long double
    */
    friend bool operator<=(const Ratio& r1, const long double& d);

    /*
    Ratio >  long double
    */
    friend bool operator>(const Ratio& r1, const long double& d);

    /*
    Ratio >= long double
    */
    friend bool operator>=(const Ratio& r1, const long double& d);


    /*
    long double == Ratio
    */
    friend bool operator==(const long double& d, const Ratio& r2);

    /*
    long double != Ratio
    */
    friend bool operator!=(const long double& d, const Ratio& r2);

    /*
    long double <  Ratio
    */
    friend bool operator<(const long double& d, const Ratio& r2);

    /*
    long double <= Ratio
    */
    friend bool operator<=(const long double& d, const Ratio& r2);

    /*
    long double >  Ratio
    */
    friend bool operator>(const long double& d, const Ratio& r2);

    /*
    long double >= Ratio
    */
    friend bool operator>=(const long double& d, const Ratio& r2);
};

/*
long/int/short + Ratio
*/
Ratio operator+(const long& l, const Ratio& r);

/*
long/int/short - Ratio
*/
Ratio operator-(const long& l, const Ratio& r);

/*
long/int/short * Ratio
*/
Ratio operator*(const long& l, const Ratio& r);

/*
long/int/short / Ratio
*/
Ratio operator/(const long& l, const Ratio& r);

/*
Non-methods: 
*/

/*
ostream << Ratio
Write the numerator, a slash, and the denominator to the ostream. Nothing else—no whitespace.
*/
std::ostream& operator<<(std::ostream& os, const Ratio& r);

/*
istream >> Ratio
Read a long numerator, a slash, and a long denominator from the istream, skipping optional whitespace before each one. If an error occurs, set the state of the
istream to failure, and leave the Ratio object unchanged. A zero divisor can either cause istream failure, throw a runtime_error, or both.  
*/
std::istream& operator>>(std::istream& is, Ratio& r);

#endif /* EVENT_H_INCLUDED */