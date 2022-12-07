#include <string.h>
#include <map>
#include <iostream>
#include <fstream>

namespace ariel{
    class NumberWithUnits{
    private:
        double value;
        std::string type;
        static std::map<std::string,std::map<std::string, double>> book_units;

    public:
    //constructor
        NumberWithUnits(double real_number, const std::string& str){
            this->value = real_number;
            this->type = str;
        }
        //get-set
        void set_value(double val);
        double get_value();
        void set_type(std::string str);
        std::string get_type();

        static void read_units(std::ifstream& file);
        
        //operators:
        
        //add
        friend NumberWithUnits operator+(const NumberWithUnits& num1, const NumberWithUnits& num2);
        NumberWithUnits& operator+=(const NumberWithUnits& num);
        friend NumberWithUnits operator+(const NumberWithUnits& num);//unary

        //sub
        friend NumberWithUnits operator-(const NumberWithUnits& num1 ,const NumberWithUnits& num2);
        NumberWithUnits& operator-=(const NumberWithUnits& num);
        friend NumberWithUnits operator-(const NumberWithUnits& num); //unary
        //comparisons
        friend bool operator>(const NumberWithUnits& num1 , const NumberWithUnits& num2);
        friend bool operator>=(const NumberWithUnits& num1 , const NumberWithUnits& num2);
        friend bool operator<(const NumberWithUnits& num1 , const NumberWithUnits& num2);
        friend bool operator<=(const NumberWithUnits& num1 , const NumberWithUnits& num2);
        friend bool operator==(const NumberWithUnits& num1 , const NumberWithUnits& num2);
        friend bool operator!=(const NumberWithUnits& num1 , const NumberWithUnits& num2);
        NumberWithUnits& operator++();
        friend NumberWithUnits operator++(NumberWithUnits& num);
        friend NumberWithUnits operator--(NumberWithUnits& num);
        NumberWithUnits& operator--();
        //multiplication
        NumberWithUnits& operator*=(double real);
        friend NumberWithUnits operator*(const NumberWithUnits& num, double real);
        friend NumberWithUnits operator*(double real,const NumberWithUnits& num);

        // I\O
        friend std::ostream& operator<<(std::ostream& os,const NumberWithUnits& num);
        friend std::istream& operator>>(std::istream& is, NumberWithUnits& num);
    };
}