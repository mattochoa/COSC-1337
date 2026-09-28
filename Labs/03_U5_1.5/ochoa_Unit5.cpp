/*
    Author: Matthew Ochoa
    Status: In Progress
    Desc: "Weekly sales report: reads employee car-sale records from carsales.dat and prints a per-employee commission subtotal via control-break processing."
    Last Updated: 9/27/2026

*/


#include <iostream>  // provides iostream objects/tools
#include <fstream>   // Needed for reading carsales.dat
#include <sstream>   // Needed for parsing each line's fields out of a std::string
#include <string>    // Needed for line/path storage
#include <vector>    // Needed for storing each employee's sale records
#include <array>     // Needed for the fixed set of file-validation error messages
#include <cctype>    // Needed for isalpha()/isdigit() header validation
#include <iomanip>   // Needed for setw()/setprecision() column formatting
#include <cstdlib>   // Needed for abort()


// Aborts the entire program (called on any unrecoverable input error)
void out(){
    std::abort();}


//////////////////////////
//////// FILE /////////////
//////////////////////////


// Opens the data file, validates its header row, and hands back lines one at a time
class File{

public:

    // Opens the file at the given path and validates its headers; aborts if either fails
    File(const char* path): fs{}, file{path}, line{}{

        fs.open(file);

        // A failed open leaves failbit set immediately, before anything is read
        if(fs.rdstate() == std::ios_base::failbit){
            std::cout << replyPrefix << file << rep[0] << std::endl; // File doesn't exist!
            out();}

        clearHeaders();}

    // Confirms the file is non-empty, starts with a header row of the right width,
    // and has at least one data row beneath it; aborts on the first problem found
    void clearHeaders(){

        // If file doesn't exist
        if(fs.rdstate() == std::ios_base::eofbit){
            std::cout << replyPrefix << file << rep[1] << std::endl; // File is empty!
            out();} // abort()

        // If first character of file isn't alphabetical
        else if(!std::isalpha(fs.peek())){
            std::cout << replyPrefix << file << rep[2] << std::endl; // File has no headers!
            out();} // abort()
        
        // Otherwise...
        else{

            // Take the file headers into 'line' via getline()
            std::getline(fs, line);

            // If headers don't match exact length
            if(line.size() != 30){
                std::cout << replyPrefix << file << rep[3] << std::endl; // File has misformatted headers
                out();} // abort()
            
            // If the next character after headers isn't a digit
            else if(!std::isdigit(fs.peek())){
                std::cout << replyPrefix << file << rep[4] << std::endl; // File has no entries
                out();} // abort()

            line.erase();}} // Wipe File::line

    // Reads one line into 'line'; returns false once the file is consumed.
    // NOTE: fs.eof()/fs.rdstate() do not reliably update on my compiler setup so had to static cast getline
    bool read(){
        // Return true unless file is empty/consumed
        // Feed next line from file stream into line and consume from stream
        return static_cast<bool>(std::getline(fs, line));}

    // Returns the most recently read line
    std::string& getLine(){
        return line;}

    std::ifstream fs;   // Input stream for the data file
    std::string file;   // Path to the data file
    std::string line;   // Most recently read line

private:
    const std::string replyPrefix = "File: \""; // Prefix for every validation message
    // Handy static vector of user warnings
    std::array<std::string, 5> rep{"\" DOESN'T EXIST!", "\" is EMPTY!", "\" has NO HEADERS!", "\" has MISFORMATTED HEADERS!", "\" has no entries!"};
};


//////////////////////////////
//////// EMPLOYEE //////////////
//////////////////////////////


// One car sale: retail price, base price, and the commission it earned
struct Sale{float retail, base, commissions;};


// Accumulates one employee's sale records and commission subtotal, and
// detects control breaks (the point where the employee ID changes)
class Employee{

public:

    // Initialize st, eRecords upon class instantiation. 'nullptr'
    Employee(): st{}, eRecords{}{}

