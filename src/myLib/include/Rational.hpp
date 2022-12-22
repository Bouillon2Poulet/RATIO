#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <type_traits>

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
template <typename T = int>
class Rational {

public:
	//////////////////////Constructors

	/// \brief default constructor, creates a Rational equal to zero
    Rational();

	/// \brief constructor from numerator and denominator, PGCD(n,d) = 1
	/// \param n : the const value used as numerator, can be negative
	/// \param d : the const value used as denominator
    Rational(const T n, const unsigned int d);

	/// \brief constructor from an int that is converted into a Rational
	/// \param value : the const value converted into a Rational
    Rational(const T value);

	/// \brief copy-constructor
	/// \param r : the source rational to be copied
	Rational(const Rational & r);

	/// \brief constructor from a float that is converted into a Rational
	/// \param f : the float that is converted
	Rational(const float & f);

    /// \brief destructor
    ~Rational() = default;


private :

	T _n; /*!< numerator, can be negative */
	T _d; /*!< denominator, can not be equal to zero */

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
	/// \param v : template to add to the calling rational
	/// \return the sum of the current Rational and the template argument 
	template <typename A>
	Rational operator+(const A &v) const;

	/// \brief add a Rational to the calling Rational
	/// \param r : rational to add to the calling rational
	void operator+=(const Rational &r);

	/// \brief unary minus
	/// \return the of minus the calling Rational
	Rational operator-() const;
	
	/// \brief substract 2 Rationals
	/// \param v : template to substract to the calling Rational
	/// \return the substract of the current Rational and the template argument 
	template <typename A>
	Rational operator-(const A &v) const;


	/// \brief substract a rational to the calling Rational
	/// \param r : Rational to substract to the calling Rational
	void operator-=(const Rational &r);

	/// \brief multiply 2 Rationals
	/// \param v : Template to multiply to the calling Rational
	/// \return the product of the current Rational and the template argument 
	template <typename A>
	Rational operator*(const A &v) const;



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
	template<typename A>
	static Rational toRational(const A& v, const uint nbIter);
	
};

//Constructors
template <typename T>
Rational<T>::Rational() : _n(0), _d(1) {
	static_assert(std::is_integral_v<T>, "T template must be integers");
}

template <typename T>
Rational<T>::Rational(const T n, const unsigned int d) : _n(n), _d(d) {
	static_assert(std::is_integral_v<T>, "T template must be integers");

	int gcd = std::gcd(_n,_d);
	if (gcd!=1){
		_n/=gcd;
		_d/=gcd;
	}

	_n*=sign(_d);
	_d*=sign(_d);
}

template <typename T>
Rational<T>::Rational(const T value){
	static_assert(std::is_integral_v<T>, "T template must be integers");
	_n=value;
	_d=1;
}

template <typename T>
Rational<T>::Rational(const float & f){
	static_assert(std::is_integral_v<T>, "T template must be integers");
	_n=toRational<float>(f,10)._n;
	_d=toRational<float>(f,10)._d;

	_n*=sign(_d);
	_d*=sign(_d);
}

template <typename T>
Rational<T>::Rational(const Rational & r) : _n(r._n), _d(r._d) {
	static_assert(std::is_integral_v<T>, "T template must be integers");

	_n*=sign(_d);
	_d*=sign(_d);
}

//Operators
template <typename T>
void Rational<T>::operator=(const Rational &r){
	_n = r.n();
	_d = r.d();
}

template <typename T>
template <typename A>
Rational<T> Rational<T>::operator+(const A &v) const{
	Rational r = toRational<A>(v, 10);
	return Rational(_n*r._d+r._n*_d,_d*r._d);
}

template <typename T>
void Rational<T>::operator+=(const Rational &r) {
	Rational result = *this+r;
	*this=result;
}

template <typename T>
Rational<T> Rational<T>::operator-() const {
	return Rational(-1*_n,_d);
}

template <typename T>
template <typename A>
Rational<T> Rational<T>::operator-(const A &v) const{
	Rational r = toRational<A>(v, 10);
	return Rational(_n*r._d-r._n*_d,_d*r._d);
}


template <typename T>
void Rational<T>::operator-=(const Rational &r) {
	Rational result = *this-r;
	*this=result;
}

template <typename T>
template <typename A>
Rational<T> Rational<T>::operator*(const A &v) const {
	Rational r = toRational<A>(v,10);
	return Rational(_n*r._n,_d*r._d);
}

template <typename T>
void Rational<T>::operator*=(const Rational &r) {
	Rational result = *this*r;
	*this=result;
}

template <typename T>
Rational<T> Rational<T>::operator/(const Rational &r) const{
	return *this*r.invert();
}

template <typename T>
void Rational<T>::operator/=(const Rational &r) {
	Rational result = *this/r;
	*this=result;
}

template <typename T>
bool Rational<T>::operator==(const Rational &r){
return (_n==r._n && _d==r._d)?true:false;
}

template <typename T>
bool Rational<T>::operator!=(const Rational &r){
return (_n!=r._n && _d!=r._d)?true:false;
}

template <typename T>
bool Rational<T>::operator<(const Rational &r){
	return _n*int(r._d)<int(_d)*r._n;
}

template <typename T>
bool Rational<T>::operator<=(const Rational &r){
	return _n*int(r._d)<=int(_d)*r._n;
}

template <typename T>
bool Rational<T>::operator>(const Rational &r){
return _n*int(r._d)>int(_d)*r._n;
}

template <typename T>
bool Rational<T>::operator>=(const Rational &r){
return _n*int(r._d)>=int(_d)*r._n;
}

//Methods

template <typename T>
Rational<T> Rational<T>::abs() const {
	return Rational<T>(std::abs(_n),_d);
}

template <typename T>
int Rational<T>::floor() const {
	return std::floor(_n/(int)_d);
}

template <typename T>
float Rational<T>::toFloat() const {
	return (float)_n/(float)_d;
}

template <typename T>
float Rational<T>::cos() const {
	return std::cos(toFloat());	
}

template <typename T>
float Rational<T>::sin() const {
	return std::sin(toFloat());	
}

template <typename T>
float Rational<T>::tan() const {
	return std::tan(toFloat());	
}

template <typename T>
Rational<T> Rational<T>::pow(const unsigned int n) const {
	if(n==0) return Rational(1,1);
	else return Rational(_n,_d) * pow(n-1);
}

template <typename T>
Rational<T> Rational<T>::sqrt() const {
	if(_n< 0){
		std::cout<<"Veuillez rentrer un nombre positif"<<std::endl;
		}
	return Rational(std::sqrt(_n),std::sqrt(_d));
}

template <typename T>
float Rational<T>::exp() const {
	return std::exp(toFloat());
}

template <typename T>
template <typename A>
Rational<T> Rational<T>::toRational(const A& v, const uint nbIter){
	if constexpr (std::is_same_v<A,Rational>){
		return v;
	}
	else if(std::is_integral_v<A>){
		return Rational<T>(v,1);
	}
	else {
		const float fPos = std::abs(v);
		if(fPos == 0. || nbIter == 0 ) return Rational<T>(0,1);
		if(fPos<1){
			return ((toRational(1*sign(v)/fPos,nbIter)).invert());
		}
		const uint uintPart = std::floor(fPos);
		return Rational<T>(sign(v)*uintPart,1)+toRational(sign(v)*(fPos-uintPart),nbIter-1);
	}
}

template <typename T>
std::ostream& operator<< (std::ostream& stream, const Rational<T>& r){
	stream << r.n() << "/" << r.d();
	return stream;
}

#endif
