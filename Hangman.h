#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

class Hangman {

public:
    string randomNameForReal;
    char guess;
    int counter = 0;
    int winCounter = 0;
    Hangman();
    bool charTrue = false;
    bool lose = false;
    vector <char> user;
    vector <char> lines;
    vector <char> lettersGuessed;
    bool charNotRepeated = true;
    int nameSize = 0;
    string randName;

    void intro();
   

    bool checkLetter(char a);   //compares to string from randCartoon ...ifright( function for right) if wrong(functionf for wrong)
    string randCartoon();       //gets random string from cartoon
    void checkIfGuessed(char a);
    void rightLetter(char a);    //Add to vector of lines
    
    void makeLines();



    void hangStand();
    void head();
    void body();
    void leftArm();
    void rightArm();
    void leftLeg();
    void rightLeg();




    bool win = false;






private:

    string cartoon[30] = {
        "piplup",
        "batman",
        "sasuke",
        "goku",
        "vegeta",
        "pikachu",
        "simpsons",
        "griffins",
        "wolverine",
        "sonic",
        "arnold",
        "johnny",
        "eric",
        "stan",
        "kenny",
        "starfire",
        "raven",
        "piplup",
        "cinderella",
        "ariel",
        "aurora",
        "anastasia",
        "candice",
        "nemo",
        "woody",
        "tarzan",
        "scooby",
        "pooh",
        "mickey",
        "simba" };


};