    // Parses one line into the current group; returns false when the ID on
    // this line differs from the current group's (a control break)
    bool operator()(std::string ln){

        // Clear flags in iostate
        st.clear();
        // Store arguments into stream object
        st.str(ln);

        // As long as not control break...
        if(!contBreak()){
            storeVals(eRecords);    // r.3 | Explictly (not necessary) pass eRecords to storeVals()
            tLines += 1;            // Count # of lines in group
            return true;}           // Return true | Is NOT control break condition
        else{return false;}}        // Return false | Is control break condition

    // Reads the ID field and reports whether it differs from the current group's ID.
    // Does NOT touch eRecords/tLines/totalC yet: the caller (r.1) (in processRecords > while > if) still needs to print the
    // OLD group's summary using that data before startGroup() resets it.
    bool contBreak(){

        // Context: Each time a line must be parsed
        // Store first value after header line into eID
        st >> eID;

        // Return condition false, unless control break condition
        return lastID != eID;}

    // Called right after the caller (r.2) prints the old group's summary. Resets the
    // accumulators and stores the just-read row (whose retail/base are still
    // sitting unread in 'st') as the first record of the new group.
    void startGroup(){
        lastID = eID;         // Advance the group's ID to the one that just broke
        eRecords.clear();     // Drop the old group's sale records
        tLines = 0;           // Reset the line count for the new group
        totalC = 0;           // Reset the commission subtotal for the new group
        storeVals(eRecords);  // r.4 | store the triggering row as this group's first sale
        tLines += 1;}         // Count that first sale

    // Reads retail/base off the current line, computes the commission, and stores the sale.
    // Called from two spots: the normal (non-break) path in operator() (r.3), and
    // startGroup() (r.4), which reuses 'st' right where contBreak() left off after
    // consuming just the ID token.
    float storeVals(std::vector<Sale>& v){

        float v1, v2, v3;
        st >> v1 >> v2;       // Pull retail and base off the line (ID was already consumed)
        v3 = getCom(v2);      // Commission is derived from the base price
        totalC += v3;         // Add this sale to the group's running commission subtotal

        Sale sale{v1, v2, v3};
        v.push_back(sale);    // Record the sale so Elines() can print it later
        return v3;}

    // Commission is 30% of base price, or $100, whichever is greater
    float getCom(float base){

        float commision = base * static_cast<float>(0.3);

        // 30% of base fell short of the $100 floor
        if(commision <= 100){
            return 100;}
        // 30% of base cleared the floor, so it stands as the commission
        else{
            return commision;}}

    unsigned int tLines = 0;    // Number of sale records stored for the current group
    float eID = 0;              // ID parsed from the line currently being processed
    float lastID = -1;          // ID of the current group (sentinel: no employee ID is negative)
    std::istringstream st;      // Stream used to parse the current line's fields
    std::string line;           // Unused scratch line (kept for interface symmetry with File)
    std::vector<Sale> eRecords; // Sale records for the current group
    float totalC = 0;           // Commission subtotal for the current group
};


////////////////////////////
//////// REPORT ///////////////
////////////////////////////


// Column justification: LEFT or RIGHT
enum Format{LEFT, RIGHT};

// One header column: its label, justification, and width
struct Header{std::string label; Format justify; int width;};

// One printed value: the number, justification, and width
struct Value{float val; Format justify; int width;};

// Prints the column header row and the divider beneath it
void breakHeaders(std::ostream& o){

    // One header entry per report column, in print order
    Header headers[] = {{"EMPLOYEE", Format::LEFT, 7}, {"RETAIL", Format::RIGHT, 13}, {"BASE", Format::RIGHT, 14}, {"Commission", Format::RIGHT, 17}};

    for(const auto& h : headers){
        // LEFT column (Format::LEFT == 0, so !h.justify also catches it)
        if(!h.justify)
            o << std::left << std::setw(h.width) << h.label;
        // RIGHT column
        else if(h.justify)
            o << std::right << std::setw(h.width) << h.label;}

    o << std::endl << std::string(55, '-') << std::left;} // Divider line under the headers

