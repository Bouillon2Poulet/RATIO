#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "internal.hpp"

#ifndef __RATIONAL__HPP
#define __RATIONAL__HPP


// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// VectorD is a super tool.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
/// 	- [path to build]/doc/doc-doxygen/html/index.html or 
/// 	- or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html



/// \class Rational
/// \brief class defining a number by its rational form
class Rational {

public:
	//////////////////////Constructors

	/// \brief default constructor, creates a Rational equal to zero
    Rational();

	/// \brief constructor from numerator and denominator, PGCD(n,d) = 1
	/// \param n : the const value used as numerator, can be negative
	/// \param d : the const value used as denominator
    Rational(const int n, const unsigned int d);

	/// \brief constructor from an int that is converted into a Rational
	/// \param value : the const value converted into a Rational
    Rational(const int value);

	/// \brief copy-constructor
	/// \param r : the source rational to be copied
	Rational(const Rational & r);

    /// \brief destructor
    ~Rational() = default;


private :

	int _n; /*!< numerator, can be negative */
	unsigned int _d; /*!< denominator, can not be equal to zero */

public :
	/// \brief return the numerator of a Rational
	inline int n() const {
		return _n;
	}

	/// \brief return the denominator of a Rational
	inline unsigned int d() const {
		return _d;
	}

	/// \brief return the invert of a Rational
	inline Rational invert() const {
		if(_n==0||_d==0){
			throw std::invalid_argument("_d = 0");
		}

		return Rational(sign(_n)*_d, std::abs(_n));
	}

	//////////////////////Operators

	/// \brief affectation operator
	void operator=(const Rational &r);


	/// \brief add 2 Rationals
	/// \param r : rational to add to the calling rational
	/// \return the sum of the current Rational and the argument Rational
	Rational operator+(const Rational &r) const;

	/// \brief add a Rational to the calling Rational
	/// \param r : rational to add to the calling rational
	void operator+=(const Rational &r);

	/// \brief unary minus
	/// \return the of minus the calling Rational
	Rational operator-() const;
	
	/// \brief substract 2 Rationals
	/// \param r : Rational to substract to the calling Rational
	/// \return the substract of the current Rational and the argument Rational
	Rational operator-(const Rational &r) const;

	/// \brief substract a rational to the calling Rational
	/// \param r : Rational to substract to the calling Rational
	void operator-=(const Rational &r);

	/// \brief multiply 2 Rationals
	/// \param r : Rational to multiply to the calling Rational
	/// \return the product of the current Rational and the argument Rational
	Rational operator*(const Rational &r) const;

	/// \brief multiply a Rational with a float
	/// \param f : float to multiply to the calling Rational
	/// \return the product of the current Rational and the argument float
	Rational operator*(const float &f) const;

	// /// \brief multiply a Rational with a int
	// /// \param i : int to multiply to the calling Rational
	// /// \return the product of the current Rational and the argument int
	// Rational operator*(const int &i) const;

	/// \brief multiply a Rational to the calling Rational
	/// \param r : Rational to multiply to the calling Rational
	void operator*=(const Rational &r);

	/// \brief divide 2 Rationals
	/// \param r : Rational to divide to the calling Rational
	/// \return the quotient of the current Rational and the argument Rational
	Rational operator/(const Rational &r) const;

	/// \brief divide a rational to the calling Rational
	/// \param r : Rational to divide to the calling Rational
	void operator/=(const Rational &r);

	/// \brief compare if 2 Rationals are equals
	/// \param r : Rational to divide to the calling Rational
	bool operator==(const Rational &r);

	/// \brief compare if 2 Rationals are different
	/// \param r : Rational to divide to the calling Rational
	bool operator!=(const Rational &r);

	/// \brief compare the size of two rationals
	/// \param r : Rational to divide to the calling Rational
	bool operator>(const Rational &r);

	/// \brief compare the size of two rationals
	/// \param r : Rational to divide to the calling Rational
	bool operator>=(const Rational &r);

	/// \brief compare the size of two rationals
	/// \param r : Rational to divide to the calling Rational
	bool operator<(const Rational &r);

	/// \brief compare the size of two rationals
	/// \param r : Rational to divide to the calling Rational
	bool operator<=(const Rational &r);



	//////////////////////Others methods

	/// \brief return the absolute value from the calling Rational
	Rational abs() const;

	/// \brief return the integar part from the calling Rational
	int floor() const;

	/// \brief convert the calling Rational to a float
	/// \return the nearest float from the calling Rational
	float toFloat() const;

	/// \brief return the cos() of the calling Rational (passing by float)
	float cos() const;

	/// \brief return the sin() of the calling Rational (passing by float)
	float sin() const;

	/// \brief return the tan() of the calling Rational (passing by float)
	float tan() const;

	/// \brief return the pow value of the calling Rational
	Rational pow(const unsigned int n) const; 

	/// \brief return the square value of the calling Rational
	Rational sqrt() const; 

	/// \brief return the exp value of the calling Rational
	float exp() const; 

	/// \brief recursive way to convert a float to a Rational
	/// \param f : float to convert to Rationnal
	/// \param nbIter : number of recursive call, greater it is, more precise the conversion will be
	static Rational floatToRational(const float& f, const uint nbIter);
	
};

    /// \brief manage display of a Rational using <<
    /// \param stream : input stream
    /// \param r : the Rational to output
    /// \return the output stream containing the Rational data
    std::ostream& operator<< (std::ostream& stream, const Rational& r);

#endif
