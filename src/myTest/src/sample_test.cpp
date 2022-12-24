#include <random>
#include <string>
using namespace std::string_literals;
// #include <vector>
// #include <string>
// #include <algorithm>

#include <gtest/gtest.h>

#include "Rational.hpp"
#include "internal.hpp"
using namespace rational;

/////////////////////////////////////////////////////
// constructors
TEST (RationalConstructor, defaultConstructor) { 
	Rational<int> r;
	ASSERT_EQ (r.n(),0);
    ASSERT_EQ (r.d(),1);
}

TEST (RationalConstructor, directConstructor) { 
	Rational<int> r1(-2,3);
	ASSERT_EQ(r1.n(),-2);
	ASSERT_EQ(r1.d(),3);

	Rational<int> r2(-4,6);
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);
}

TEST (RationalConstructor, copyConstructor) { 
	Rational<int> r1(-2,3);
	Rational<int> r2(r1);
	ASSERT_EQ(r2.n(),r1.n());
	ASSERT_EQ(r2.d(),r1.d());
}

// Methods
TEST (RationalMethod, Getters){
	Rational<int> r(-2,3);
	ASSERT_EQ(r.n(),-2);
	ASSERT_EQ(r.d(),3);
}

TEST (InternalMethod, invertMethod){
	Rational<int> r1(-2,3);
	ASSERT_EQ(r1.invert().n(),-3);
	ASSERT_EQ(r1.invert().d(),2);

	Rational<int> r2(0,1);
	ASSERT_THROW(Rational<int>r3 = r2.invert(),std::exception);
}

// Operators
TEST (RationalOperators, affectionOperator){
	Rational<int> r1(-2,3);
	Rational<int> r2 = r1;
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);
}

TEST (RationalOperators, plusOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	ASSERT_EQ((r2+r1).n(),-2);
	ASSERT_EQ((r2+r1).d(),3);

	Rational<int> r3(5,4);
	ASSERT_EQ((r2+r3).n(),7);
	ASSERT_EQ((r2+r3).d(),12);

	int a = 2;
	float b = 1.5;
	ASSERT_EQ((r1+a)==Rational<int>(2,1),true);
	ASSERT_EQ((r1+b)==Rational<int>(3,2),true);
	ASSERT_EQ((r2+a)==Rational<int>(4,3),true);
	ASSERT_EQ((r2+b)==Rational<int>(5,6),true);
}

TEST (RationalOperators, plusEqualOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	r2+=r1;
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);

	Rational<int> r3(5,4);
	r2+=r3;
	ASSERT_EQ(r2.n(),7);
	ASSERT_EQ(r2.d(),12);

	Rational<int> r4(-5,3);
	int a = 2;
	float b = 1.5;
	r1+=a;
	r4+=b;
	ASSERT_EQ(r1==Rational<int>(2,1),true);
	ASSERT_EQ(r4==Rational<int>(-1,6),true);

}

TEST (RationalOperators, unaryMinusOperator){
	Rational<int> r1(-2,3);
	ASSERT_EQ((-r1).n(),2);
	ASSERT_EQ((-r1).d(),3);

	Rational<int> r2(2,3);
	ASSERT_EQ((-r2).n(),-2);
	ASSERT_EQ((-r2).d(),3);
}

TEST (RationalOperators, minusOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);

	ASSERT_EQ((r2-r1).n(),-2);
	ASSERT_EQ((r2-r1).d(),3);

	Rational<int> r3(5,4);
	ASSERT_EQ((r2-r3).n(),-23);
	ASSERT_EQ((r2-r3).d(),12);

	int a = 2;
	float b = 1.5;
	ASSERT_EQ((r1-a)==Rational<int>(-2,1),true);
	ASSERT_EQ((r1-b)==Rational<int>(-3,2),true);
	ASSERT_EQ((r2-a)==Rational<int>(-8,3),true);
	ASSERT_EQ((r2-b)==Rational<int>(-13,6),true);
}

TEST (RationalOperators, minusEqualOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	r2-=r1;
	ASSERT_EQ(r2.n(),-2);
	ASSERT_EQ(r2.d(),3);

	Rational<int> r3(5,4);
	r2-=r3;
	ASSERT_EQ(r2.n(),-23);
	ASSERT_EQ(r2.d(),12);

	Rational<int> r4(-5,3);
	int a = 2;
	float b = 1.5;
	r1-=a;
	r4-=b;
	ASSERT_EQ(r1==Rational<int>(-2,1),true);
	ASSERT_EQ(r4==Rational<int>(-19,6),true);
}

