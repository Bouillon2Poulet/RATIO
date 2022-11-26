#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>

#include <fstream>


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
		return Rational(_d,_n);
	}


	/// \brief affectation operator
	Rational & operator=(const Rational &r);


	/// \brief add 2 Rationals
	/// \param r : rational to add to the calling rational
	/// \return the sum of the current Rational and the argument Rational
	Rational operator+(const Rational &r) const;

	/// \brief substract 2 Rationals
	/// \param r : Rational to substract to the calling Rational
	/// \return the substract of the current vector and the argument vector
	Rational operator-(const Rational &vec) const;


	/// \brief unary minus
	/// \return the minus the calling Rational
	Rational operator-() const;

	/// \brief multiply 2 Rationals
	/// \param r : Rational to multiply to the calling Rational
	/// \return the product of the current vector and the argument vector
	Rational operator*(const Rational &r) const;

	/// \brief divide 2 Rationals
	/// \param r : Rational to divide to the calling Rational
	/// \return the quotient of the current vector and the argument vector
	Rational operator/(const Rational &r) const;
	/*
	/// \brief scale a vector with a constant value
	/// \param value : scale factor
	/// \return the scaled vector
	VectorD operator*(const double &value) const;

	/// \brief compute the norm L2 of a vector
	/// \return the L2 norm of the calling vector
	/// \bug no bug at all, but I know this function exists, just in case.
    double norm() const;

	/// \brief inplace normalize a vector such its norm is 1.
	/// \test try normalize null vector.
    void normalize();

    /// \brief compute the inner product between 2 vectors
    /// \param v : the second vector to consider in the dot product.
    /// \return : the scalar value corresponding to the dot product. 
    double dot(const VectorD &v) const;

    /// \brief save a vector in a file
    /// \param filename : name of the file (including path) where to save the vector data
    /// \throw exception if can not open file
    void save(const std::string &filename) const;

    /// \brief load a vector from a file, the size of the vector should be already the good one ...
    /// \param filename : name of the file (including path) to open and load the vector data
    /// \throw exception if can not open file
    /// \todo : make a nice todo list :)
    void load(const std::string &filename);

    /// \brief display the elements of the vector
    void display() const;
*/
};


	// /// \brief scale a vector with a constant value
	// /// \param value : scale factor
	// /// \param vec is the vector to be scaled
	// /// \return the scaled vector
	// VectorD operator*(const double value, const VectorD &vec);

	// /// \brief overload the operator << for VectorD
    // /// \param stream : input stream
    // /// \param v : the vector to output
    // /// \return the output stream containing the vector data
    // std::ostream& operator<< (std::ostream& stream, const VectorD& v);

#endif
