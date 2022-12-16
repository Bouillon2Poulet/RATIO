#include "Rational.hpp"
// #include <fstream>
// #include <cstdlib>    // size_t
// #include <algorithm>  // transform
#include <numeric>    // gcd()
#include <cmath>      // sqrt
#include <assert.h>
// #include <stdexcept>  // special exceptions
// #include <string>     // for exceptions


//Constructors
template <typename T=int>
Rational<T>::Rational() : _n(0), _d(1) {
}

Rational::Rational(const int n, const unsigned int d) : _n(n), _d(d) {
	int gcd = std::gcd(_n,_d);
	if (gcd!=1){
		_n/=gcd;
		_d/=gcd;
	}
}

Rational::Rational(const int value){
	_n=value;
	_d=1;
}

Rational::Rational(const float & f){
	_n=floatToRational(f,10)._n;
	_d=floatToRational(f,10)._d;
}

Rational::Rational(const Rational & r) : _n(r._n), _d(r._d) {
}

//Operators

void Rational::operator=(const Rational &r){
	_n = r.n();
	_d = r.d();
}

Rational Rational::Rational::operator+(const Rational &r) const{
	return Rational(_n*r._d+r._n*_d,_d*r._d);
}

void Rational::Rational::operator+=(const Rational &r) {
	Rational result = *this+r;
	*this=result;
}

Rational Rational::Rational::operator-() const {
	return Rational(-1*_n,_d);
}

Rational Rational::Rational::operator-(const Rational &r) const{
	return Rational(_n*r._d-r._n*_d,_d*r._d);
}

//ajout
Rational Rational::operator-(const int &i) const{
	return Rational(_n-i*int(_d),_d);
}

// ajout
// Rational Rational::operator-(const float &f) const{
// 	Rational r = floatToRational(f,10);
// 	return Rational(_n*r._d-_d*r._n,_d*r._d);
// }

void Rational::Rational::operator-=(const Rational &r) {
	Rational result = *this-r;
	*this=result;
}

Rational Rational::Rational::operator*(const Rational &r) const {
	return Rational(_n*r._n,_d*r._d);
}

Rational Rational::Rational::operator*(const float &f) const {
	Rational r = floatToRational(f,10);
	return Rational(_n*r._n,_d*r._d);
}

// Rational Rational::operator*(const int &i) const {
// 	return Rational(_n*i,int(_d)*i);
// }

void Rational::Rational::operator*=(const Rational &r) {
	Rational result = *this*r;
	*this=result;
}

Rational Rational::Rational::operator/(const Rational &r) const{
	return *this*r.invert();
}

void Rational::Rational::operator/=(const Rational &r) {
	Rational result = *this/r;
	*this=result;
}

bool Rational::operator==(const Rational &r){
return (_n==r._n && _d==r._d)?true:false;
}

bool Rational::operator!=(const Rational &r){
return (_n!=r._n && _d!=r._d)?true:false;
}


bool Rational::operator<(const Rational &r){
	return _n*int(r._d)<int(_d)*r._n;
}

bool Rational::operator<=(const Rational &r){
	return _n*int(r._d)<=int(_d)*r._n;
}

bool Rational::operator>(const Rational &r){
return _n*int(r._d)>int(_d)*r._n;
}

bool Rational::operator>=(const Rational &r){
return _n*int(r._d)>=int(_d)*r._n;
}

//Methods
Rational Rational::abs() const {
	return Rational(std::abs(_n),_d);
}

int Rational::floor() const {
	return std::floor(_n/(int)_d);
}

float Rational::toFloat() const {
	return (float)_n/(float)_d;
}

float Rational::cos() const {
	return std::cos(toFloat());	
}

float Rational::sin() const {
	return std::sin(toFloat());	
}

float Rational::tan() const {
	return std::tan(toFloat());	
}

Rational Rational::pow(const unsigned int n) const
{
	if(n==0) return Rational(1,1);
	else return Rational(_n,_d) * pow(n-1);
}

Rational Rational::sqrt() const
{
	if(_n< 0){
		std::cout<<"Veuillez rentrer un nombre positif"<<std::endl;
		}
	else return Rational(std::sqrt(_n),std::sqrt(_d));
}


float Rational::exp() const {
	return std::exp(toFloat());
}


Rational Rational::floatToRational(const float& f, const uint nbIter){
	const float fPos = std::abs(f);
	if(fPos == 0. || nbIter == 0 ) return Rational(0,1);
	if(fPos<1){
		return ((floatToRational(1*sign(f)/fPos,nbIter)).invert());
	}
	if(fPos>=1){
		const uint uintPart = std::floor(fPos);
		return Rational(sign(f)*uintPart,1)+floatToRational(sign(f)*(fPos-uintPart),nbIter-1);
	}
}


std::ostream& operator<< (std::ostream& stream, const Rational& r) {	
	stream << r.n() << "/" << r.d();
	return stream;
}

