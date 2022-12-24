#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <type_traits>
#include <limits>
#include <stdarg.h>

#include "internal.hpp"

#ifndef __RATIONAL__HPP
#define __RATIONAL__HPP


// Doxygen menu
/// \version 0.1
/// \mainpage
/// \image html myImage.jpg
/// \tableofcontents
/// \section instroduction_sec What for?
/// Rational is a super tool to decrease error caused by floats intrinsic rounds  
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li C++ 17
/// \li STL library
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
/// \section Credits
/// \li Big thanks to Jules Fouchy, Matteo Leclercq and Guy Luong for the big help they provided us
/// \li Shout out to Elise Massa who recommended overleaf.com in order to make our project report
/// \li Finally, huge thanks to Vincent Nozick aka "le maxi crack" who supported us during the whole semester

int NBITERDEFAULT = 10;

/// \class Rational
/// \brief template class defining a number by its rational form, template type MUST BE an integral
using namespace internal;

namespace rational{
	template <typename T = int>
	class Rational {

	public:
		//////////////////////Constructors

		/// \brief default constructor, creates a Rational equal to zero (1/0)
		constexpr Rational();

		/// \brief copy constructor
		/// \param r : the source Rational
		constexpr Rational(const Rational& r)=default;

		/// \brief constructor from numerator and denominator, PGCD(n,d) = 1
		/// \tparam T : the template type, MUST BE an integral
		/// \param n : the const value used as numerator
		/// \param d : the const value used as denominator
		constexpr Rational(const T& n, const T& d);

		/// \brief constructor from a value that is converted into a Rational thanks to toRational() function
		/// \tparam A : the value type, MUST BE an integral, a floating point or a Rational
		/// \param value : the const value converted into a Rational
		template<typename A>
		constexpr Rational(const A& value);


		/// \brief destructor
		~Rational() = default;


	private :

		T _n; /*!< numerator*/
		T _d; /*!< denominator, if equal to zero -> the Rational is infinite */

	public :
		/// \brief return the T numerator of a Rational of type T
		constexpr inline T n() const {
			return _n;
		}

		/// \brief return the T denominator of a Rational of type T
		constexpr inline T d() const {
			return _d;
		}

		/// \brief return the invert of a Rational
		constexpr inline Rational<T> invert() const {
			if(_n==0||_d==0){
				throw std::invalid_argument("_d = 0");
			}

			return Rational<T>(sign(_n)*_d, std::abs(_n));
		}

		//////////////////////Operators

		/// \brief affectation operator
		constexpr void operator=(const Rational &r);

		/// \brief add 2 Rationals
		/// \param v : the value to add to the calling rational
		/// \return the sum of the current Rational and the argument value
		template <typename A>
		constexpr Rational<T> operator+(const A &v) const;

		/// \brief add a value to the calling Rational
		/// \param v : the value to add to the calling rational
		template <typename A>
		constexpr void operator+=(const A &v);

		/// \brief unary minus
		/// \return the minus of the calling Rational
		constexpr Rational<T> operator-() const;
		
		/// \brief substract 2 Rationals
		/// \param v : value to substract to the calling Rational
		/// \return the substract of the current Rational and the argument value
		template <typename A>
		constexpr Rational<T> operator-(const A &v) const;

		/// \brief substract a value to the calling Rational
		/// \param v : the value to substract to the calling Rational
		template <typename A>
		constexpr void operator-=(const A &v);

		/// \brief multiply a Rational to a value
		/// \param v : the value to multiply to the calling Rational
		/// \return the product of the current Rational and the argument value
		template <typename A>
		constexpr Rational<T> operator*(const A &v) const;

		/// \brief multiply a value to the calling Rational
		/// \param v : the value to multiply to the calling Rational
		template <typename A>
		constexpr void operator*=(const A &v);

		/// \brief divide 2 Rationals
		/// \param v : the value to divide to the calling Rational
		/// \return the quotient of the current Rational and the argument value
		template <typename A>
		constexpr Rational<T> operator/(const A &v) const;

		/// \brief divide a value to the calling Rational
		/// \param v : the value to divide to the calling Rational
		template <typename A>
		constexpr void operator/=(const A &v);

		/// \brief compare if the left Rational is equal to the argument value
		/// \param v : the value to compare to the calling Rational
		/// \return 1 if equal else 0
		template <typename A>
		constexpr bool operator==(const A &v);

		/// \brief compare if the left Rational is different to the argument value
		/// \param v : the value to compare to the calling Rational
		/// \return 1 if different else 0
		template <typename A>
		constexpr bool operator!=(const A &v);

		/// \brief compare if the left Rational is greater than the argument value
		/// \param v : the value to compare to the calling Rational
		/// \return 1 if greater else 0
		template <typename A>
		constexpr bool operator>(const A &v) const;

		/// \brief compare if the left Rational is greater or equal to the argument value
		/// \param v : the value to compare to the calling Rational
		/// \return 1 if greater or equal else 0
		template <typename A>
		constexpr bool operator>=(const A &v);

