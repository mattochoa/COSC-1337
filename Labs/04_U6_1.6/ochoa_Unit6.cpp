/*
    Author: Matthew Ochoa
    Status: Complete
    Desc: "Winning division: prompts for the quarterly sales of all four divisions, then reports the highest (or every division tied for it)."
    Last Updated: 10/7/2026

*/


#include <iostream> // provides iostream objects/tools
#include <iomanip>  // Needed for fixed/setprecision() dollar formatting
#include <sstream>  // Needed for parsing the user's input line into a number
#include <string>   // Needed for division names and raw input storage
#include <cstdlib>  // Needed for exit() and EXIT_FAILURE


// One division: its name and its quarterly sales figure
struct Division{std::string name; double sales;};


/////////////////////////
//////// SALES //////////
/////////////////////////


// Prompts for a division's quarterly sales using the name passed by main,
// re-prompting until the amount is a number greater than zero; returns it to main
double getSales(const std::string& name){

    constexpr double MINIMUM_SALES = 0.0; // Sales must be greater than this

    std::string line;      // Raw user input (consumes the whole line from cin)
    double sales = 0;      // Parsed sales amount
    char extra;            // Catches any leftover characters after the number
    bool validated = false; // for do-while condition

    do{
        // Prompt the user for input
        std::cout << "Enter the quarterly sales for the " << name << " division: ";

        // Take user input -> cin & store into -> line
        // If cin is closed (no input left), there is nothing to re-prompt for
        if(!std::getline(std::cin, line)){
            std::exit(EXIT_FAILURE);}

        // Initialize 's' string stream using line data
        std::istringstream s(line);

        // If it isn't a number, or has anything trailing it (e.g: '500abc')
        if(!(s >> sales) || s >> extra){
            std::cout << "Sales figures must be a number. Please re-enter." << std::endl;}

        // If it's zero or negative
        else if(sales <= MINIMUM_SALES){
            std::cout << "Sales figures must be greater than zero. Please re-enter." << std::endl;}

        // Otherwise it's valid
        else{
            validated = true;}

    // Run do loop as long as input is not validated
    }while(!validated);

    return sales;}


/////////////////////////
//////// HIGHEST ////////
/////////////////////////


// Determines which of the four divisions had the highest sales and displays its name and amount.
// If two or more divisions share the highest amount, displays every division in the tie instead
void findHighest(Division ne, Division se, Division nw, Division sw){

    constexpr int NUM_DIVISIONS = 4; // Number of divisions being compared
    constexpr int PRECISION = 2;     // Decimal places for dollar amounts

    // Group the four divisions so they can be looped over
    Division divisions[NUM_DIVISIONS] = {ne, se, nw, sw};

    Division highest = divisions[0]; // Start with the first division as the highest
    int ties = 0;                    // Number of divisions sharing the highest amount

    // Pass 1: find the highest amount
    for(const auto& d : divisions){
        if(d.sales > highest.sales){
            highest = d;}}

    // Pass 2: count how many divisions hit that amount (1 = no tie)
    for(const auto& d : divisions){
        if(d.sales == highest.sales){
            ties++;}}

    // Lock dollar formatting (decimal notation, 2 places) for the results
    std::cout << std::fixed << std::setprecision(PRECISION) << std::endl;

    // One clear winner
    if(ties == 1){
        std::cout << "The " << highest.name << " division had the highest sales this quarter." << std::endl;
        std::cout << "Their sales were $" << highest.sales << std::endl;}

    // Tie: list every division that matched the highest amount
    else{
        std::cout << "There was a " << ties << "-way tie for the highest sales this quarter:" << std::endl;

        for(const auto& d : divisions){
            if(d.sales == highest.sales){
                std::cout << "  The " << d.name << " division" << std::endl;}}

        std::cout << "Their sales were $" << highest.sales << " each" << std::endl;}}


// Main function: gets each division's sales via getSales(), then hands all four to findHighest()
int main(){

    // Each division starts with its name and no sales yet
    Division northeast{"Northeast", 0};
    Division southeast{"Southeast", 0};
    Division northwest{"Northwest", 0};
    Division southwest{"Southwest", 0};

    // Get the quarterly sales for each division, passing its name for the prompt
    northeast.sales = getSales(northeast.name);
    southeast.sales = getSales(southeast.name);
    northwest.sales = getSales(northwest.name);
    southwest.sales = getSales(southwest.name);

    // Determine and display the highest (or the tie)
    findHighest(northeast, southeast, northwest, southwest);

    // End of program
    return 0;}
