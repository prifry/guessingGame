/*Compile: g++ guessgameimproved.cpp -o guessgameimproved.out 
**Run: guessgameimproved.out
* Prifry
*Date: 09/19/2024 
 Description: This is an improved version of the prior guessing game*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> //For input validation

using namespace std; 

//constants for points and secret number range
const int MAX_POINTS = 1000;
const int Max_sSECRET_NUM_EASY = 50;
const int MAX_SECRET_NUM_MEDIUM = 100;
const int Max_secret_NUM_DIFFICULT= 200;

//Function to display the welcome message
void print_welcome_message(){
    cout <<"------------------------------------"<<endl;
    cout <<"-   Welcome to the Guessing Game!  -"<<endl;
    cout <<"------------------------------------"<<endl;
}

//Function to select difficulty level
char select_difficulty(){
    char level; //check the dificulty level
    do{
        cout<<"Choose the level of difficulty: Easy(E), Medium(M), Difficult(D): "<<endl;
        cin>>level;
    } while(level != 'E' && level != 'M' && level != 'D');
    return level;
}

//Function to set the number of attempts based on difficulty
int set_attemps(char level){
    switch (level)
    {
        case 'E': return 15;
        case 'M': return 10;
        case 'D': return 5;
        default: return 10; //Default to medium if erro occurs
     
    }
}

//Function to set the range of the secret number based on difficulty
int set_secret_num(char level){
    switch (level)
    {
    case 'E': return rand() % (Max_sSECRET_NUM_EASY +1); //0 TO 50
    case 'M': return rand() % (MAX_SECRET_NUM_MEDIUM + 1); // 0 TO 100
    case 'D': return rand() % (Max_secret_NUM_DIFFICULT + 1); //0 to 200
    default: return rand() % (MAX_SECRET_NUM_MEDIUM +1); //Default range for Medium
       
    }
}

//Function to validate user input for guessing
int get_valid_guess(){
    int guess;
    while(true){
        cout <<"What is your guess?" << endl;
        cin >> guess;

        if(cin.fail()){
            cin.clear(); //clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip to the next line
            cout<<"Invalid input, please enter a number."<<endl;
        }else{
            return guess;
        }
    }
}
//Function to calculate points lost for each guess
double calculate_points_lost(int guess, int secret_num){
    return abs(guess - secret_num) / 2.0;
}

//Main game logic
void play_game(int secret_num, int numOfTry){
    int guess;
    double points = MAX_POINTS;
    for(int count = 1; count <= numOfTry; count++){
        guess = get_valid_guess();
        double points_lost = calculate_points_lost(guess, secret_num);
        points -= points_lost;
        if(guess == secret_num){
            cout<<"Congratulations! You guessed the number in "<<count<<" tries."<<endl;
            cout.precision(2);
            cout<<fixed<<" Your score: "<<points <<endl;
            return;
        }else if(guess > secret_num){
            cout << "Your guess is too high."<<endl;
        }else{
            cout<<"Your guess is too low."<<endl;
        }
    }
    //If all attempts are used
    cout<<"Sorry, you've used all "<<numOfTry<<" atttempts. The correct number was "<<secret_num<<endl;
}

//Function to ask if the player wants to play again
bool play_again(){
    char response;
    cout<<"Do you want to play again? (y/n): "<<endl;
    cin>>response;
    return(response == 'y' || response == 'Y');
}

//Main Function
int main(){
    srand(time(NULL)); //Seed the random number generator
    do{
        print_welcome_message();
        char level = select_difficulty();
        int numOfTry = set_attemps(level);
        int secret_num = set_secret_num(level);

        play_game(secret_num, numOfTry);

    }while(play_again());
    cout<<"Thanks for playing!"<<endl;
    return 0;
    
}