		/// \brief compare if the left Rational is lower than the argument value
		/// \param v : the value to compare to the calling Rational
		/// \return 1 if lower else 0
		template <typename A>
		constexpr bool operator<(const A &v) const;

		/// \brief compare if the left Rational is lower or equal to the argument value
		/// \param v : the value to compare to the calling Rational
		/// \return 1 if lower or equal else 0
		template <typename A>
		constexpr bool operator<=(const A &v);


		//////////////////////Others methods

		/// \brief return the absolute value of the calling Rational
		constexpr Rational<T> abs() const;

		/// \brief return the integar part of the calling Rational
		constexpr int floor() const;

		/// \brief convert the calling Rational to a float
		/// \return the nearest float from the calling Rational
		constexpr float toFloat() const;

		/// \brief return the cos() of the calling Rational (passing by float)
		constexpr float cos() const;

		/// \brief return the sin() of the calling Rational (passing by float)
		constexpr float sin() const;

		/// \brief return the tan() of the calling Rational (passing by float)
		constexpr float tan() const;

		/// \brief return the pow value of the calling Rational
		constexpr Rational<T> pow(const unsigned int n) const; 

		/// \brief return the square root of the calling Rational (passing by float)
		constexpr Rational<T> sqrt() const; 

		/// \brief return the exp value of the calling Rational (passing by float)
		constexpr float exp() const; 

		/// \brief recursive way to convert a value to a Rational
		/// \param v : the value to convert to Rational
		/// \param nbIter : number of recursive call, greater it is, more precise the conversion will be
		template<typename A>
		constexpr static Rational<T> toRational(const A& v, const uint nbIter);

		/// \brief function that returns the maximum of 2 Rationals
		/// \param r1 : the first Rational to get the maximum of
		/// \param r2 : the second Rational to get the maximum of
		constexpr static Rational<T> max(const Rational<T>& r1,const Rational<T>& r2);

		/// \brief variadic function that return the maximum of several Rationals
		/// \param args : the Rationals to get the maximum of
		template<typename... Args>
		constexpr static Rational<T> max(const Rational<T>& r, Args... args);

		/// \brief function that returns the minimum of 2 Rationals
		/// \param r1 : the first Rational to get the minimum of
		/// \param r2 : the second Rational to get the minimum of
		constexpr static Rational<T> min(const Rational<T>& r1,const Rational<T>& r2);

		/// \brief variadic function that return the minimum of several Rationals
		/// \param args : the Rationals to get the maximum of
		template<typename... Args>
		constexpr static Rational<T> min(const Rational<T>& r, Args... args);
	};

	//Constructors
	template <typename T>
	constexpr Rational<T>::Rational() : _n(0), _d(1) {
		static_assert(std::is_integral_v<T>, "T template must be integers");
	}

	template <typename T>
	constexpr Rational<T>::Rational(const T& n, const T& d) : _n(n), _d(d) {
		static_assert(std::is_integral_v<T>, "T template must be integers");

		//case 0/0
		if (_n ==0 && _d==0){
			throw std::invalid_argument("error : bad argument");
		}

		int gcd = std::gcd(_n,_d);
		if (gcd!=1){
			_n/=gcd;
			_d/=gcd;
		}

		//case _d<0
		_n*=sign(_d);
		_d*=sign(_d);


		//infinite
		if (_d==0) _n=1*sign(_n);
	}

	template <typename T>
	template <typename A>
	constexpr Rational<T>::Rational(const A& value){
		static_assert(std::is_integral_v<T>, "T template must be integers");
		Rational<T> r = toRational(value,NBITERDEFAULT);
		_n=r._n;
		_d=r._d;

		//infinite
		if (_d==0) _n=1*sign(_n);
	}

	//Operators
	template <typename T>
	constexpr void Rational<T>::operator=(const Rational &r){
		_n = r.n();
		_d = r.d();
	}

	template <typename T>
	template <typename A>
	constexpr Rational<T> Rational<T>::operator+(const A &v) const{
		Rational r = toRational<A>(v, NBITERDEFAULT);
		return Rational(_n*r._d+r._n*_d,_d*r._d);
	}

	template <typename T>
	template <typename A>
	constexpr void Rational<T>::operator+=(const A &v) {
		Rational r = toRational<A>(v, NBITERDEFAULT);
		Rational result = *this+r;
		*this=result;
	}

	template <typename T>
	constexpr Rational<T> Rational<T>::operator-() const {
		return Rational(-1*_n,_d);
	}

	template <typename T>
	template <typename A>
	constexpr Rational<T> Rational<T>::operator-(const A &v) const{
		Rational r = toRational<A>(v, NBITERDEFAULT);
		return Rational(_n*r._d-r._n*_d,_d*r._d);
	}


	template <typename T>
	template <typename A>
	constexpr void Rational<T>::operator-=(const A &v) {
		Rational r = toRational<A>(v, NBITERDEFAULT);
		Rational result = *this-r;
		*this=result;
	}

