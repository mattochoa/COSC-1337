/*
    Author: Matthew Ochoa
    Status: Complete
    Desc: "Vehicle travel range calculator, given fuel efficiency (mpg) and fuel tank capacity(gal)."
    Last Updated: 9:23pm 9/4/2026

*/

// Including <cmath> for std::round() functionality (line: 38)
#include <iostream>
#include <cmath>
using namespace std;


// Prompt and Store input for (capacity: float) and (mpg: float)
// Calculate (range: float) = (mpg*capacity)
// Output 2 displays (1) range rounded to nearest mile, (2) range with full decimal values
int main() {
    
    // capacity (Fuel tank capacity)
    // mpg (Fuel efficiency)
    // range (The estimated max travel range)
    float capacity, mpg, range;

    //  Prompt & Input to store (capacity: float) and (mpg: float)
    cout << "Enter the fuel tank capacity in gallons: ";
    cin >> capacity;
    cout << "Enter the estimated miles per gallon: ";
    cin >> mpg;

    // Calculate (range: float) = (capacity: float) * (mpg: float)
    range = capacity * mpg; 

    // Output Display 1 (range rounded to nearest mi)
    cout << endl;
    cout << "Distance Range For Miles (rounded):" << endl;
    cout << "The car can be driven " << round(range) << " miles without refueling." << endl << endl;

    // Output Display 2 range with full decimal values
    cout << "Distance Range For Miles (full):" << endl;
    cout << "The car can be driven " << range << " miles without refueling." << endl << endl;
    
    // Complete main function successfully
    return 0;

}
