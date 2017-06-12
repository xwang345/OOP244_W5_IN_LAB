// Created by Xiaochen Wang
// Student ID: 015297153
// TODO: insert header files
#include <iostream>
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;

namespace sict{
    // TODO: implement the default constructor
    Fraction::Fraction() {
        m_numerator = 0;
        m_denominator = 0;
    }

    // TODO: implement the two-argument constructor
    Fraction::Fraction(int n, int d) {
        if(n >= 0 && d >= 0){
            m_numerator = n;
            m_denominator = d;
            reduce();
        }else{
            m_denominator = 0;
            m_numerator = 0;
        }
    }

    // TODO: implement the max query
    // max returns the maximum of the numerator and denominator
    int Fraction::max() const {
        return (m_numerator > m_denominator) ? m_numerator : m_denominator;
    }

    //

    // TODO: implement the min query
    // min returns the maximum of the numerator and denominator
    //
    int Fraction::min() const {
        return (m_numerator > m_denominator) ? m_denominator : m_numerator;
    }

    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = max();  // min of numerator and denominator
        int mx = min();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    // reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
    //
    void Fraction::reduce() {
        int tmp = gcd();
        m_numerator /= tmp;
        m_denominator /= tmp;

    }

    // TODO: implement the display query
    // display inserts num/denom into the output stream
    //
    void Fraction::display() const {
        if(isEmpty()){
            cout << "no fraction stored";
        } else {
            if(m_denominator == 1){
                cout << m_numerator;
            } else {
                cout << m_numerator << "/" << m_denominator;
            }
        }
    }


    // TODO: implement the isEmpty query
    // isEmpty returns true if Fraction object is in a safe empty state
    //
    bool Fraction::isEmpty() const {
        return (m_denominator == 0) ? true : false;
    }

    // TODO: implement the + operator
    // + operator adds the rhs to the current object and reduces the result
    //
    Fraction Fraction::operator+(Fraction s) {
        Fraction Res;
        if(!(isEmpty() || s.isEmpty())) {
            Res.m_numerator = m_denominator *s.m_numerator + m_numerator * s.m_denominator;
            Res.m_denominator = m_denominator * s.m_denominator;
        }
        return Res;
    }

}



