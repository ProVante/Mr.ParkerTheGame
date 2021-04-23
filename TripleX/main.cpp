// Preprocessor Directive
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>

using namespace std;

// Gets ASCII art from starting text file
std::string getFileContents (std::ifstream&); 
int ASCIIArtStart()
{
    std::ifstream Reader ("Start.txt");

    std::string Art = getFileContents(Reader);       //Get file
    
    std::cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

// Gets ASCII art from loser text file
int ASCIIArtLose()
{
    std::ifstream Reader ("Loser.txt");

    std::string Art = getFileContents(Reader);       //Get file
    
    std::cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

// Gets Content in file
std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline(File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}

// Sends the intro when game starts
void PrintIntro(int Difficulty)
{
    // Prints out the game situation and prompt to the user
    std::cout << "You are a student trying to hack your way into Mr. Parker's computer in order to change your * UNIT " << Difficulty << " TEST * grade." << endl;
    std::cout << "You need to guess his secret password on his desktop to get access to his gradebook..." << endl;
    std::cout << "Good luck soldier...\n" << endl;  
}

// Starts the game
bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    // Declaration Statements: Const will make it a constant value, which actually means it can't be changed
    const int CodeA = (rand() % Difficulty + Difficulty);
    const int CodeB = (rand() % Difficulty + Difficulty);
    const int CodeC = (rand() % Difficulty + Difficulty);

    // Stores the code sum and code product into variables
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Expression statements, tells the user the sum and the product of the code
    cout << "+ There are 3 numbers in the code!" << endl;
    cout << "+ The sum of the codes numbers are: " << CodeSum << endl;
    cout << "+ The product of of the code numbers are: " << CodeProduct << endl;

    // Stores user input into variables
    int GuessA, GuessB, GuessC;
    cout << "\nPlease enter in the code and each number separated by a space: ";
    cin >> GuessA >> GuessB >> GuessC;

    // Stores the guess sum and guess product into variables
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Checks if GuessSum and GuessProduct is the same as CodeSum and CodeProduct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "\nYou hacked Mr. Parkers computer!" << endl;
        return true;
    } else
    {
        ASCIIArtLose();
        cout <<  "WRONG! Mr. Parker caught you trying to hack his computer! GAME OVER!" << endl;
        return false;
    }
}

// Main function
int main()
{   
    //Creates a new random seed everytime the game is played
    srand(time(NULL));

    // Sets the difficulty
    int LevelDifficulty = 1;
    const int MaxDifficulty = 4;
    bool bWin;

    // Start screen art
    ASCIIArtStart();

    // Will loop through the game and increase game difficulty until completed
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();
        bWin = true;
        if (bLevelComplete)
        {
            ++LevelDifficulty;
        } else {
            bWin = false;
            break;
        }
    }
    
    // Sends the congradulations message
    if (bWin)
    {
       cout << "Congratulations! You aced all four quarters!" << endl; 
    }

    // Press ENTER to quit application
    cout << "Press ENTER to quit the application..." << endl;
    getchar();

    return 0;

    // NOTE: Expression statements are any statements in code that end in ';'
}
