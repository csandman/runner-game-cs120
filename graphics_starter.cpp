#include "graphics.h"
#include "Runner.h"
#include "Obstacle.h"
#include "floorSpikes.h"
#include "Button.h"
#include "account_list.h"
#include <vector>
#include <string>
#include <iostream>
#include "time.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
using namespace std;

GLdouble width, height;
enum mode {start, highScores, playerSelect, game, gameOver};
mode screen;
int wd;
int score;
int ogXPos;
int ogYPos;
bool isKeyDown;
bool isJumping;
bool reachedMaxHeight;
bool boosted;
int colorChange;
Runner player;
vector<floorSpikes> spikes;
vector<Runner> boosts;
vector<vector<string>> highScoresVect;
point mouseLocation;
point boostSpawn;

Button startButton, highscoresButton, restart, quitButton, backButton;
Button redRunner, orangeRunner, yellowRunner, greenRunner, blueRunner, purpleRunner, blackRunner;
Button floor;
vector<Button> colorSelect;
vector<color> colors;

color red, orange, yellow, green, blue, purple, gray, black, gold;
color playerColor;

AccountList acc_list;
string current_account;


void init() {

    width = 500;
    height = 500;
    screen = start;
    score = 0;
    isKeyDown = false;
    isJumping = false;
    reachedMaxHeight = false;

    player = Runner(20,20,150,400,0,0,0);
    floor = Button(100, 500, 250,463, gray, gray); // y pos of 463 is perfect, 464 has a gap which kinda looks nice
    spikes.push_back(floorSpikes(20,20,800,410));
    spikes.push_back(floorSpikes(20,20,1000,410));
    spikes.push_back(floorSpikes(20,20,1200,410));
    spikes.push_back(floorSpikes(20,20,1400,410));
    spikes.push_back(floorSpikes(20,20,1600,410));
    spikes.push_back(floorSpikes(20,20,1800,410));
    spikes.push_back(floorSpikes(20,20,1820,410));
    spikes.push_back(floorSpikes(20,20,2020,410));
    spikes.push_back(floorSpikes(20,20,2040,410));
    spikes.push_back(floorSpikes(20,20,2240,410));
    spikes.push_back(floorSpikes(20,20,2260,410));
    spikes.push_back(floorSpikes(20,20,2480,410));
    spikes.push_back(floorSpikes(20,20,2655,410));
    spikes.push_back(floorSpikes(20,20,2830,410));
    spikes.push_back(floorSpikes(20,20,3005,410));
    spikes.push_back(floorSpikes(20,20,3180,410));
    spikes.push_back(floorSpikes(20,20,3355,410));
    spikes.push_back(floorSpikes(20,20,3530,410));
    spikes.push_back(floorSpikes(20,20,3730,410));
    spikes.push_back(floorSpikes(20,20,3930,410));
    spikes.push_back(floorSpikes(20,20,4130,410));
    spikes.push_back(floorSpikes(20,20,4150,410));
    spikes.push_back(floorSpikes(20,20,4350,410));
    spikes.push_back(floorSpikes(20,20,4370,410));
    spikes.push_back(floorSpikes(20,20,4570,410));
    spikes.push_back(floorSpikes(20,20,4590,410));
    spikes.push_back(floorSpikes(20,20,4610,410));
    spikes.push_back(floorSpikes(20,20,4810,410));
    spikes.push_back(floorSpikes(20,20,4830,410));
    spikes.push_back(floorSpikes(20,20,4850,410));
    spikes.push_back(floorSpikes(20,20,5000,410));
    spikes.push_back(floorSpikes(20,20,5020,410));
    spikes.push_back(floorSpikes(20,20,5040,410));
    spikes.push_back(floorSpikes(20,20,5240,410));
    spikes.push_back(floorSpikes(20,20,5260,410));
    spikes.push_back(floorSpikes(20,20,5280,410));
    spikes.push_back(floorSpikes(20,20,5480,410));
    spikes.push_back(floorSpikes(20,20,5680,410));
    spikes.push_back(floorSpikes(20,20,5880,410));
    spikes.push_back(floorSpikes(20,20,5900,410));
    spikes.push_back(floorSpikes(20,20,6100,410));
    spikes.push_back(floorSpikes(20,20,6120,410));
    spikes.push_back(floorSpikes(20,20,6320,410));
    spikes.push_back(floorSpikes(20,20,6340,410));
    spikes.push_back(floorSpikes(20,20,6360,410));
    spikes.push_back(floorSpikes(20,20,6560,410));
    spikes.push_back(floorSpikes(20,20,6580,410));
    spikes.push_back(floorSpikes(20,20,6780,410));
    spikes.push_back(floorSpikes(20,20,6800,410));
    spikes.push_back(floorSpikes(20,20,7000,410));
    spikes.push_back(floorSpikes(20,20,7200,410));
    spikes.push_back(floorSpikes(20,20,7220,410));
    spikes.push_back(floorSpikes(20,20,7240,410));
    spikes.push_back(floorSpikes(20,20,7260,410));


    highScoresVect = acc_list.getHighScores();


    ogXPos = 250;
    ogYPos = 400;
    red = color(1,0,0);
    orange = color(1,140/255.0,0);
    yellow = color(1,215/255.0,0);
    green = color(0,128/255.0,0);
    blue = color(0,0,1);
    purple = color(158/255.0,0,1);
    gray = color(169/255.0,169/255.0,169/255.0);
    black = color(0,0,0);
    gold = color(1,215/255.0,0);

    colors.push_back(red);
    colors.push_back(orange);
    colors.push_back(yellow);
    colors.push_back(green);
    colors.push_back(blue);
    colors.push_back(purple);
    colors.push_back(black);


    startButton = Button(50,150,250,250,gray,gray);
    highscoresButton = Button(50,150,250,350,gray,gray);
    restart = Button(50,200,250,250,red,black);
    quitButton = Button(50,200,250,350,red,black);
    backButton = Button(50,75,70,50,yellow,black);


    redRunner = Button(25,25,100,300,red,red);
    orangeRunner = Button(25,25,150,300,orange,orange);
    yellowRunner = Button(25,25,200,300,yellow,yellow);
    greenRunner = Button(25,25,250,300,green,green);
    blueRunner = Button(25,25,300,300,blue,blue);
    purpleRunner = Button(25,25,350,300,purple,purple);
    blackRunner = Button(25,25,400,300,black,black);

    boostSpawn = point(810,350);
    boosts.push_back(Runner(10,10,boostSpawn,gold));

    srand(time(NULL));

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* UPDATE HIGH SCORE FUNCTION */

void updateHighScore() {
    int accountIndex = acc_list.indexFromUsername(current_account);
    Account currentAcc = acc_list.getAccount(accountIndex);
    if (currentAcc.getScore() < score) {
        currentAcc.setScore(score);
        acc_list.deleteAccount(accountIndex);
        acc_list.addAccount(currentAcc);
    }
}


void displayTesting() {

    string message1 = "The Very Possible Game";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(150, 150);
    for (char c : message1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }


    //startButton.draw();

    Runner r = Runner();
    r.setFill(1,0,0);
    r.setCenter(300,300);
    r.draw();
}


void displayStart(){
    glClearColor(0,0,0,1);

    string message1 = "The Very Possible Game";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(125, 150);
    for (char c : message1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }


    startButton.draw();

    string message2 = "Play";
    glColor3f(1.0,1.0,1.0);
    glRasterPos2i(228,256);
    for (char c : message2){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    }

    highscoresButton.draw();

    string message3 = "High Scores";
    glColor3f(1.0,1.0,1.0);
    glRasterPos2i(190,356);
    for (char c : message3){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    }

}

void displayCharSelect(){

    glClearColor(169/255.0,169/255.0,169/255.0,1.0);

    string message1 = "Pick a color for your Runner:";
    glColor3f(1.0,1.0,1.0);
    glRasterPos2i(100, 150);
    for (char c : message1){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    redRunner.draw();
    orangeRunner.draw();
    yellowRunner.draw();
    greenRunner.draw();
    blueRunner.draw();
    purpleRunner.draw();
    blackRunner.draw();
}

void displayGameOver(){

    glClearColor(169/255.0,169/255.0,169/255.0,1.0);

    string gameOverMessage = "Game Over!";
    glColor3f(1,0,0);
    glRasterPos2i(190, 150);
    for(char c : gameOverMessage){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);

    }

    restart.draw();

    string message2 = "Try Again";
    glColor3f(1.0,1.0,1.0);
    glRasterPos2i(202,256);
    for (char c : message2){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    }

    quitButton.draw();

    string message3 = "Quit";
    glColor3f(1.0,1.0,1.0);
    glRasterPos2i(225,356);
    for (char c : message3){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    }


}

void displayGame(){
    glClearColor(1.0,1.0,1.0,1.0);

    floor.draw();
    player.draw();
    for (int i = 0; i < boosts.size() ; ++i) {
        boosts[i].draw();
        boosted = false;
        if (player.collectBoost(boosts[i])){
            boosts[i].move(5000,0);
            score += 10;
            }

        }


    for (int i = 0; i < spikes.size(); ++i) {
        spikes[i].draw();

        if (player.isColliding(spikes[i])) //If statement to detect overlap between player circle and spikes.
        {
            spikes[i].setCorner(width, spikes[i].getCorner().y);
            boosts[0].setCenter((width+boosts[0].center.x/2.0),boosts[0].center.y);
            updateHighScore();
            screen = gameOver;
        }
    }

    string scoreMessage = "Score: " + to_string(score);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2i(25,50);
    for (char c : scoreMessage) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

}


void displayHighScores() {
    glClearColor(1.0,1.0,1.0,1.0);

    int yPos1 = 120;
    int yPos2 = 120;


    for (string str : highScoresVect[0]) {
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2i(100,yPos1);
        for (char c : str) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
        yPos1 += 35;
    }

    for (string str : highScoresVect[1]) {
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2i(300,yPos2);
        for (char c : str) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
        }
        yPos2 += 35;
    }

    backButton.draw();

    string backMessage = "Back";
    glColor3f(0,0,0);
    glRasterPos2i(44,59);
    for (char c : backMessage){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,c);
    }


}



