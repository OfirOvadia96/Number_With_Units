#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{

    void NumberWithUnits::set_value(double val){
            this->value = val;
        }
    double NumberWithUnits::get_value(){
        return this->value;
    }
    void NumberWithUnits::set_type(std::string str){
        this->type = str;
    }
    string NumberWithUnits::get_type(){
        return this->type;
    }

    void NumberWithUnits::read_units(std::ifstream& file){
        
    }
    //operators:
        
        // sub\add
        NumberWithUnits operator+(const NumberWithUnits& num1, const NumberWithUnits& num2){
            return num1;
        }
        NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& num){
            this->value +=num.value;
            return *this;
        }
        NumberWithUnits operator+(const NumberWithUnits& num){//unary
             return NumberWithUnits(num.value, num.type);
        }
        NumberWithUnits operator-(const NumberWithUnits& num1 ,const NumberWithUnits& num2){
            return num1;
        }
        NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& num){
            this->value -=num.value;
            return *this;
        }
        NumberWithUnits operator-(const NumberWithUnits& num){ //unary
            return NumberWithUnits((-num.value), num.type);
        }
        //comparisons
        bool operator>(const NumberWithUnits& num1 , const NumberWithUnits& num2){
            return true;
        }
        bool operator>=(const NumberWithUnits& num1 , const NumberWithUnits& num2){
            return true;
        }
        bool operator<(const NumberWithUnits& num1 , const NumberWithUnits& num2){
            return true;
        }
        bool operator<=(const NumberWithUnits& num1 , const NumberWithUnits& num2){
            return true;
        }
        bool operator==(const NumberWithUnits& num1 , const NumberWithUnits& num2){
            return true;
        }
        bool operator!=(const NumberWithUnits& num1 , const NumberWithUnits& num2){
            return true;
        }
        NumberWithUnits& NumberWithUnits::operator++(){
            return *this;
        }
        NumberWithUnits operator++(NumberWithUnits& num){
            return NumberWithUnits(num.value+1 , num.type);
        }
        NumberWithUnits operator--(NumberWithUnits& num){
            return NumberWithUnits(num.get_value()-1 , num.get_type());
        }
        NumberWithUnits& NumberWithUnits::operator--(){
            return *this;
        }
        //multiplication
        NumberWithUnits& NumberWithUnits::operator*=(double real){
            this->value *= real;
            return *this;
        }
        NumberWithUnits operator*(const NumberWithUnits& num, double real){
            return NumberWithUnits((num.value*real), num.type);
        }
        NumberWithUnits operator*(double real, const NumberWithUnits& num){
            return NumberWithUnits((num.value*real), num.type);
        }
        // I\O
        ostream& operator<<(ostream& os, const NumberWithUnits& num){
            return (os << num.value << "[" << num.type << "]");
        }
        istream& operator>>(istream& is, NumberWithUnits& num){
            string temp;
            return (is >> num.value >> temp >> num.type);
        }
}