/*
Glen McItntosh
CS-253 HW6
4-20-23
*/

#include "Ratio.h"
#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <numeric>

using namespace std;

Ratio::Ratio(long numerator, long denominator) : num(numerator), den(denominator) { normalize(); }

Ratio::Ratio(int numerator, int denominator) : num(static_cast<long>(numerator)), den(static_cast<long>(denominator)) { normalize(); }

Ratio::Ratio(const Ratio& rhs) : num(rhs.num), den(rhs.num) { normalize(); }

Ratio::~Ratio() {}

long Ratio::numerator() const {
    return num;
}

void Ratio::numerator(long numerate) {
    num = numerate;
    normalize();
}

long Ratio::denominator() const {
    return den;
}

void Ratio::denominator(long denom) {
    if (denom == 0) {
        throw runtime_error("divide by zero");
    }
    den = denom;
    normalize();
}

long double Ratio::ratio() const {
    long double num_double = num;
    long double den_double = den;
    
    return num_double / den_double;
}

void Ratio::normalize() {
    if (den == 0) {
        throw runtime_error("divide by 0");
    }
    if (num == 0) {
        den = 1l;
    }

    if (den < 0) {
        num = (num * -1);
        den = (den * -1);
    }

    long dl = __gcd(num, den);
    long new_num = num / dl;
    num = new_num;
    long new_den = den / dl;
    den = new_den;
}

Ratio Ratio::operator=(const Ratio& rhs) {
   
    if (this != &rhs) {  // avoid self-assignment
        num = rhs.num;
        den = rhs.den;
    }
    //return *this;
    return Ratio(num,den);
   
}

Ratio Ratio::operator+(const Ratio& r) const {
    long common_den = den * r.den;
    long new_num1 = num * r.den;
    long new_num2 = r.num * den;
    long sum = new_num1 + new_num2;
    return Ratio(sum, common_den);
}

Ratio Ratio::operator-(const Ratio& r) const {
    long numa = (num * r.den) - (r.num * den);
    long denon = den * r.den;

    return Ratio(numa, denon);
}

Ratio Ratio::operator*(const Ratio& r) const {
    long numbe = this->num * r.num;
    long denon = this->den * r.den;
    return Ratio(numbe, denon);
}

Ratio Ratio::operator/(const Ratio& r) const {
    if (r.num == 0) {
        throw std::runtime_error("Divide by zero error");
    }
    // num *= r.denominator();
    // den *= r.num;
    //normalize();
    long new_num = this->num * r.den;
    long new_den = this->den * r.num;
    return Ratio(new_num, new_den);
}

Ratio Ratio::operator+(const long& l) const {
    Ratio r(l);
    return *this + r;
}

Ratio Ratio::operator-(const long& l) const {
    Ratio r(l);
    return *this - r;
}

Ratio Ratio::operator*(const long& l) const {
    Ratio r(l);
    return *this * r;
}

Ratio Ratio::operator/(const long& l) const {
    Ratio r(l);
    return *this / r;
}


Ratio Ratio::operator+=(const Ratio& r) {
    

    return *this + r;
}

Ratio Ratio::operator-=(const Ratio& r) {
    

    return *this - r;
}

Ratio Ratio::operator*=(const Ratio& r) {
    
    return *this * r;
}

Ratio& Ratio::operator/=(const Ratio& r) {
    
    *this = *this / r; 
    return *this;
}

// /**/

// Ratio& Ratio::operator+=(const long &l){
//     Ratio r(l);
//     *this = *this + r; 
//     return *this;
// }

// Ratio& Ratio::operator-=(const long &l){
//     Ratio r(l);
//     *this = *this - r; 
//     return *this;
// }

// Ratio& Ratio::operator*=(const long &l){
//     Ratio r(l);
//     *this = *this * r; 
//     return *this;
// }

// Ratio& Ratio::operator/=(const long &l){
//     Ratio r(l);
//     *this = *this / r; 
//     return *this;
//}

/*Ratio to Raito*/
bool operator==(const Ratio& r1, const Ratio& r2) {
    return (r1.ratio() == r2.ratio());
}

bool operator!=(const Ratio& r1, const Ratio& r2) {
    return (!(r1 == r2));
}

bool operator<(const Ratio& r1, const Ratio& r2) {
    return r1.ratio() < r2.ratio();
}

bool operator<=(const Ratio& r1, const Ratio& r2) {
    return r1.ratio() <= r2.ratio();
}

bool operator>(const Ratio& r1, const Ratio& r2) {
    return r1.ratio() > r2.ratio();
}

bool operator>=(const Ratio& r1, const Ratio& r2) {
    return r1.ratio() >= r2.ratio();
}


/*Ratio to long double/double/long/int/short*/
bool operator==(const Ratio& r1, const long double& d) {
    return r1.ratio() == d;
}

bool operator!=(const Ratio& r1, const long double& d) {
    return r1.ratio() != d;
}

bool operator<(const Ratio& r1, const long double& d) {
    return r1.ratio() < d;
}

bool operator<=(const Ratio& r1, const long double& d) {
    return r1.ratio() <= d;
}

bool operator>(const Ratio& r1, const long double& d) {
    return r1.ratio() > d;
}

bool operator>=(const Ratio& r1, const long double& d) {
    return r1.ratio() >= d;
}

/*long double/double/long/int/short to Ratio*/
bool operator==(const long double& d, const Ratio& r2) {
    return d == r2.ratio();
}

bool operator!=(const long double& d, const Ratio& r2) {
    return d != r2.ratio();
}

bool operator<(const long double& d, const Ratio& r2) {
    return d < r2.ratio();
}

bool operator<=(const long double& d, const Ratio& r2) {
    return d <= r2.ratio();
}

bool operator>(const long double& d, const Ratio& r2) {
    return d > r2.ratio();
}

bool operator>=(const long double& d, const Ratio& r2) {
    return d >= r2.ratio();
}

Ratio operator+(const long& l, const Ratio& r) {
    return Ratio(l) + r;
}

Ratio operator-(const long& l, const Ratio& r) {
    return Ratio(l) - r;
}

Ratio operator*(const long& l, const Ratio& r) {
    return Ratio(l) * r;
}

Ratio operator/(const long& l, const Ratio& r) {
    return Ratio(l) / r;
}

ostream& operator<<(ostream& os, const Ratio& r) {
    os << r.numerator() << "/" << r.denominator();
    return os;
}

istream& operator>>(istream& is, Ratio& r) {
    is >> std::ws;

    int numerator;
    if (!(is >> numerator)) {
        is.setstate(std::ios::failbit);  // Set the state to failure
        return is;
    }

    is >> std::ws;

    char slash;
    if (!(is >> slash) || slash != '/') {
        is.setstate(std::ios::failbit);
        return is;
    }

    is >> std::ws;

    int denominator;
    if (!(is >> denominator)) {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (denominator == 0) {
        is.setstate(std::ios::failbit);
        throw std::runtime_error("Divide by zero error");
    }

    r = Ratio(numerator, denominator);
    return is;
}

long gcd(long a, long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

/*Geeks for Geeks*/
long lcm(long a, long b) {
    long product = a * b;
    long gcdValue = gcd(a, b);
    long lcmValue = product / gcdValue;
    return lcmValue;
}