TEST (RationalOperators, multiplyOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	ASSERT_EQ((r1*r2).n(),0);
	ASSERT_EQ((r1*r2).d(),1);

	Rational<int> r3(5,4);
	ASSERT_EQ((r2*r3).n(),-5);
	ASSERT_EQ((r2*r3).d(),6);

//float 
	ASSERT_EQ((r1*0.66).n(),0);
	ASSERT_EQ((r1*0.66).d(),1);
	ASSERT_NEAR((r3*0.66).toFloat(),0.825,0.1);
}

TEST (RationalOperators, multiplyEqualOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	r2*=r1;
	ASSERT_EQ(r2.n(),0);
	ASSERT_EQ(r2.d(),1);

	r2 = Rational<int>(-2,3);
	Rational<int> r3(5,4);
	r2*=r3;
	ASSERT_EQ(r2.n(),-5);
	ASSERT_EQ(r2.d(),6);

	Rational<int> r4(-5,3);
	int a = 2;
	float b = -1.5;
	r1*=a;
	r4*=b;
	ASSERT_EQ(r1==Rational<int>(0,1),true);
	ASSERT_EQ(r4==Rational<int>(5,2),true);
}

TEST (RationalOperators, divideOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	ASSERT_EQ((r1/r2).n(),0);
	ASSERT_EQ((r1/r2).d(),1);

	Rational<int> r3(5,4);
	ASSERT_EQ((r2/r3).n(),-8);
	ASSERT_EQ((r2/r3).d(),15);

	int a = 2;
	float b = 1.5;
	ASSERT_EQ((r1/a)==Rational<int>(0,1),true);
	ASSERT_EQ((r1/b)==Rational<int>(0,1),true);
	ASSERT_EQ((r2/a)==Rational<int>(-2,6),true);
	ASSERT_EQ((r2/b)==Rational<int>(-4,9),true);
}

TEST (RationalOperators, divideEqualOperator){
	Rational<int> r1(0,1);
	Rational<int> r2(-2,3);
	r1/=r2;
	ASSERT_EQ(r1.n(),0);
	ASSERT_EQ(r1.d(),1);

	r2 = Rational(-2,3);
	Rational<int>r3(5,4);
	r2/=r3;
	ASSERT_EQ(r2.n(),-8);
	ASSERT_EQ(r2.d(),15);

	Rational<int> r4(-5,3);
	int a = 2;
	float b = -1.5;
	r1/=a;
	r4/=b;
	ASSERT_EQ(r1==Rational<int>(0,1),true);
	ASSERT_EQ(r4==Rational<int>(10,9),true);
}

TEST (StreamOperators, coutOperator){
		Rational<int>r(-2,3);
		std::stringstream stream;
		stream<<r;
		ASSERT_EQ (stream.str(),std::to_string(-2)+"/"s+std::to_string(3));
}

TEST (RationalOperators, EqualComparisonOperator){
	Rational<int>r1(0,1);
	Rational<int>r2(-2,3);
	ASSERT_EQ(r1==r2,false);

	Rational<int>r3(-4,6);
	ASSERT_EQ(r2==r3,true);

	Rational<int>r4(-3,1);
	Rational<int>r5(-3,2);
	int a = -3;
	float b = -1.5;
	ASSERT_EQ(r4==a,true);
	ASSERT_EQ(r5==b,true);

}

TEST (RationalOperators, NotEqualComparisonOperator){
	Rational<int>r1(0,1);
	Rational<int>r2(-2,3);
	ASSERT_EQ(r1!=r2,true);

	Rational<int>r3(-4,6);
	ASSERT_EQ(r2!=r3,false);

	Rational<int>r4(-6,2);
	Rational<int>r5(-3,2);
	int a = -3;
	float b = -2.5;
	ASSERT_EQ(r4!=a,false);
	ASSERT_EQ(r5!=b,true);
	
}

TEST (RationalOperators, InferiorComparisonOperator){
	Rational<int>r1(0,1);
	Rational<int>r2(-2,3);
	ASSERT_EQ(r2<r1,true);

	Rational<int>r3(-5,6);
	ASSERT_EQ(r2<r3,false);

	Rational<int>r4(-3,1);
	Rational<int>r5(-3,2);
	int a = -2;
	float b = -2.5;
	ASSERT_EQ(r4<a,true);
	ASSERT_EQ(r5<b,false);
}

