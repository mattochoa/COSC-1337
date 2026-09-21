/*
    Author: Matthew Ochoa
    Status: Complete
    Desc: "Demonstrates std::isdigit() from <cctype>: takes 1 char argument and returns nonzero (true) if it is a digit 0-9, otherwise 0 (false)."
    Last Updated: 9/20/2026

*/


#include <iostream> // Using std::cout, std::cin, & std::endl
#include <cctype> // Using std::isdigit() | "Checks if the given character is one of the 10 decimal digits: (0123456789)"


// Return true if user hasn't entered 'q'
bool running(){

    // Input character definition and assignment
    char sChar;

    // Prompt the user for a character
    std::cout << std::endl << "Enter a character: ";
    std::cin >> sChar;

    // If input matches sentinal value 'q'; quit the program
    if(sChar == 'q'){

        std::cout << std::endl << "Program quiting..." << std::endl;

        return false;}
        
    else{

        // Otherwise print out if the user input is a qualified digit
        if(std::isdigit((unsigned char)sChar)){

            std::cout << "Char: " << sChar << " IS a digit between 0-9" << std::endl;}
        else{

            std::cout << "Char: " << sChar << " is NOT a digit between 0-9" << std::endl;}
    }

    // Input was not the sentinal value; keep running
    return true;
}


// Main func: notifies the user of the sentinal value and runs the input loop
int main(){

    // Notify user of what the program does
    std::cout << "This program checks whether a character is a digit (0-9)." << std::endl;

    // Notify user of sentinal value
    std::cout << "Type q to QUIT." << std::endl;

    // Keep running as long as sentinal isn't input
    while(running()){}

    // End of program
    return 0;
}
