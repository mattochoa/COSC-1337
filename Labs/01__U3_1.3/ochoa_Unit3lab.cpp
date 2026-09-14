/*
    Author: Matthew Ochoa
    Status: Complete
    Desc: "User input validation for date format (mm/dd/yyyy), and iostate handler."
    Last Updated: (approx) 8:30pm 9/13/2026

*/


#include <iostream> // provides iostream objects/tools
#include <iomanip> // Needed for formatting output
#include <string> // Needed for input validation of user input stored into string objects
#include <sstream> // Needed for 's' stream cin buffer copy so getline can clear cin and store into 's' for later assignment
#include <cctype> // Needed for character type validation
#include <limits> // Used for finding max stream size when clearing streams
#include <thread> // used for 'sleep' function
#include <chrono> // used for 'sleep function


/////////////////////////
//////// UTILITY ////////
/////////////////////////


// Sleep for t second(s)
void wait(int t){
    std::this_thread::sleep_for(std::chrono::seconds(t));
}


// Clear the terminal screen
void clrScreen() {

    // Clear screen and move cursor to top-left
    std::cout << "\033[2J\033[1;1H"; 
}   


// Clear any flags in iostate
int clrFlags(std::istringstream& s){

    // Clear flags for console in stream
    std::cin.clear();

    // Clear flags for string in stream
    s.clear();

    return 0;
}


// Function for clearing streams
// Takes 's' string memory address as argument
int clrStream(std::istringstream& s){

    // Clear any flags raised in iostate
    clrFlags(s);

    // Store the max limit for the stream size
    auto max_size = std::numeric_limits<std::streamsize>::max();

    // Clear 's' stream buffer
    s.ignore(max_size, '\n');

    return 0;
}


////////////////////////////
//////// VALIDATION ////////
////////////////////////////

// Check if our user input is equal to the correct format length of characters (e.g: 'mm/dd/yyyy')
bool checkLen(std::string& line){

    if(line.length() == 10){
        return true;} // Input = 10 characters
    else{
        return false;} // Input != 10 characters
}


// Check if any whitespace characters exist in user input
bool checkSpaces(std::string& line){

    if(line.find_first_of(" \n\t")!=line.npos){
        return true;} // Input has  whitespace characters
        else{
            return false;} // Input doesn't have whitespace characters
}

// I came back after deadline to fix comments, but didn't cheat and modify logic.


// Check 1) if and 2) how many '/' characters exist in line
// Then 3) if the '/' are located in the correct places within given format (mm/dd/yy) (3 & 6)
// Then break user input via 'line' into substrings l1 = mm | l2 = dd | l3 == yyyy
bool checkSlash(std::string& line, std::string& l1, std::string& l2, std::string& l3){

    int count = 0;
    int stringLocation = 0;

    // Count occurences of '/' in line after loop(s) run
    // Don't run loop if no '/' are found
    while(line.find('/', stringLocation)!=line.npos){
        stringLocation = line.find('/', stringLocation) + 1;
        count++;}

    // If 2 '/' are found in character locations of 3 & 6 of 'line'
    // Break input into associated substrings for mm, dd, and yyyy
    // Then return true
    if(count == 2 && line[2] == '/' && line[5] == '/'){
        l1 = line.substr(0, 2);
        l2 = line.substr(3, 2);
        l3 = line.substr(6);
        return true;}

    // Otherwise return false
    else{return false;}
}


// Find out if each character in range of string 's' is between 0-9
// Return false if not; or true
bool isCharInt(std::string& s){

    int i = 0;
    int len = s.length();

    // While iterator 'i' is less than len(length of string 's')
    while (i<len){

        // If character at location 'i' @ 's' is not a digit
        // Return false | trigger invalidation
        if(std::isdigit((unsigned char)s[i])==0){
            return false;}
        i++;} // Iterate
    // Or return true if valid
    return true;
}


// Check if a given string 'str' is a digit via isCharInt()
// Check if the integer value of 'str' is greater than 0
int checkInt(std::string& str){

    // Is it a digit & Is it greater than 0?
    if(isCharInt(str) && std::stoi(str, 0)>0){
        // YES = return value of integer value of 'str'
        return std::stoi(str, 0);}
    // NO = return 0
    else{return 0;}
}


// Check if l1(mm) = maximum of 12 | l2(dd) = max of 31
// Check that l1, l2, l3 are digits and are greater than 1 via checkInt() returns not 0
bool checkCalVal(std::string& l1, std::string& l2, std::string& l3){

    int monInYr = 12;
    int dayInMo = 31;

    // if checkInt returns validation condition (return value > 0)
    // if l1 <= 12
    // if l2 <= 31
    if(checkInt(l1)!=0 && checkInt(l2) != 0 && checkInt(l3) != 0 && checkInt(l1)<=monInYr && checkInt(l2)<=dayInMo){
        //return true if validated
        return true;}
    // otherwise return false
    else{return false;}
}


// Validation orchestrator
// Takes a memory address poointer to 'line'
bool validate(std::string& line){

    // Initializes l1(mm), l2(dd), l3(yyyy)
    std::string l1, l2, l3;

    // validate length of 10 | Has no whitespaces | Has a count of 2 '/'(s); substring line into l1, l2, l3 ->
    // ->| line (as l1,l2,l3) Contains only integers > 0; l1(mm)<=12; l2(dd)<=31
    if(checkLen(line) && !checkSpaces(line) && checkSlash(line, l1, l2, l3) && checkCalVal(l1, l2, l3)){
        // If meets validation
        return true;}
    // IF invalid
    else{return false;}
}


// Obtain user input via getline of console-in data into 'line'
// Initialize 's' string stream using line data
std::istringstream getStream(){

    std::string line;       // For validation of user input (consumes cin)
    std::istringstream s;   // String responsible for assignment after validation
    bool validated = false; // for do-while condition

    do{
        // Prompt the user for input
        std::cout << "Enter date (mm/dd/yyyy): ";

        // Take user input -> cin & store into -> line
        std::getline(std::cin, line);
        s.str(line);
        s.clear(); // str() does not reset flags left over from a prior clrStream() ignore-to-eof

        // Capture input validation state in 'validated' via validate() provided user input of string 'line
        validated = validate(line);

        // If input is invalid
        if(!validated){
            // Notify user
            std::cout << "Invalid input format." << std::endl;
            // Wait 2 seconds
            wait(2);
            // Clear screen
            clrScreen();
            // Clear cin and string stream 's'
            clrStream(s);
        }
    // Run do loop as long as input is not validated
    }while(!validated);

    return s;
}


// Main func: initializes and stores core variables and streams
// Runs operation do-while loop
int main() {
    int month, day, year;
    char slash1, slash2;
    
    // Calls a function that returns a stream after validation
    getStream() >> month >> slash1 >> day >> slash2 >> year;
        
    // Print formatted date to user after user input is validated
    std::cout << "Month entered: " << std::setw(2) << std::setfill('0') << month << std::endl;
    std::cout << "Day entered:   " << std::setw(2) << std::setfill('0') << day << std::endl;
    std::cout << "Year entered:  " << year << std::endl;
        
    // End of program
    return 0;
}
