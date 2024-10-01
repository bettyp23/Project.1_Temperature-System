//Betty Phipps 0002 Fall 2024
//-------------temperature.cpp-------------------
//class definition for temperature

#include <iostream>
#include <iomanip>
#include <string>
#include "temperature.h"

using namespace std;

//Default constructor - initializes temperature to 0 degrees Celsius
//set to ), Celcius 'C', and default format
Temperature::Temperature() {
    degrees = 0;
    scale = 'C';
    format = Default;
}

// Parameterized constructor - initializes temperature with provided degree and scale
Temperature::Temperature(double deg, char s) {
// assign the scale based on user input
    if (s == 'C' || s == 'c' ){
        scale = 'C';
    }
    else if (s == 'F' || s == 'f'){
        scale = 'F';
    }
    else if (s == 'K' || s == 'k'){
        scale = 'K';
    }
    else 
        scale = 'C';                                    // Default to Celsius if invalid scale is provided
    
    // Assign degrees based on the scale with validation for absolute zero values
    if (scale == 'C'){
       (deg > -273.15) ? degrees = deg  : degrees = 0;
    }
    else if (scale == 'F'){
        (deg > -459.67) ? degrees = deg : degrees = 0;
    }
    else if (scale  == 'K'){
        (deg > 0) ? degrees = deg : degrees = 0;
    }
    else
        degrees = 0;

    format = Default;
}

// Input function for user to enter temperature and scale
void Temperature::Input(){
    double deg;
    char s;

    cout<<"Enter a temperature: "<<'\n';
    cin>>deg>>s;

    if (s == 'C' || s == 'c' ){
        scale = 'C';
    }
    else if (s == 'F' || s == 'f'){
         scale = 'F';
    }
    else if (s == 'K' || s == 'k'){
        scale = 'K';
    }
    else 
        scale = 'C';
    
    //// Assign degrees based on the scale with validation for minimum values
    if (scale == 'C'){
       if (deg > -273.15){
            degrees = deg;
       } else{
            degrees = 0;
       }
    }
    else if (scale == 'F'){
        if (deg > -459.67){
            degrees = deg;
        }else{
            degrees = 0;
        }
    }
    else if (scale  == 'K'){
        if (deg > 0){
            degrees = deg;
        } else{
            degrees = 0;
        }
    }
    else
        degrees = 0;           // Default to 0 if no valid input

    format = Default;          // Set the format to default
}

// Output function to display the temperature in the selected format
void Temperature::Show() const{
    switch (format) 
    {
    case Default:{
        cout<<degrees<<" "<<scale<<endl;
        break;
    }
    case Precision1:{
        cout<<fixed<<setprecision(1)<<degrees<<" "<<scale<<endl;
        cout.unsetf(ios::fixed); //unset the fixed format
        cout.precision(6);      //resent to default
        break;
    }
    case Long:{
        cout<<degrees<<" ";
    }

 // Display full name of the temperature scale
        if (scale == 'C'){
            cout<<"Celsius"<<endl;
        }
        else if (scale == 'F'){
            cout<<"Fahrenheit"<<endl;
        }
        else{
            cout<<"Kelvin"<<endl;
        }
        break;
    }
}     

// Getter for degrees
double Temperature::GetDegrees() const{
    return degrees;
} 

// Getter for scale
char Temperature::GetScale() const{
    return scale;
}    

 bool Temperature::Set(double deg, char s){   
 //check if scale is valid and check it
    if (s == 'C' || s == 'c' ) {
        scale = 'C';
    }
    else if (s == 'F' || s == 'f') {
        scale = 'F';
    }
    else if (s == 'K' || s == 'k'){
        scale = 'K';
    }
    else {
        return false;
    }
    
    //assign the degree based on valid scale: else return false and the current value does not change
    if (scale == 'C'){
       if (deg > -273.15){
            degrees = deg;
       }
        else{
            return false;
        }
    }
    else if (scale == 'F'){
        if (deg > -459.67){
                degrees = deg;
        }
        else{
            return false;
        }
    }
    else if (scale  == 'K'){
        if (deg > 0){
            degrees = deg;
        }
        else{
            return false;
        }
    }

    return true;                          // Successfully set the temperature
 }

// Set the format of the temperature display
bool Temperature::SetFormat(char f){
    switch (f) {
        case 'D':
            format = Default;             // Default format
            return true;
        case 'P':
            format = Precision1;          // Set to 1 decimal precision
            return true;
        case 'L':
            format = Long;                // Set to long format
            return true;
        default:
            return false;                 // Invalid format

    }
}

// Convert the temperature to the specified scale (Celsius, Fahrenheit, or Kelvin)      
bool Temperature::Convert(char sc){
    double newScale  = degrees;
    
// Check if the desired scale is valid
    if (sc != 'C' && sc != 'c' && sc != 'K' && sc != 'k' && sc != 'F' && sc != 'f'){
        return false;
    }
    else{
        if (sc == 'C' || sc == 'c'){
            if (scale == 'F'){
                newScale = (degrees - 32) * (5.0 / 9.0);   // Convert Fahrenheit to Celsius
            }
            else if (scale == 'K'){
                newScale = degrees - 273.15;               // Convert Kelvin to Celsius
            }
            scale = 'C';
        }

        else if (sc == 'F' || sc == 'f'){
            if (scale == 'C'){
                newScale = degrees * (9.0/5.0) + 32;       // Convert Celsius to Fahrenheit
            }
            else if (scale == 'K'){
                newScale = (degrees - 273.15) * (9.0/5.0) + 32;  // Convert Kelvin to Fahrenheit
            }
            scale = 'F';
        }

        else if (sc == 'K' || sc == 'k'){
            if (scale == 'C'){
                newScale = degrees + 273.15;    // Convert Celsius to Kelvin
            }
            else if (scale == 'F'){
                newScale = (degrees - 32) * (5.0/9.0) + 273.15;   // Convert Fahrenheit to Kelvin
            }
            scale = 'K';
        }
    }

        degrees = newScale;          // Set the new converted degrees
        return true;
    };
   
// Compare this temperature object with another temperature
int Temperature::Compare(const Temperature& deg) const{

//copying the variables into temporary temperature
    Temperature temporaryTemp = deg;
    
    // Convert the other temperature to the same scale as this one for comparison
    temporaryTemp.Convert(scale);

    if ( temporaryTemp.degrees < degrees ){
        return 1;   // This temperature is greater
    }
    else if ( temporaryTemp.degrees > degrees ){
        return -1;  // This temperature is smaller
    }
    else {
        return 0;   // Temperatures are equal
    }
}