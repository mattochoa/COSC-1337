/*
    Author: Matthew Ochoa
    Status: Complete
    Desc: "Voter tally: generates random votes to votes.dat, reads them back, and reports yes/no totals and a per-district breakdown."
    Last Updated: 9/20/2026

*/


#include <iostream> // provides iostream objects/tools
#include <fstream> // Needed for reading and writing the votes.dat file
#include <vector> // Needed for per-district tally storage
#include <random> // Needed for the random vote and district generators
#include <string> // Needed for passing prompt text into ask()
#include <algorithm> // Needed for max() when validating district count


// Vote choice values (used as the tally enum)
enum Tally {Y, N};


//////////////////////////
//////// RANDOM //////////
//////////////////////////


// Random number generators for votes and districts
class Random{

    // Random engine seeded from hardware entropy
    std::mt19937 gen{std::random_device{}()};

public:

    // Number of districts (never less than 1)
    int districts = 3;

    // Generate a value of (0,1) and return it as the Tally enum {Y,N}
    Tally tally(){

        return Tally(std::uniform_int_distribution<int>(0, 1)(gen));}

    // Generate a district value of (1, districts)
    int district(){

        return std::uniform_int_distribution<int>(1, districts)(gen);}
};


////////////////////////
//////// VOTE //////////
////////////////////////


// A single vote entity: which district it came from and how it was cast
class Vote{

public:

    int district;
    Tally tally;

    // Default to district 1 and a yes vote
    Vote(int d = 1, Tally t = Y){

        district = d;
        tally = t;}
};


////////////////////////////////
//////// ORCHESTRATOR //////////
////////////////////////////////


// Handles file io, tallying, output, and the program menu loop
class Orchestrator{

    Random rng;                     // Generators for votes and districts
    int numVotes = 5;               // Number of votes to generate per run
    const char* file = "votes.dat"; // Data file name

    // Generate numVotes random votes and write them to the data file
    void writeVotes(){

        std::ofstream out(file);

        for(int i = 0; i < numVotes; i++){

            // Build one random vote
            Vote v(rng.district(), rng.tally());

            // Write it as: district Y/N
            out << v.district << ' ' << (v.tally == Y ? 'Y' : 'N') << '\n';}}

    // Read the data file back and print the yes/no totals and district breakdown
    void readAndReport(){

        std::ifstream in(file);

        // Index 0 is unused so districts line up with their number (1 to districts)
        std::vector<int> yes(rng.districts + 1);
        std::vector<int> no(rng.districts + 1);

        int totalYes = 0;
        int totalNo = 0;
        int d;
        char c;

        // Read each line of the file: district then Y/N
        while(in >> d >> c){

            Vote v(d, c == 'Y' ? Y : N);

            // Add the vote to its district and to the overall total
            if(v.tally == Y){
                yes[v.district]++;
                totalYes++;}
            else{
                no[v.district]++;
                totalNo++;}
        }

        // Print overall totals
        std::cout << "Total: " << totalYes << " yes, " << totalNo << " no" << std::endl;

        // Print breakdown by district
        for(int i = 1; i <= rng.districts; i++){
            std::cout << "District " << i << ": " << yes[i] << " yes, " << no[i] << " no" << std::endl;}}

    // Display a prompt and return the integer the user enters
    int ask(const std::string& prompt){

        int value;

        std::cout << prompt;
        std::cin >> value;

        return value;}

public:

    // Program loop: generate, read, report, then prompt for a menu action
    void run(){

        bool running = true;

        while(running){

            writeVotes();
            readAndReport();

            switch(ask("\n1) Change districts  2) Change votes  3) Exit: ")){

                // Change districts (a district count of 0 is not allowed)
                case 1:
                    rng.districts = std::max(1, ask("Districts: "));
                    break;

                // Change the number of votes to count
                case 2:
                    numVotes = ask("Votes: ");
                    break;

                // Exit (or any other entry ends the loop)
                default:
                    running = false;}
        }
    }
};


// Main function: creates the orchestrator and runs the program
int main(){

    Orchestrator().run();

    // End of program
    return 0;}
