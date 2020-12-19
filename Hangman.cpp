#include "Hangman.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

Hangman::Hangman() {

}

void Hangman::intro() {


    cout << "Welcome to a game of Hangman!!!" << endl;
    cout << "We are going to randomly choose a cartoon character that you have to try to guess." << endl;
    cout << "You are going to guess a letter at a time and if you guess wrong, the Hangman will slowly build up." << endl;
    cout << "Once the Hangman is complete, you lose" << endl;
    cout << "Otherwise, you win!" << endl;
    cout << "If you see the Hangman, click on the Hangman to continue guessing." << endl;
    cout << "Here is the word" << endl;

    //Put vector of _____

     randomNameForReal = randCartoon();
     makeLines();
     for (int i = 0; i < nameSize; i++) {
         cout << lines[i];
         cout << " ";
     }
     cout << endl;
     while (win == false) {
         cin >> guess;
         rightLetter(guess);
         if (lose == true) {
             return;
         }
     }
     cout << "you win" << endl;
     return;

}


//gets random string from cartoon
string Hangman::randCartoon() {
    srand(time(0));
    int randomNum = rand() % 30;
    string cartName = cartoon[randomNum];
   
    return cartName;
}      
//vector of Lines
void Hangman::makeLines() {
    randName = randomNameForReal;
    
    nameSize = randName.length();
    lines.resize(nameSize);
    for (int i = 0; i < nameSize; i++) {
        lines.at(i) = '_';  //cinderella
      
    }
    
}
//check if letter repeated or a number
void Hangman::checkIfGuessed(char a) {
    
    for (int i = 0; i < lettersGuessed.size(); i++) {
        if (a == lettersGuessed[i]) {

            charNotRepeated = false;
        }
    }
    if (!isalpha(a)) {
        charNotRepeated = false;
    }


}
bool Hangman::checkLetter(char a) {
    
        
    
        for (int i = 0; i < nameSize; i++) {
            if (a == randName[i]) {

                return 1;
            }

        }
        return 0;
       
    
}  
//if letter is found
void Hangman::rightLetter(char a) {
    a = tolower(a);
    checkIfGuessed(a);
    
        if (charNotRepeated) {


            bool b = checkLetter(a);
            if (b) {
                for (int i = 0; i < nameSize; i++) {
                    if (a == randName[i]) {
                        lines[i] = a;
                        winCounter++;
                    }

                }
                cout << "Yaay, there is/are '" << a << "' in the word" << endl;
            }
            else if (!b) {
                cout << "There is no '" << a << "' in the word" << endl;

                ++counter;

                switch (counter) {
                case 1:
                    head();
                    break;
                case 2:
                    body();
                    break;
                case 3:
                    leftArm();
                    break;
                   
                case 4:
                    rightArm();
                    break;
                case 5:
                    leftLeg();
                    break;
                case 6:
                    
                    rightLeg();
                    break;
                }

            }



        }
        else {
            cout << "You have entered the same letter again or an invalid value" << endl;
            charNotRepeated = true;
        }



        cout << randName << endl;
        for (int i = 0; i < nameSize; i++) {
            cout << lines[i];
            cout << " ";
        }
        cout << endl;
        lettersGuessed.push_back(a);
        if (winCounter == lines.size()) {
            win = true;
        }
        if (counter == 6) {
            cout << "You Lose" << endl;
            lose = true;
    }
}    //Add to vector of lines






void Hangman::hangStand() {

    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/


        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);


        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}


void Hangman::head() {
    
    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/


        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);

        CircleShape circle;
        circle.setRadius(120);
        circle.setPosition(240, 320);
        circle.setFillColor(Color::Red);
        window.draw(circle);
        window.display();

       

        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}
void Hangman::body() {
    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/

        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);

        CircleShape circle;
        circle.setRadius(120);
        circle.setPosition(240, 320);
        circle.setFillColor(Color::Red);
        window.draw(circle);
        window.display();

        RectangleShape rect;
        rect.setSize(Vector2f(80, 240));
        rect.setPosition(320, 560);
        rect.setFillColor(Color::Red);
        window.draw(rect);

        


        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}
void Hangman::leftArm() {
    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/
        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);

        CircleShape circle;
        circle.setRadius(120);
        circle.setPosition(240, 320);
        circle.setFillColor(Color::Red);
        window.draw(circle);
        window.display();

        RectangleShape rect;
        rect.setSize(Vector2f(80, 240));
        rect.setPosition(320, 560);
        rect.setFillColor(Color::Red);
        window.draw(rect);

        RectangleShape leftArm;
        leftArm.setSize(Vector2f(120, 80));
        leftArm.setPosition(200, 600);
        leftArm.setFillColor(Color::Red);
        window.draw(leftArm);
        

        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}