	template <typename T>
	template <typename A>
	constexpr Rational<T> Rational<T>::operator*(const A &v) const {
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return Rational(_n*r._n,_d*r._d);
	}

	template <typename T>
	template <typename A>
	constexpr void Rational<T>::operator*=(const A &v){
		Rational r = toRational<A>(v, NBITERDEFAULT);
		Rational result = *this*r;
		*this=result;
	}

	template <typename T>
	template <typename A>
	constexpr Rational<T> Rational<T>::operator/(const A &v) const{
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return *this*r.invert();
	}

	template <typename T>
	template <typename A>
	constexpr void Rational<T>::operator/=(const A &v){
		Rational r = toRational<A>(v, NBITERDEFAULT);
		Rational result = *this/r;
		*this=result;
	}

	template <typename T>
	template <typename A>
	constexpr bool Rational<T>::operator==(const A &v){
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return (_n==r._n && _d==r._d);
	}

	template <typename T>
	template <typename A>
	constexpr bool Rational<T>::operator!=(const A &v){
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return (_n!=r._n || _d!=r._d);
	}

	template <typename T>
	template <typename A>
	constexpr bool Rational<T>::operator<(const A &v) const{
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return _n*int(r._d)<int(_d)*r._n;
	}

	template <typename T>
	template <typename A>
	constexpr bool Rational<T>::operator<=(const A &v){
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return _n*int(r._d)<=int(_d)*r._n;
	}

	template <typename T>
	template <typename A>
	constexpr bool Rational<T>::operator>(const A &v) const {
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return _n*int(r._d)>int(_d)*r._n;
	}

	template <typename T>
	template <typename A>
	constexpr bool Rational<T>::operator>=(const A &v){
		Rational r = toRational<A>(v,NBITERDEFAULT);
		return _n*int(r._d)>=int(_d)*r._n;
	}

	//Methods

	template <typename T>
	constexpr Rational<T> Rational<T>::abs() const {
		return Rational<T>(std::abs(_n),_d);
	}

	template <typename T>
	constexpr int Rational<T>::floor() const {
		return std::floor(_n/(int)_d);
	}

	template <typename T>
	constexpr float Rational<T>::toFloat() const {
		return (float)_n/(float)_d;
	}

	template <typename T>
	constexpr float Rational<T>::cos() const {
		return std::cos(toFloat());	
	}

	template <typename T>
	constexpr float Rational<T>::sin() const {
		return std::sin(toFloat());	
	}

	template <typename T>
	constexpr float Rational<T>::tan() const {
		return std::tan(toFloat());	
	}

	template <typename T>
	constexpr Rational<T> Rational<T>::pow(const unsigned int n) const {
		if(n==0) return Rational(1,1);
		else return Rational(_n,_d) * pow(n-1);
	}

	template <typename T>
	constexpr Rational<T> Rational<T>::sqrt() const {
		if(_n< 0){
			std::cout<<"Veuillez rentrer un nombre positif"<<std::endl;
			}
		return Rational(std::sqrt(_n),std::sqrt(_d));
	}

	template <typename T>
	constexpr float Rational<T>::exp() const {
		return std::exp(toFloat());
	}

	template <typename T>
	template <typename A>
	constexpr Rational<T> Rational<T>::toRational(const A& v, const uint nbIter){
		if constexpr (std::is_same_v<A,Rational>){
			return v;
		}
		else if(std::is_integral_v<A>){
			return Rational<T>(v,1);
		}
		else if (std::is_floating_point_v<A>){
			const float fPos = std::abs(v);
			if(fPos == 0. || nbIter == 0 ) return Rational<T>(0,1);
			if(fPos<1){
				return ((toRational(1*sign(v)/fPos,nbIter)).invert());
			}
			const uint uintPart = std::floor(fPos);
			return Rational<T>(sign(v)*uintPart,1)+toRational(sign(v)*(fPos-uintPart),nbIter-1);
		}
		else {
			throw std::invalid_argument("error : bad argument");
		}
	}

	template <typename T>
	constexpr Rational<T> Rational<T>::max(const Rational<T>& r1,const Rational<T>& r2) {
		return r1>r2 ? r1 : r2;
	}

	template<typename T>
	template <typename... Args>
	constexpr Rational<T> Rational<T>::max(const Rational<T>& r, Args... args) {
		return  Rational<T>::max(r,max(args...));
	}

	template <typename T>
	constexpr Rational<T> Rational<T>::min(const Rational<T>& r1,const Rational<T>& r2) {
		return r1<r2 ? r1 : r2;
	}

	template<typename T>
	template <typename... Args>
	constexpr Rational<T> Rational<T>::min(const Rational<T>& r, Args... args) {
		return  Rational<T>::min(r,min(args...));
	}

	template <typename T>
	constexpr std::ostream& operator<< (std::ostream& stream, const Rational<T>& r){
		stream << r.n() << "/" << r.d();
		return stream;
	}

	#endif
}

