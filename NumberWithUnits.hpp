#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <map>
#include <stdbool.h>

namespace ariel{

    class NumberWithUnits{
    private:
        double value;
        std::string unit;

    public:
        static std::map<std::string, std::map<std::string, double>> con_map; //help for convert
        /* constructor */
         NumberWithUnits(double val, const std::string& type){
        con_map.at(type);
        this->unit = type;
        this->value = val;
        }
        
        /* read from files the right units */
        static void read_units(std::ifstream &file_name);

        
        /* --  Operators  --  */
       
        /* Add and Sub */
        friend NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b);
        NumberWithUnits& operator+=(const NumberWithUnits &other);
        friend NumberWithUnits operator+(const NumberWithUnits &a);
        friend NumberWithUnits& operator++(NumberWithUnits &a); //prefix
        friend NumberWithUnits operator++(NumberWithUnits &a, int); //postfix
        friend NumberWithUnits& operator--(NumberWithUnits &a); //prefix
        friend NumberWithUnits operator--(NumberWithUnits &a, int); //postfix
        friend NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b);
        NumberWithUnits& operator-=(const NumberWithUnits &other);
        friend NumberWithUnits operator-(const NumberWithUnits &a);

        /* multiplication */
        friend NumberWithUnits operator*(const NumberWithUnits &a,const double b);
        friend NumberWithUnits operator*(const double b,const NumberWithUnits &a);
        friend NumberWithUnits operator*(const NumberWithUnits &a,const NumberWithUnits &b);

        /* Boolean */
        friend bool operator==(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator>(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator<(const NumberWithUnits &a, const NumberWithUnits &b);
        friend bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b);

        /* I\O */
        friend std::ostream &operator<<(std::ostream &ostream, const NumberWithUnits &a);
        friend std::istream &operator>>(std::istream &istream, NumberWithUnits &a);
    };

}