void Hangman::rightArm() {
    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/

        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);

        CircleShape circle;
        circle.setRadius(120);
        circle.setPosition(240, 320);
        circle.setFillColor(Color::Red);
        window.draw(circle);
        window.display();

        RectangleShape rect;
        rect.setSize(Vector2f(80, 240));
        rect.setPosition(320, 560);
        rect.setFillColor(Color::Red);
        window.draw(rect);

        RectangleShape leftArm;
        leftArm.setSize(Vector2f(120, 80));
        leftArm.setPosition(200, 600);
        leftArm.setFillColor(Color::Red);
        window.draw(leftArm);
        RectangleShape rightArm;
        rightArm.setSize(Vector2f(120, 80));
        rightArm.setPosition(400, 600);
        rightArm.setFillColor(Color::Red);
        window.draw(rightArm);


       
        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}
void Hangman::leftLeg() {
    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/
        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);

        CircleShape circle;
        circle.setRadius(120);
        circle.setPosition(240, 320);
        circle.setFillColor(Color::Red);
        window.draw(circle);
        window.display();

        RectangleShape rect;
        rect.setSize(Vector2f(80, 240));
        rect.setPosition(320, 560);
        rect.setFillColor(Color::Red);
        window.draw(rect);

        RectangleShape leftArm;
        leftArm.setSize(Vector2f(120, 80));
        leftArm.setPosition(200, 600);
        leftArm.setFillColor(Color::Red);
        window.draw(leftArm);
        RectangleShape rightArm;
        rightArm.setSize(Vector2f(120, 80));
        rightArm.setPosition(400, 600);
        rightArm.setFillColor(Color::Red);
        window.draw(rightArm);


        RectangleShape leftLeg;
        leftLeg.setSize(Vector2f(80, 120));
        leftLeg.setPosition(240, 800);
        leftLeg.setFillColor(Color::Red);
        window.draw(leftLeg);


        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}
void Hangman::rightLeg() {
    RenderWindow window(VideoMode(1000, 1000), "SFML Template");




    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear();

        /***** PLACE YOUR DRAWING CODE HERE *****/
        RectangleShape base;
        base.setSize(Vector2f(320, 80));
        base.setPosition(600, 800);
        base.setFillColor(Color::Magenta);
        window.draw(base);

        RectangleShape core;
        core.setSize(Vector2f(80, 640));
        core.setPosition(720, 160);
        core.setFillColor(Color::Magenta);
        window.draw(core);

        RectangleShape top;
        top.setSize(Vector2f(400, 80));
        top.setPosition(320, 160);
        top.setFillColor(Color::Magenta);
        window.draw(top);

        RectangleShape end;
        end.setSize(Vector2f(80, 80));
        end.setPosition(320, 240);
        end.setFillColor(Color::Magenta);
        window.draw(end);
        
        CircleShape circle;
        circle.setRadius(120);
        circle.setPosition(240, 320);
        circle.setFillColor(Color::Red);
        window.draw(circle);
        window.display();

        RectangleShape rect;
        rect.setSize(Vector2f(80, 240));
        rect.setPosition(320, 560);
        rect.setFillColor(Color::Red);
        window.draw(rect);

        RectangleShape leftArm;
        leftArm.setSize(Vector2f(120, 80));
        leftArm.setPosition(200, 600);
        leftArm.setFillColor(Color::Red);
        window.draw(leftArm);
        RectangleShape rightArm;
        rightArm.setSize(Vector2f(120, 80));
        rightArm.setPosition(400, 600);
        rightArm.setFillColor(Color::Red);
        window.draw(rightArm);


        RectangleShape leftLeg;
        leftLeg.setSize(Vector2f(80, 120));
        leftLeg.setPosition(240, 800);
        leftLeg.setFillColor(Color::Red);
        window.draw(leftLeg);

        RectangleShape rightLeg;
        rightLeg.setSize(Vector2f(80, 120));
        rightLeg.setPosition(400, 800);
        rightLeg.setFillColor(Color::Red);
        window.draw(rightLeg);

        /***** END OF DRAWING	*****/

        // Apply all the draws to the screen
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed) {

                window.close();
            }
        }

    }
}
