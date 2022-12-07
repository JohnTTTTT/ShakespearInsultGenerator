#include <vector>
#include <string>

using namespace std;

const string sourceFile("InsultsSource.txt");

class FileException{    
    //Class defined for source file open/close errors

    public:
        FileException(const string&);   
        //Constructor
        string what() const;    
        //Returns error message

    private:
        string msg;     
        //Attribute

};

class NumInsultsOutOfBounds{    
    //Class defined for source file format errors

    public:
        NumInsultsOutOfBounds(const string&);   
        //Constructor
        string what() const;    
        //Returns error message

    private:
        string msg;     
        //Attribute

};

class InsultGenerator{    
    //Class defined for the main branch of code
    
    public:
        InsultGenerator();  
        //Constructor
        void initialize();  
        //Opens the source file and stores each possible adjective inside one of three vectors
        string talkToMe() const;    
        //Returns an individual insult 
        vector<string> generate(int) const;     
        //Randomizes the locations of each adjective stored in the three arrays and intializes there locations to be true inside a boolean array.
        //In a different loop we create a string that contains the full sentence that includes all the adjectives whose locations were stored randomly inside the boolean array
        //Then we store that string inside a single string vector which we then return
        void generateAndSave(string, int) const;    
        //Creates a new file containing each complete insult sentence

    private:                           
        int fileSize;	    
        //Attribute					
	    int random(int) const;      
        //Returns a random integer within the range of the input
        vector<string> adjective1;	    
        //1 of 3 vectors storing collumb one of the adjectives from the source file
	    vector<string> adjective2;		
        //2 of 3 vectors storing collumb two of the adjectives from the source file
	    vector<string> adjective3;      
        //3 of 3 vectors storing collumb three of the adjectives from the source file

};