/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */
    switch (screen) {
        case start:
            displayStart();
            break;

        case playerSelect:
            score = 0;
            displayCharSelect();
            break;

        case game:
            displayGame();
            break;

        case gameOver:
            displayGameOver();
            break;

        case highScores:
            displayHighScores();
            break;
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    if (screen == start)
    {
        if (key == 'p')
        {
            screen = playerSelect;
        }

        if (key == 'h')
        {
            screen = highScores;
        }
    }

    if (screen == highScores)
    {
        if (key == 'b')
        {
            screen = start;
        }
    }

    if (screen == game) {
        if (key == 32) {
            isKeyDown = true;
        }
    }

    if (screen == gameOver)
    {
        if (key == 'q')
        {
            glutDestroyWindow(wd);
            exit(0);
        }

        if (key == 't')
        {
            screen = start;
            player.center = player.ogPos;
            for (int i = 0; i < spikes.size(); ++i)
            {
                spikes[i].setCorner(spikes[i].ogPos);
            }
        }
    }
        glutPostRedisplay();

        return;
}
void kbdUp(unsigned char key, int x, int y){

    if(key == 32)
    {
        isKeyDown = false;
    }
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            if (colorChange - 1 < 0){
                colorChange = 6;
            }else {
                colorChange -= 1;
            }

            if (player.center.x > 10) {
                player.move(-6, 0);
            }
            break;
        case GLUT_KEY_RIGHT:
            if (colorChange + 1 > 6){
                colorChange = 0;
            }else{
                colorChange += 1;
            }
            if (player.center.x < (width-10)) {
                player.move(6, 0);
            }
            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
    
    return;
}


