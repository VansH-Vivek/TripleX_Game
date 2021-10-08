#include<iostream>
#include<ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << endl;
    // print welcome messages to terminal
    cout << "You are a secret agent breaking into a level "<< Difficulty << " secure server room..." << endl;
    cout << "Enter the correct code to continue..." << endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
  
    // const not change value
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print CodeSum and CodeProduct to the terminal
    cout << endl;
    cout << "+ There are 3 numbers in the code" << endl;
    cout << "+ The codes add-up to: " << CodeSum << endl;
    cout << "+ The codes multiply to give: " << CodeProduct <<endl;

    // store player guess  
    int GuessA, GuessB, GuessC;
   
    cout << endl;
    cout << "Enter GuessA = ";
    cin >> GuessA;
    cout << "Enter GuessB = ";
    cin >> GuessB;
    cout << "Enter GuessC = ";
    cin >> GuessC;
    // cout << "You entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA *  GuessB *GuessC;

    // chack if the player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << endl;
        cout << "Well done agent! You have extracted a fail! Keep going! " << endl;
        return true;
    }
    else
    {
        cout << endl;
        cout << "You entered the wrong code! Carful again! Try again! "<< endl;
        return false;
    }
    
}

int main()
{
    srand(time(NULL)); //create new random sequence based on time of day

    int LevekDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevekDifficulty <= MaxDifficulty) // Loop game unill all levels completed
    {
        bool bLevelComplete = PlayGame(LevekDifficulty);
        cin.clear(); //clears any errors
        cin.ignore(); //discard the buffer

        if (bLevelComplete)
        {
            //increase the leveldifficulty
            ++LevekDifficulty;
        }
        
    }
    cout << endl;
    cout << "Great work agent! You got all the files! now get out of ther!" << endl;
    cout << endl;
    return 0;
}