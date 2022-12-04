#include <random>
#include <string>
using namespace std::string_literals;
// #include <vector>
// #include <string>
// #include <algorithm>

#include <gtest/gtest.h>

#include "Rational.hpp"
#include "internal.hpp"

/////////////////////////////////////////////////////
// constructors

TEST (RationalConstructor, defaultConstructor) { 
	Rational r;
	ASSERT_EQ (r.n(),0);
    ASSERT_EQ (r.d(),1);
}

TEST (RationalConstructor, directConstructor) { 
	Rational r1(-2,3);
	ASSERT_EQ(r1.n(),-2);
	ASSERT_EQ(r1.d(),3);

	Rational r2(-4,6);
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);

	// ASSERT_THROW(Rational(-0.5f, 0.5f), std::exception);
	// ASSERT_THROW(Rational(2, -2), std::exception);
}

TEST (RationalConstructor, copyConstructor) { 
	Rational r1(-2,3);
	Rational r2(r1);
	ASSERT_EQ(r2.n(),r1.n());
	ASSERT_EQ(r2.d(),r1.d());
}

// Methods
TEST (RationalMethod, Getters){
	Rational r(-2,3);
	ASSERT_EQ(r.n(),-2);
	ASSERT_EQ(r.d(),3);
}

TEST (InternalMethod, invertMethod){
	Rational r1(-2,3);
	ASSERT_EQ(r1.invert().n(),-3);
	ASSERT_EQ(r1.invert().d(),2);

	Rational r2(0,1);
	ASSERT_THROW(Rational r3 = r2.invert(),std::exception);
}

// Operators
TEST (RationalOperators, affectionOperator){
	Rational r1(-2,3);
	Rational r2 = r1;
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);
}

TEST (RationalOperators, plusOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ((r2+r1).n(),-2);
	ASSERT_EQ((r2+r1).d(),3);

	Rational r3(5,4);
	ASSERT_EQ((r2+r3).n(),7);
	ASSERT_EQ((r2+r3).d(),12);
}

TEST (RationalOperators, plusEqualOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	r2+=r1;
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);

	Rational r3(5,4);
	r2+=r3;
	ASSERT_EQ(r2.n(),7);
	ASSERT_EQ(r2.d(),12);
}

TEST (RationalOperators, unaryMinusOperator){
	Rational r1(-2,3);
	ASSERT_EQ((-r1).n(),2);
	ASSERT_EQ((-r1).d(),3);

	Rational r2(2,3);
	ASSERT_EQ((-r2).n(),-2);
	ASSERT_EQ((-r2).d(),3);
}

TEST (RationalOperators, minusOperator){
	Rational r1(0,1);
	Rational r2(-2,3);

	ASSERT_EQ((r2-r1).n(),-2);
	ASSERT_EQ((r2-r1).d(),3);

	Rational r3(5,4);
	ASSERT_EQ((r2-r3).n(),-23);
	ASSERT_EQ((r2-r3).d(),12);
}

TEST (RationalOperators, minusEqualOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	r2-=r1;
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);

	Rational r3(5,4);
	r2-=r3;
	ASSERT_EQ(r2.n(),-23);
	ASSERT_EQ(r2.d(),12);
}

TEST (RationalOperators, multiplyOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ((r1*r2).n(),0);
	ASSERT_EQ((r1*r2).d(),1);

	Rational r3(5,4);
	ASSERT_EQ((r2*r3).n(),-5);
	ASSERT_EQ((r2*r3).d(),6);
}

TEST (RationalOperators, multiplyWithFloatOperator){
	Rational r1(0,1);
	ASSERT_EQ((r1*0.66).n(),0);
	ASSERT_EQ((r1*0.66).d(),1);

	Rational r2(5,4);
	ASSERT_NEAR((r2*0.66).toFloat(),0.825,0.1);
}

TEST (RationalOperators, multiplyEqualOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	r2*=r1;
	ASSERT_EQ(r2.n(),0);
	ASSERT_EQ(r2.d(),1);

	r2 = Rational(-2,3);
	Rational r3(5,4);
	r2*=r3;
	ASSERT_EQ(r2.n(),-5);
	ASSERT_EQ(r2.d(),6);
}

TEST (RationalOperators, divideOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ((r1/r2).n(),0);
	ASSERT_EQ((r1/r2).d(),1);

	Rational r3(5,4);
	ASSERT_EQ((r2/r3).n(),-8);
	ASSERT_EQ((r2/r3).d(),15);
}

