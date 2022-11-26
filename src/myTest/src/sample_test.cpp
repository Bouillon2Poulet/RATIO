#include <random>
// #include <vector>
// #include <string>
// #include <algorithm>

#include <gtest/gtest.h>

#include "Rational.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (RationalConstructor, defaultConstructor) { 
	Rational r;
	ASSERT_EQ (r.n(),0);
    ASSERT_EQ (r.d(),1);
}

TEST (RationalConstructor, directConstructor) { 

    const size_t maxSize = 150;  // max value for both _n et _d
    std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

	// run many times the same test with different values
	for(int run=0; run<100; ++run){

		// define a vector dimension
        int n = uniformDistributionValue(-int(maxSize),maxSize);
        unsigned int d = uniformIntDistribution(0,maxSize);;

        Rational r(n,d);
		ASSERT_EQ (std::gcd(r.n(),r.d()),1);
	}
}



// /////////////////////////////////////////////////////
// // arithmetic

// TEST (VectorDArithmetic, plus) {

// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim), vec3(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		vec3 = vec1 + vec2;
// 		ASSERT_EQ (vec3.size(), dim);

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] + data2[i]);    // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }


// TEST (VectorDArithmetic, minus) {

// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim), vec3(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		vec3 = vec1 - vec2;
// 		ASSERT_EQ (vec3.size(), dim);

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] - data2[i]);  // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }

// TEST (VectorDArithmetic, dot) {
// //1.
// 	VectorD vec1(3), vec2(3);
// 	vec1[0]=1.0;
// 	vec1[1]=4.0;
// 	vec1[2]=5.0;

// 	vec2[0]=7.0;
// 	vec2[1]=0.0;
// 	vec2[2]=3.0;

// 	ASSERT_EQ(vec1.dot(vec2),22);

// //2.
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim), vec3(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		//Verification avec calcul
// 		double calculatedDot = 0;
// 		for (int i=0;i<dim;i++){
// 			calculatedDot+=vec1[i]*vec2[i];
// 		}
// 		ASSERT_EQ(vec1.dot(vec2), calculatedDot);

// 		//Commutatif
// 		ASSERT_EQ(vec1.dot(vec2),vec2.dot(vec1));

// 		//Defini positif 
// 		ASSERT_GE(vec1.dot(vec1),0.);

// 		//Loi des cosinus
// 		double cosLaw = 0.5*(vec1.dot(vec1)+vec2.dot(vec2)-(vec1-vec2).dot(vec1-vec2));
// 		ASSERT_NEAR(vec1.dot(vec2),cosLaw, 1);
// 	}
// }

// TEST (VectorDArithmetic, productWithAScalar) {
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim);
// 		std::generate(data1.begin(), data1.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 		}

// 		double scalar = 5;
// 		vec2 = vec1*scalar;

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec2[i], vec1[i]*scalar);  // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }

// TEST (VectorDArithmetic, copyOperator) {

// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim);
// 		std::generate(data1.begin(), data1.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 		}

// 		VectorD vec2 = vec1;

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec1[i], vec2[i]);  // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }

// /////////////////////////////////////////////////////
// // exception

// TEST (VectorDException, loadExceptionMessage) {
// 	const std::string filename = "filename.txt";
// 	const std::string expectedException = "VectorD::load: error: can not open file: " + filename;

// 	// check the exception message
//     try{
// 		VectorD vec;
//         vec.load(filename);
//     }
//     catch( const std::exception &e){
//         EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
//     }
// }


// TEST (VectorDException, loadExceptionType) {

// 	// check exception type
// 	VectorD vec;
// 	EXPECT_THROW(vec.load("filename.txt"), std::ios_base::failure);
// }


// TEST (VectorDException, plusOperator) {

// 	// check exception type
// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim);
// 		std::generate(data1.begin(), data1.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim),vec2(dim-1);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 		}
// 		for(size_t i=0; i<dim-1; ++i){
// 			vec2[i] = vec1[i];
// 		}

// 		//Exception type
// 		EXPECT_THROW(VectorD vec3 = vec1+vec2, std::length_error);

// 		//Error message
// 		const std::string expectedException = "VectorD::operator+: operand with incompatible size : " + std::to_string(vec1.size()) + " and " + std::to_string(vec2.size());
		
// 		try{
// 			VectorD vec3 = vec1+vec2;
// 		}
// 		catch( const std::exception &e){
// 			EXPECT_TRUE( std::string(e.what()).find(expectedException) == 0);
// 		}

// 	}
// }




// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }


