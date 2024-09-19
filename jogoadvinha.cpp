/*
*Prifry
*Date: 19/09/2024
*Description: To compile the code  we need to use the command: g++ jogoadvinha.cpp -o jogoadvinha.out , and to run we need the command: jogoadvinha.out.
*We have to recompile every time we make a change before we run it. Guided by Alura */

#include <iostream>  //To include the library for the input, output and flow. In order for the output and input to work, if not icluded it will show errors.
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std; // To say we are using the std library  and be able to  write cout <<""<< endl; in place of  std::cout<<""<<std::endl;

// Always start with the function: int main(){}
int main()
{

    cout << "***********************************" << endl; // the endl is to output the next print in the next line
    cout << "* Welcome to the Guessing Game!   *" << endl;
    cout << "***********************************" << endl;

    cout << "Choose the level of difficulty:   " << endl;
    cout << "Easy(E), Median(M), Difficult(D) " << endl;

    char level;
    cin >> level;
    int numOfTry;

    while(level !='E' && level != 'M' && level !='D'){
        cout<<"Wrong Character"<<endl;
        cout<<"Enter: E, M or D"<<endl;
        cin >> level;
    }
    if(level == 'E')
    {
        numOfTry = 15;
    }
    else if (level == 'M')
    {
        numOfTry = 10;
    }
    else if (level == 'D')
    {
        numOfTry = 5;
    }
  

    // To make the value of the secret number vary between runs of our game, we use the srand() and rand() functions.
//The first is used to determine the seed that will be used when generating the pseudo-random values in our program,
// and the second is used to return a random value. Need to include this two library #include <cstdlib>
//#include <ctime>
    srand(time(NULL));
    const int secret_num = rand() % 100; // to ouput this variable value write it like this in the cout<<" Hi "<<secret_num<< " don't tell anyone" << endl; 
                                        // % função módulo, ou resto de divisão, denotada por % para conseguir valores aleatórios menores

    // user guess input variable
    int guess;
    int count = 0;

    double points = 1000.0;

    // flag variables true or false for if statement(did not work)
    // bool guessCorrect = guess == secret_num;
    // bool guessHigh = guess > secret_num;

    for (count = 1; count <= numOfTry; count++)
    {

        cout << "What is your guessing number? " << endl;
        cin >> guess;
        double points_lost = abs(guess - secret_num) / 2.0;
        points = points - points_lost;
        cout << "The value of your guess is: " << guess << endl;

        if (guess == secret_num)
        {
            cout << "Congratulations you win!" << endl;
            cout << "You did it in: " << count << " tries. " << endl;
            cout.precision(2); // make the output points show the number in ex: the number 2 represents the two zeros after the dot 0.00 precisao dois zero depois do ponto. Always add it before the output needed to be modified
            cout << fixed;     // to not show the values in scientific way. Always add it after precision function
            cout << "Your points are: " << points << " points." << endl;
            cout << "END of Game" << endl;
        
            break; // Exit the loop if the guess is correct
        }
        else if (guess > secret_num)
        {
            cout << "Your number guess is too high. " << endl;
        }
        else
        {
            cout << "Your number guess is too low. " << endl;
        }

         // If the user did not guess correctly after the attempts
        if (count == numOfTry && guess != secret_num)
        {
            cout << "Sorry, you've used all " << numOfTry << " chances. The correct number was " << secret_num << "." << endl;
        }
    }


    return 0; // End of program
}