TEST (RationalOperators, divideEqualOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	r1/=r2;
	ASSERT_EQ(r1.n(),0);
	ASSERT_EQ(r1.d(),1);

	r2 = Rational(-2,3);
	Rational r3(5,4);
	r2/=r3;
	ASSERT_EQ(r2.n(),-8);
	ASSERT_EQ(r2.d(),15);
}

TEST (StreamOperators, coutOperator){
		Rational r(-2,3);
		std::stringstream stream;
		stream<<r;
		ASSERT_EQ (stream.str(),std::to_string(-2)+"/"s+std::to_string(3));
}

TEST (RationalOperators, EqualComparisonOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ(r1==r2,false);

	Rational r3(-4,6);
	ASSERT_EQ(r2==r3,true);
}

TEST (RationalOperators, NotEqualComparisonOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ(r1!=r2,true);

	Rational r3(-4,6);
	ASSERT_EQ(r2!=r3,false);
}

TEST (RationalOperators, InferiorComparisonOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ(r2<r1,true);

	Rational r3(-5,6);
	ASSERT_EQ(r2<r3,false);
}

TEST (RationalOperators, InferiorEqualComparisonOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ(r2<=r1,true);

	Rational r3(-4,6);
	ASSERT_EQ(r2<=r3,true);
}

TEST (RationalOperators, SuperiorComparisonOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ(r1>r2,true);

	Rational r3(-5,6);
	ASSERT_EQ(r2>r3,true);
}

TEST (RationalOperators, SuperiorEqualComparisonOperator){
	Rational r1(0,1);
	Rational r2(-2,3);
	ASSERT_EQ(r1>=r2,true);

	Rational r3(-4,6);
	ASSERT_EQ(r2>=r3,true);
}

//Methods
TEST (RationalMethods, absMethod){
	Rational r1(-2,3);
	ASSERT_EQ(r1.abs().n(),2);
	ASSERT_EQ(r1.abs().d(),3);
}

TEST (RationalMethods, floorMethod){
	Rational r1(-2,3);
	Rational r2(-5,3);
	Rational r3(5,3);
	ASSERT_EQ(r1.floor(),0);
	ASSERT_EQ(r2.floor(),-1);
	ASSERT_EQ(r3.floor(),1);
}

TEST (RationalMethods, toFloatMethod){
	Rational r1(-2,3);
	Rational r2(0,1);
	ASSERT_NEAR(r1.toFloat(),-0.666,0.01);
	ASSERT_NEAR(r2.toFloat(),0,0.01);
}

TEST (RationalMethods, cosMethod){
	Rational r1(0,1);
	Rational r2 = Rational::floatToRational(M_PI/2,10);
	Rational r3 = Rational::floatToRational(M_PI,10);
	ASSERT_NEAR(r1.cos(),1,0.01);
	ASSERT_NEAR(r2.cos(),0,0.01);
	ASSERT_NEAR(r3.cos(),-1,0.01);
}

TEST (RationalMethods, sinMethod){
	Rational r1(0,1);
	Rational r2 = Rational::floatToRational(M_PI/2,10);
	Rational r3 = Rational::floatToRational(M_PI,10);
	ASSERT_NEAR(r1.sin(),0,0.01);
	ASSERT_NEAR(r2.sin(),1,0.01);
	ASSERT_NEAR(r3.sin(),0,0.01);
}

TEST (RationalMethods, tanMethod){
	Rational r1(0,1);
	Rational r2 = Rational::floatToRational(M_PI/4,10);
	Rational r3 = Rational::floatToRational(M_PI,10);
	ASSERT_NEAR(r1.tan(),0,0.01);
	ASSERT_NEAR(r2.tan(),1,0.01);
	ASSERT_NEAR(r3.tan(),0,0.01);
}

TEST (RationalMethods, powMethod){
	Rational r1(0,1);
	Rational r2(0,1);
	ASSERT_EQ(r1.pow(10)==r2,true);

	Rational r3(-4,6);
	Rational r4(4,9);

	ASSERT_EQ(r3.pow(2)==r4,true);
}

TEST (RationalMethods, sqrtMethod){
	Rational r1(25,100);
	Rational r2(5,10);
	ASSERT_EQ(r1.sqrt()==r2,true);

	Rational r3(4,36);
	Rational r4(2,6);

	ASSERT_EQ(r3.sqrt()==r4,true);
}

TEST (RationalMethods, expMethod){
	Rational r1(0,1);
	Rational r2(5,10);
	ASSERT_EQ(r1.exp()==1.0,true);

	ASSERT_EQ(r2.exp()==float(std::exp(5.0/10.0)),true);
}