void cursor(int x, int y) {

    mouseLocation.x = x;
    mouseLocation.y = y;


    if (startButton.isOverlapping(mouseLocation)) {
        startButton.highlightBorder();
    }
    else if (!startButton.isOverlapping(mouseLocation)) {
        startButton.setBorder(gray);
    }

    if (backButton.isOverlapping(mouseLocation)) {
        backButton.highlightBorder();
    }
    else if (!backButton.isOverlapping(mouseLocation)) {
        backButton.setBorder(gray);
    }

    if (highscoresButton.isOverlapping(mouseLocation)) {
        highscoresButton.highlightBorder();
    }
    else if (!highscoresButton.isOverlapping(mouseLocation)) {
        highscoresButton.setBorder(gray);
    }

    if (redRunner.isOverlapping(mouseLocation)) {
        redRunner.highlightBorder();
    }
    else if (!redRunner.isOverlapping(mouseLocation)) {
        redRunner.setBorder(red);
    }

    if (orangeRunner.isOverlapping(mouseLocation)) {
        orangeRunner.highlightBorder();
    }
    else if (!orangeRunner.isOverlapping(mouseLocation)) {
        orangeRunner.setBorder(orange);
    }

    if (yellowRunner.isOverlapping(mouseLocation)) {
        yellowRunner.highlightBorder();
    }
    else if (!yellowRunner.isOverlapping(mouseLocation)) {
        yellowRunner.setBorder(yellow);
    }

    if (greenRunner.isOverlapping(mouseLocation)) {
        greenRunner.highlightBorder();
    }
    else if (!greenRunner.isOverlapping(mouseLocation)) {
        greenRunner.setBorder(green);
    }

    if (blueRunner.isOverlapping(mouseLocation)) {
        blueRunner.highlightBorder();
    }
    else if (!blueRunner.isOverlapping(mouseLocation)) {
        blueRunner.setBorder(blue);
    }

    if (purpleRunner.isOverlapping(mouseLocation)) {
        purpleRunner.highlightBorder();
    }
    else if (!purpleRunner.isOverlapping(mouseLocation)) {
        purpleRunner.setBorder(purple);
    }

    if (blackRunner.isOverlapping(mouseLocation)) {
        blackRunner.highlightBorder();
    }
    else if (!blackRunner.isOverlapping(mouseLocation)) {
        blackRunner.setBorder(black);
    }

    if(restart.isOverlapping(mouseLocation)){
        restart.highlightBorder();
    }
    else if(!restart.isOverlapping(mouseLocation)){
        restart.setBorder(black);
    }

    if(quitButton.isOverlapping(mouseLocation)){
        quitButton.highlightBorder();
    }
    else if(!quitButton.isOverlapping(mouseLocation)){
        quitButton.setBorder(black);
    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if(screen == start &&startButton.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        screen = playerSelect;
    }

    if(screen == start &&highscoresButton.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        highScoresVect = acc_list.getHighScores();
        screen = highScores;
    }

    if(screen == playerSelect && redRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(red);
        playerColor = red;
        colorChange = 0;
        screen = game;
    }

    if(screen == playerSelect && orangeRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(orange);
        playerColor = orange;
        colorChange = 1;
        screen = game;
    }

    if(screen == playerSelect && yellowRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(yellow);
        playerColor = yellow;
        colorChange = 2;
        screen = game;
    }

    if(screen == playerSelect && greenRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(green);
        playerColor = green;
        colorChange = 3;
        screen = game;
    }

    if(screen == playerSelect && blueRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(blue);
        playerColor = blue;
        colorChange = 4;
        screen = game;
    }

    if(screen == playerSelect && purpleRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(purple);
        playerColor = purple;
        colorChange = 5;
        screen = game;
    }

    if(screen == playerSelect && blackRunner.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        player.setFill(black);
        playerColor = black;
        colorChange = 6;
        screen = game;
    }

    if(screen == gameOver && restart.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        screen = start;
        player.center = player.ogPos;
        for (int i = 0; i < spikes.size(); ++i)
        {
            spikes[i].setCorner(spikes[i].ogPos);
        }
    }

    if(screen == gameOver && quitButton.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glutDestroyWindow(wd);
        exit(0);
    }

    if(screen == highScores && backButton.isOverlapping(mouseLocation) && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        screen = start;
    }
    glutPostRedisplay();

}

void timer(int time) {
    int deltaX = ogXPos + player.center.x;
    int deltaY = ogYPos - player.center.y;

    if(screen == game)
    {
        switch (colorChange){
            case 0:
                player.setFill(colors[0]);
                break;
            case 1:
                player.setFill(colors[1]);
                break;
            case 2:
                player.setFill(colors[2]);
                break;
            case 3:
                player.setFill(colors[3]);
                break;
            case 4:
                player.setFill(colors[4]);
                break;
            case 5:
                player.setFill(colors[5]);
                break;
            case 6:
                player.setFill(colors[6]);
                break;
            }

        if (time % 10 == 0) {
            score++;
        }
        if (deltaY != 0) {
            isJumping = true;
        } else {
            isJumping = false;
        }

        if (isKeyDown == true && deltaY <= 60 && reachedMaxHeight == false) {
            player.move(0, -6);
        }
        else if ((isKeyDown == false && deltaY > 0) || (isKeyDown == true && reachedMaxHeight == true && deltaY > 0))
        {
            player.move(0, 6);
        }
        else if (deltaY >= 60)
        {
            reachedMaxHeight = true;
        }
        else if (deltaY == 0)
        {
            reachedMaxHeight = false;
        }

        for (int i = 0; i < spikes.size(); ++i) {
            spikes[i].move(-7,0);

            if (spikes[i].getCorner().x < 0) {
                spikes[i].setCorner(7300, spikes[i].getCorner().y);
            }


        }
        for (int i = 0; i < boosts.size() ; i++) {
            boosts[i].move(-7,0);
            if (boosts[i].getCenter().x < 0){
                boosts[i].move(5000, boosts[i].getCenter().y);
            }
        }


    }

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}


/**
 *
 *      ACCOUNT MANAGEMENT STUFF
 *
 */


void clearInput() {
    cin.clear();
    string junk = "";
    getline(cin, junk);
}

bool containsSpace(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (isspace(str[i])) {
            return true;
        }
    }
    return false;
}

