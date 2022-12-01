#include "Rational.hpp"
// SALUT MATHOU SAVA ????

// #include <fstream>
// #include <cstdlib>    // size_t
// #include <algorithm>  // transform
#include <numeric>    // gcd()
#include <cmath>      // sqrt
#include <cstdint>
// #include <stdexcept>  // special exceptions
// #include <string>     // for exceptions


//Constructors

Rational::Rational() : _n(0), _d(1) {
}

Rational::Rational(const int n, const unsigned int d) : _n(n), _d(d) {
	int gcd = std::gcd(_n,_d);
	if (gcd!=1){
		_n/=gcd;
		_d/=gcd;
	}
}

Rational::Rational(const int value){
	//Faire la conversion int -> rationnel 
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

Rational Rational::floatToRational(const float& f, const uint nbIter){
	const float fPos = std::abs(f);
	
	if(fPos == 0. || nbIter == 0 ) return Rational(0,1);
	if(fPos<1){
		return ((floatToRational(1*sign(f)/fPos,nbIter)).invert());
	}
	if(fPos>=1){
		const uint uintPart = std::floor(fPos);
		Rational returnTest = Rational(sign(f)*uintPart,1)+floatToRational(sign(f)*(fPos-uintPart),nbIter-1);
		if (returnTest.n() > cstdint::INT_MAX|| returnTest.n() >)
		return Rational(sign(f)*uintPart,1)+floatToRational(sign(f)*(fPos-uintPart),nbIter-1);
	}
}


std::ostream& operator<< (std::ostream& stream, const Rational& r) {	
	stream << r.n() << "/" << r.d();
	return stream;
}

// VectorD VectorD::operator+(const VectorD &v) const
// {
// 	if(v.size() != this->size())
// 		throw std::length_error("VectorD::operator+: operand with incompatible size : " + std::to_string(this->_data.size()) + " and " + std::to_string(v._data.size()));

// 	VectorD result(size());
// 	std::transform(_data.begin(), _data.end(), v._data.begin(), result._data.begin(), std::plus<double>());

// 	// if(result.size() !=0)
// 	// 	result[0] += 42; // looks like a bug ...

// 	return result;
// }


// VectorD VectorD::operator-(const VectorD &v) const
// {
// 	if(v.size() != this->size())
// 		throw std::length_error("VectorD::operator-: operand with incompatible size : " + std::to_string(this->_data.size()) + " and " + std::to_string(v._data.size()));

// 	VectorD result(size());
// 	std::transform(_data.begin(), _data.end(), v._data.begin(), result._data.begin(), std::minus<double>());

// 	return result;
// }


// VectorD VectorD::operator-() const
// {
// 	VectorD result(size());
// 	for(size_t i=0; i<size(); ++i)
// 		result[i] = -_data[i];

// 	return result;
// }


// VectorD VectorD::operator*(const double &value) const
// {
// 	VectorD result(*this);
// 	for(size_t i=0; i<size(); ++i)
// 		result[i] *= value;

// 	return result;
// }


// double VectorD::norm() const{
// 	return sqrt(this->dot(*this));
// }


// void VectorD::normalize() {
// 	double vec_norm = this->norm();

// 	if (std::abs(vec_norm) < 1.0e-10)
// 		return;

// 	for (size_t i =0; i<size(); i++) 
// 		_data[i] /= vec_norm;
// }


// double VectorD::dot(const VectorD & v) const {

// 	if(v.size() != this->size())
// 		throw std::length_error("VectorD::dot: operand with incompatible size : " + std::to_string(this->_data.size()) + " and " + std::to_string(v._data.size()));

// 	return std::inner_product(_data.begin(), _data.end(), v._data.begin(),0.0);
// }



// void VectorD::save(const std::string &filename) const{

// 	//open the file
// 	std::ofstream myfile;
// 	myfile.open(filename, std::ios::out | std::ios::binary);
	
// 	if(!myfile.is_open()){
// 		throw std::ios_base::failure("VectorD::save: error: can not open file: " + filename);
// 	}

// 	// write the vector size
// 	myfile << size() << std::endl;

// 	for(size_t i=0; i<size(); ++i)
// 		myfile << _data[i] << " ";

// 	myfile.close();
// }


// void VectorD::load(const std::string &filename){

// 	//open the file
// 	std::ifstream myfile;
// 	myfile.open(filename, std::ios::in | std::ios::binary); 
// 	if(!myfile.is_open()){
// 		throw std::ios_base::failure("VectorD::load: error: can not open file: " + filename);
// 	}

// 	// read the vector size
// 	size_t vectorSize;
// 	myfile >> vectorSize;
// 	if(vectorSize != size())
// 		*this = VectorD(vectorSize);

// 	// read the data
// 	for(size_t i=0; i<vectorSize; ++i)
// 		myfile >> _data[i];

// 	// close file
// 	myfile.close();
// }


// void VectorD::display() const {
// 	for(size_t i=0; i< _data.size(); ++i)
// 		std::cout << _data[i] << " ";
// 	std::cout << std::endl;
// }


// std::ostream& operator<< (std::ostream& stream, const VectorD& v) {
// 	if(v.size() == 0){
// 		stream << "Not initialized yet -> size is 0";
// 		return stream;
// 	}
			
// 	stream << "(";
// 	for(unsigned int i=0; i<v.size()-1; ++i)
// 		stream << v[i] << " , ";
 
//  	stream << v[v.size()-1] << ")";

// 	return stream;
// }


// VectorD operator*(const double value, const VectorD &vec){
// 	return vec * value;
// }
