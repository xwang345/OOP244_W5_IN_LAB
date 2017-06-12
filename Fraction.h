// Student Name: Xiaochen Wang
// Student ID: 015297153
// TODO: header file guard
#ifndef SICT_FRACTION_H_
#define SICT_FRACTION_H_


// TODO: create namespace
using namespace std;

namespace sict {
    // TODO: define the Fraction class
    class Fraction {
    private:
        int m_numerator;
        int m_denominator;
        int gcd() const; // returns the greatest common divisor of num and denom
        int max() const; // returns the maximum of num and denom
        int min() const; // returns the minimum of num and denom
    public:
        // TODO: declare the member functions
        void reduce(); // simplifies a Fraction by dividing the
        // numerator and denominator to their greatest common divisor
        Fraction();
        Fraction(int n, int d);

        void display() const;
        bool isEmpty() const;

        // TODO: declare the + operator overload
        Fraction operator+(Fraction);
    };
};
#endif
