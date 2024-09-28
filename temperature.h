//Betty Phipps 0002 Fall 2024
//-----------Temperature.h-------------

enum Format {
    Default,
    Precision1,
    Long
};

class Temperature{

public:
    Temperature();                               //default constructor initializes to 0
    Temperature(double deg, char s);             //initializes to given temperature and scale

    // //input methods

    void Input();                               //promt user to enter a temperature (degrees, scale) within range

    //output methods
    void Show() const;                          //ouputs the temperature in current format with three possible display formatts

    //accessors return degrees and scale to caller, respectivly
    double GetDegrees() const;  
    char GetScale() const;      

    // //mutators
    bool Set(double deg, char s);               //operation should abort (i.e. the existing stored temperature should not be changed)
    bool SetFormat(char f);                     //adjusted inside the object based on the character code passed in.  This means that future uses of the Show function will display in this given format until the format is changed.
    
    bool Convert(char sc);                      //convert temperature to the new scale
    int Compare(const Temperature& deg) const;  //comparing the calling object and the parameter (-1 lower temp callin object, 0 same temp, 1 lower temp parameter)

private:
    //private member data
    double degrees;
    char scale;
    Format format;
};