// Wraps a print function with a blank line before and after.
// func: the print routine to sandwich (r.5 passes breakHeaders in from Elines())
void printWrap(std::ostream& o, void func(std::ostream& o)){
    o << std::endl;   // Blank line before
    func(o);          // Run whatever print routine the caller handed us
    o << std::endl;}  // Blank line after

// Prints every stored sale for the current employee group
void Elines(std::vector<std::vector<Value>>& eData, Employee& e, std::ostream& o){

    printWrap(o, breakHeaders); // r.5 | hands breakHeaders in as printWrap's func
    o << std::fixed;            // Lock decimal notation (not scientific) for this whole block

    for(unsigned int i = 0; i < e.tLines; i++){

        // One printable Value per column, pulled from this group's i-th sale record
        Value lines[] = {{e.lastID, Format::LEFT, 6}, {e.eRecords[i].retail, Format::RIGHT, 14}, {e.eRecords[i].base, Format::RIGHT, 14}, {e.eRecords[i].commissions, Format::RIGHT, 14}};

        for(const auto& data : lines){
            // LEFT column: the employee ID, printed as a whole number
            if(!data.justify){
                o << std::string(2, ' ') << std::setprecision(0) << std::left << std::setw(data.width) << data.val;}
            // RIGHT column: dollar amounts, two decimal places
            else if(data.justify){
                o << std::setprecision(2) << std::right << std::setw(data.width) << data.val;}}

        o << std::setprecision(0) << std::endl;                  // Reset precision before the next row
        eData.emplace_back(std::begin(lines), std::end(lines));} // Keep a copy of this row in eData's history

    o << std::endl;}

// Prints one employee's full report block: header, sale lines, and commission subtotal.
// func: the row-printing routine to run in the middle (r.6 passes Elines in from processRecords())
void eSumm(std::vector<std::vector<Value>>& eData, Employee& e, std::ostream& o, void func(std::vector<std::vector<Value>>& eData, Employee& e, std::ostream& o)){

    o << std::string(55, '.') << std::left << std::endl << std::endl; // Top divider
    o << std::string(3, ' ') << "WEEKLY SALES REPORT" << std::endl;   // Title
    o << std::string(55, '=') << std::left;                           // Divider under the title

    func(eData, e, o); // Prints this group's rows (Elines(), via r.6)

    // e.lastID/e.totalC still belong to the group func() just printed
    o << std::string(2, ' ') << "***Total Commission for " << e.lastID << ": $" << std::setprecision(2) << e.totalC << std::endl;
    o << std::string(55, '_') << std::left << std::endl;} // Bottom divider


// Reads carsales.dat line by line, printing a report block on every control
// break, plus one final block for the last group once the file is exhausted
void processRecords(){

    std::vector<std::vector<Value>> eData; // History of every printed row, across all groups
    File fst("carsales.dat");              // Opens + validates the data file (aborts on any problem)
    std::ostream& o{std::cout};             // Where the report gets printed
    Employee e;                             // Accumulates the current group as lines come in

    // Context: one iteration per line of carsales.dat
    while(fst.read()){
        // e(...) returns false exactly on a control break (see contBreak())
        if(!e(fst.getLine())){
            if(e.tLines > 0){ // r.1 | skip: nothing accumulated yet before the very first group
                eSumm(eData, e, o, Elines);} // r.6 | passes Elines in as eSumm's func
            // r.2 | Now lets store the info
            e.startGroup();}}

    eSumm(eData, e, o, Elines); // r.6 | last group never hits a break, so print it here
}


// Entry point: runs the report
int main(){

    // Report Trigger
    processRecords();

    // End of program
    return 0;}
