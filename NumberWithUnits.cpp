#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{
    const double eps = 0.000001; 
    map<string, map<string, double>> NumberWithUnits::con_map = {}; // init con_map

    void NumberWithUnits::read_units(ifstream &file_name){
        double first = 0;
        double second = 0;

        string first_unit;
        string second_unit; 
        string equal;

        while (file_name >> first >> first_unit >> equal >> second >> second_unit){

            con_map[first_unit][second_unit] = second;
            con_map[second_unit][first_unit] = first / second;
            
            //connect the first unit:
            for (auto &current_unit : con_map[first_unit]){
                double current_val = con_map[second_unit][first_unit] * current_unit.second;

                con_map[second_unit][current_unit.first] = current_val;
                con_map[current_unit.first][second_unit] = 1 / current_val;
            }

            //connect the second unit:
            for (auto &current_unit : con_map[second_unit]){
                double current_val = con_map[first_unit][second_unit] * current_unit.second;

                con_map[first_unit][current_unit.first] = current_val;
                con_map[current_unit.first][first_unit] = 1 / current_val;
            }
        }
    }

    /* Auxiliary function for conversions */
    double Convert(double val, const string &first_unit, const string &second_unit){
        if (NumberWithUnits::con_map[first_unit].count(second_unit) == 0){
            throw "Uknown conversion ! ! !";
        }
        //if there the same
        if (first_unit == second_unit){
            return val;
        }

        return (val * NumberWithUnits::con_map[first_unit][second_unit]);
    }

    /*!!!!! Operators !!!!!*/

    NumberWithUnits operator+(const NumberWithUnits &a, const NumberWithUnits &b){
        double b_to_a = Convert(b.value, b.unit, a.unit);
        return NumberWithUnits(b_to_a + a.value, a.unit);
    }

    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits &other){
        this->value+= Convert(other.value,other.unit,this->unit);
        return *this;
    }

    NumberWithUnits operator+(const NumberWithUnits &a){
        return NumberWithUnits(a.value,a.unit);
    }

     NumberWithUnits &operator++(NumberWithUnits &a){ //prefix   
        a.value++;
        return a;
    }

    NumberWithUnits operator++(NumberWithUnits &a, int){ //postfix
        return NumberWithUnits(a.value++,a.unit);
    }

    NumberWithUnits &operator--(NumberWithUnits &a){//prefix
        a.value--;
        return a;
    }

    NumberWithUnits operator--(NumberWithUnits &a, int){//postfix
        NumberWithUnits pre(a.value--,a.unit);
        return pre;
    }

    NumberWithUnits operator-(const NumberWithUnits &a, const NumberWithUnits &b){
        double b_to_a = Convert(b.value, b.unit, a.unit);
        return NumberWithUnits(a.value-b_to_a, a.unit);
    }

    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits &other){
        this->value -= Convert(other.value, other.unit, this->unit);
        return *this;
    }

    NumberWithUnits operator-(const NumberWithUnits &a){
        return NumberWithUnits(-a.value,a.unit);
    }

    /* multiplication operator */

    NumberWithUnits operator*(const NumberWithUnits &a, double b){
        return NumberWithUnits(a.value*b, a.unit);
    }

    NumberWithUnits operator*(double b,const NumberWithUnits &a){ 
        return NumberWithUnits(a.value*b, a.unit);
    }

    NumberWithUnits operator*(const NumberWithUnits &a,const NumberWithUnits &b){
        double con = Convert(b.value,a.unit,b.unit);
        return NumberWithUnits(a.value*con, a.unit);
    }

    /* Boolean operators */
    bool operator>(const NumberWithUnits &a, const NumberWithUnits &b){
       bool ans = a.value > Convert(b.value,b.unit,a.unit); 
       return ans;
    }

    bool operator>=(const NumberWithUnits &a, const NumberWithUnits &b){
        double b_to_a = Convert(b.value,b.unit,a.unit);
        bool ans = a.value>b_to_a || abs(a.value-b_to_a)<eps;
        return ans;
    }

    bool operator<(const NumberWithUnits &a, const NumberWithUnits &b){
        bool ans = a.value<Convert(b.value,b.unit,a.unit);
        return ans;
    }

    bool operator<=(const NumberWithUnits &a, const NumberWithUnits &b){
        double b_to_a = Convert(b.value,b.unit,a.unit);
        bool ans = a.value<b_to_a || abs(a.value-b_to_a)<eps;
        return ans;
    }

    bool operator==(const NumberWithUnits &a, const NumberWithUnits &b){
        bool ans = abs(a.value-Convert(b.value,b.unit,a.unit))<eps;
        return ans;
    }

    bool operator!=(const NumberWithUnits &a, const NumberWithUnits &b){
        bool ans = a.value!=Convert(b.value,b.unit,a.unit);
        return ans;
    }

    /* I\O operators */

    ostream &operator<<(ostream &ostream, const NumberWithUnits &a){
        return (ostream << a.value << "[" << a.unit << "]");
    }

    istream &operator>>(istream &istream, NumberWithUnits &a){
        double value = 0;
        string unit;
        char current = ' ';
        bool flag = false;
        istream>>value;
        while(current!=']'){
            if(current=='['){
                flag = true;
            }
            istream>>current;
            if(flag){
                if(current!=' '&&current!=']') {
                    unit+=current;
                }
            }
        }
        if(NumberWithUnits::con_map.count(unit)==0){
            throw " Invalid Unit";
        }
        //updates
        a.unit = unit;
        a.value = value;
        return istream;
    }
}