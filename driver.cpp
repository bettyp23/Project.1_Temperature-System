// /////////////////////////////////////////////////////////
// // Bob Myers
// //
// // sample.cpp -- sample test program starter for Temperature class
// /////////////////////////////////////////////////////////

#include <iostream>
#include "temperature.h"

using namespace std;

int main() {
    // Test constructors
    Temperature t1; // default constructor
    Temperature t2(100, 'C'); // constructor with valid temperature and scale
    Temperature t3(0, 'K'); // constructor with valid temperature in Kelvin
    Temperature t4(-500, 'F'); // invalid temperature for Fahrenheit (below absolute zero)

    Temperature t5(0, 'C');
    Temperature t6(31.5, 'F');

    // Test Show function
    cout << "Testing Show function:\n";
    t1.Show(); // should show 0 C (default)
    t2.Show(); // should show 100 C
    t3.Show(); // should show 0 K
    t4.Show(); // should show 0 F (invalid input was set to 0)
    
    // Test Set function
    cout << "\nTesting Set function:\n";
    if (t1.Set(36.5, 'C')) {
        cout << "Set t1 to 36.5 C successfully.\n";
    } else {
        cout << "Failed to set t1.\n";
    }
    t1.Show(); // should show 36.5 C

    // Test Convert function
    cout << "\nTesting Convert function:\n";
    t2.Convert('F');
    t2.Show(); // should convert 100 C to 212 F
    t3.Convert('C');
    t3.Show(); // should convert 0 K to -273.15 C
    t1.Convert('K');
    t1.Show(); // should convert 36.5 C to 309.65 K

    // Test Compare function
    cout << "\nTesting Compare function:\n";
    cout << "t1 vs t2: " << t1.Compare(t2) << endl; // t1 is 309.65 K, (97.7) t2 is 212 F, t1 should be higher -> result: 1
    cout << "t2 vs t1: " << t2.Compare(t1) << endl; // t2 should be lower -> result: -1
    cout << "t3 vs t4: " << t3.Compare(t4) << endl; // t3 is -273.15 C, t4 is 0 F -> result: -1
    cout << "t5 vs t6 " << t6.Compare(t5) << endl; // t3 is -273.15 C, t4 is 0 F -> result: -1

    // Test SetFormat and Show with different formats
    cout << "\nTesting SetFormat and Show:\n";
    t2.SetFormat('P');
    t2.Show(); // should show 212.0 F with precision of 1
    t2.SetFormat('L');
    t2.Show(); // should show "Long: 212 Fahrenheit"
    t2.SetFormat('D');
    t2.Show(); // should show 212 F (default format)
    
    return 0;
}
