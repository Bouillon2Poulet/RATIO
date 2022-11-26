#include "Rational.hpp"

// #include <fstream>
// #include <cstdlib>    // size_t
// #include <algorithm>  // transform
#include <numeric>    // gcd()
// #include <cmath>      // sqrt
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

Rational & Rational::operator=(const Rational &r){
	_n = r._n;
	_d = r._d;
}

Rational Rational::Rational::operator+(const Rational &r) const{
	return Rational(_n*r._d+r._n*_d,_d*r._d);
}

Rational Rational::Rational::operator+(const Rational &r) const{
	return Rational(_n*r._d-r._n*_d,_d*r._d);
}

Rational Rational::Rational::operator-() const {
	return Rational(-1*_n,_d);
}

Rational Rational::Rational::operator*(const Rational &r) const {
	return Rational(_n*r._n,_d*r._d);
}

Rational Rational::Rational::operator/(const Rational &r) const{
	return Rational(_n*r._d,_d*r._n);
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