bool containsNumber(string str) {
    if (str.find('0') != string::npos ||
        str.find('1') != string::npos ||
        str.find('2') != string::npos ||
        str.find('3') != string::npos ||
        str.find('4') != string::npos ||
        str.find('5') != string::npos ||
        str.find('6') != string::npos ||
        str.find('7') != string::npos ||
        str.find('8') != string::npos ||
        str.find('9') != string::npos)  {
        return true;
    }
    return false;
}

bool containsSpecialCharacters(string str) {
    if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890-") != std::string::npos) {
        return true;
    }
    return false;
}

string adjustCase(string str) {
    str[0] = toupper(str[0]);
    for (int i = 1; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void createAccount() {
    string firstName = " ";
    string lastName = " ";
    string userName = " ";
    string password = " ";

    cout << "Enter your first name:" << endl;

    getline(cin, firstName);
    while (containsSpace(firstName) || containsNumber(firstName) || containsSpecialCharacters(firstName)) {
        cout << "This name is not valid, please try again" << endl;
        getline(cin, firstName);
    }
    firstName = adjustCase(firstName);


    cout << "Enter your last name:" << endl;
    getline(cin, lastName);
    while (containsSpace(lastName) || containsNumber(lastName) || containsSpecialCharacters(lastName)) {
        cout << "This name is not valid, please try again" << endl;
        getline(cin, lastName);
    }
    lastName = adjustCase(lastName);

    cout << "Enter a username:" << endl;
    getline(cin, userName);
    while (containsSpace(userName) || acc_list.indexFromUsername(userName) != -1) {
        cout << "Your username is invalid, please try again" << endl;
        getline(cin, userName);
    }

    cout << "Enter a password:" << endl;
    getline(cin, password);
    while (containsSpace(password)) {
        cout << "Your username cannot contain any spaces, please try again" << endl;
        getline(cin, password);
    }

    Account new_account(firstName,lastName,userName,password,0);
    acc_list.addAccount(new_account);
}

void printWelcomeMessage(Account acc) {
    // Output Manipulation
    string message = "Welcome back " + acc.getFirstName() + " " + acc.getLastName() + "!";
    cout << message << endl;
}

void login() {

    string userName = " ";
    string password = " ";

    cout << "Enter your username:" << endl;
    getline(cin, userName);
    int accountIndex = -1;
    while (acc_list.indexFromUsername(userName) == -1) {
        cout << "Your username is not in the system, please try again" << endl;
        getline(cin, userName);
    }
    accountIndex = acc_list.indexFromUsername(userName);

    cout << "Enter your password:" << endl;
    getline(cin, password);
    while (!acc_list.passwordMatches(userName, password)) {
        cout << "Your password does not match, please try again" << endl;
        getline(cin, password);
    }

    current_account = userName;
    printWelcomeMessage(acc_list.getAccount(accountIndex));
}

void search() {
    cout << "Enter a first or last name to search:" << endl;
    string searchTerm = " ";
    getline(cin, searchTerm);
    int accountIndex = -1;
    while (containsNumber(searchTerm) || containsSpace(searchTerm)) {
        cout << "Names cannot contain spaces or symbols, please try again" << endl;
        getline(cin, searchTerm);
    }
    acc_list.searchAccountByName(adjustCase(searchTerm));
}




/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    int intInput = 0;
    bool loggedIn = false;

    cout << "Welcome to the Slim Shady and the Beavertown Band Sidescroller!" << endl;
    while (intInput != 4 && loggedIn == false) {
        cout << "Please select an option:" << endl;
        cout << "1) Create a new account" << endl;
        cout << "2) Login to an existing account" << endl;
        cout << "3) Search a user by first or last name" << endl;
        cout << "4) Quit" << endl;

        // recieving numerical input from user
        while (!(cin >> intInput) || intInput < 0 || intInput > 4) {
            clearInput();
            cout << "That was not an option, please try again" << endl;
        }

        clearInput();

        if (intInput == 1) {
            createAccount();
        }

        if (intInput == 2) {
            login();
            loggedIn = true;
        }

        if (intInput == 3) {
            search();
        }

        while (loggedIn) {
            cout << "Please select an option:" << endl;
            cout << "1) Start Game!" << endl;
            cout << "2) Display High Scores" << endl;
            cout << "3) Delete my Account" << endl;
            cout << "4) Logout" << endl;
            while (!(cin >> intInput) || intInput < 1 || intInput > 4) {
                clearInput();
                cout << "That was not an option, please try again" << endl;
            }
            if (intInput == 1) {
                init();

                glutInit(&argc, argv);          // Initialize GLUT

                glutInitDisplayMode(GLUT_RGBA);

                glutInitWindowSize((int)width, (int)height);
                glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/2-(int)width/2, glutGet(GLUT_SCREEN_HEIGHT)/2-(int)height/2); //position the window in the center of the screen
                /* create the window and store the handle to it */
                wd = glutCreateWindow("The Very Possible Game!" /* title */ );

                // Register callback handler for window re-paint event
                glutDisplayFunc(display);

                // Our own OpenGL initialization
                initGL();

                // register keyboard press event processing function
                // works for numbers, letters, spacebar, etc.
                glutKeyboardFunc(kbd);

                glutKeyboardUpFunc(kbdUp);

                // register special event: function keys, arrows, etc.
                glutSpecialFunc(kbdS);

                // handles mouse movement
                glutPassiveMotionFunc(cursor);

                // handles mouse click
                glutMouseFunc(mouse);

                // handles timer
                glutTimerFunc(0, timer, 0);

                // Enter the event-processing loop
                glutMainLoop();
            }
            if (intInput == 2) {
                acc_list.displayHighScores();
            }
            if (intInput == 3) {
                int currentAccountIndex = acc_list.indexFromUsername(current_account);
                acc_list.deleteAccount(currentAccountIndex);
                cout << "Account successfully deleted" << endl;
                loggedIn = false;
            }
            if (intInput == 4) {
                loggedIn = false;
            }
        }

    }
    cout << "Have a nice day!" << endl;

    return 0;
}

#pragma clang diagnostic pop