TEST (RationalOperators, InferiorEqualComparisonOperator){
	Rational<int>r1(0,1);
	Rational<int>r2(-2,3);
	ASSERT_EQ(r2<=r1,true);

	Rational<int>r3(-4,6);
	ASSERT_EQ(r2<=r3,true);

	Rational<int>r4(-3,1);
	Rational<int>r5(-3,2);
	int a = -2;
	float b = -1.5;
	ASSERT_EQ(r4<=a,true);
	ASSERT_EQ(r5<=b,true);
}

TEST (RationalOperators, SuperiorComparisonOperator){
	Rational<int>r1(0,1);
	Rational<int>r2(-2,3);
	ASSERT_EQ(r1>r2,true);

	Rational<int>r3(-5,6);
	ASSERT_EQ(r2>r3,true);

	Rational<int>r4(-3,1);
	Rational<int>r5(-3,2);
	int a = -2;
	float b = -2.5;
	ASSERT_EQ(r4>a,false);
	ASSERT_EQ(r5>b,true);
}

TEST (RationalOperators, SuperiorEqualComparisonOperator){
	Rational<int>r1(0,1);
	Rational<int>r2(-2,3);
	ASSERT_EQ(r1>=r2,true);

	Rational<int>r3(-4,6);
	ASSERT_EQ(r2>=r3,true);

	Rational<int>r4(-3,1);
	Rational<int>r5(-3,2);
	int a = -2;
	float b = -1.5;
	ASSERT_EQ(r4>=a,false);
	ASSERT_EQ(r5>=b,true);
}

//Methods
TEST (RationalMethods, absMethod){
	Rational<int>r1(-2,3);
	ASSERT_EQ(r1.abs().n(),2);
	ASSERT_EQ(r1.abs().d(),3);
}

TEST (RationalMethods, floorMethod){
	Rational<int>r1(-2,3);
	Rational<int>r2(-5,3);
	Rational<int>r3(5,3);
	ASSERT_EQ(r1.floor(),0);
	ASSERT_EQ(r2.floor(),-1);
	ASSERT_EQ(r3.floor(),1);
}

TEST (RationalMethods, toFloatMethod){
	Rational<int>r1(-2,3);
	Rational<int>r2(0,1);
	ASSERT_NEAR(r1.toFloat(),-0.666,0.01);
	ASSERT_NEAR(r2.toFloat(),0,0.01);
}

TEST (RationalMethods, cosMethod){
	Rational<int>r1(0,1);
	Rational<int>r2 = Rational<int>::toRational<float>(M_PI/2,10);
	Rational<int>r3 = Rational<int>::toRational<float>(M_PI,10);
	ASSERT_NEAR(r1.cos(),1,0.01);
	ASSERT_NEAR(r2.cos(),0,0.01);
	ASSERT_NEAR(r3.cos(),-1,0.01);
}

TEST (RationalMethods, sinMethod){
	Rational<int>r1(0,1);
	Rational<int>r2 = Rational<int>::toRational<float>(M_PI/2,10);
	Rational<int>r3 = Rational<int>::toRational<float>(M_PI,10);
	ASSERT_NEAR(r1.sin(),0,0.01);
	ASSERT_NEAR(r2.sin(),1,0.01);
	ASSERT_NEAR(r3.sin(),0,0.01);
}

TEST (RationalMethods, tanMethod){
	Rational<int>r1(0,1);
	Rational<int>r2 = Rational<int>::toRational<float>(M_PI/4,10);
	Rational<int>r3 = Rational<int>::toRational<float>(M_PI,10);
	ASSERT_NEAR(r1.tan(),0,0.01);
	ASSERT_NEAR(r2.tan(),1,0.01);
	ASSERT_NEAR(r3.tan(),0,0.01);
}

TEST (RationalMethods, powMethod){
	Rational<int>r1(0,1);
	Rational<int>r2(0,1);
	ASSERT_EQ(r1.pow(10)==r2,true);

	Rational<int>r3(-4,6);
	Rational<int>r4(4,9);

	ASSERT_EQ(r3.pow(2)==r4,true);
}

TEST (RationalMethods, sqrtMethod){
	Rational<int>r1(25,100);
	Rational<int>r2(5,10);
	ASSERT_EQ(r1.sqrt()==r2,true);

	Rational<int>r3(4,36);
	Rational<int>r4(2,6);

	ASSERT_EQ(r3.sqrt()==r4,true);
}

TEST (RationalMethods, expMethod){
	Rational<int>r1(0,1);
	Rational<int>r2(5,10);
	ASSERT_EQ(r1.exp()==1.0,true);

	ASSERT_EQ(r2.exp()==float(std::exp(5.0/10.0)),true);
}
