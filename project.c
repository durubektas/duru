#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>

void gotoxY(int x, int y); //The function which leads to the coordinates of x and y
void gamePlay() ; //The function that plays the game
void creatingFile(); //The function of creating a file to save values of wanted variables
void readingFile(); //The function of reading values of structure from a file to load a saved game
void randomWord(); //The function that give random words from text file

//Initializing integers
    clock_t t1, t2; //for me to see the execution time of the game each time
    double score_t; //variable where i see the execution time of each printing of game
    int score=0; //current score which will not be printed
    int score_board=0; //score which will be printed to screen
    char word[50]; //the word string of bomb
    int y=0; //place of bomb in y axis
    int x=0; //place of bomb in x axis
    unsigned int delay=200; //The delay time of clearing screen
    unsigned int word_length=3; //word length of words
    unsigned int word_count=2; //counts the number of words
    int i=0; //place of plane in x axis
    int firstini=1; //first initialize, to understand if menu screen is shown first or by Esc
    char line[50]; //string which randomWord() function will determine

//The main function is directly the menu of the game
int main () {

   int count=1; //count is given for the menu to be opened again and again in certain acts

    while (count<=5) {

    system("cls"); //cleans the screen

    //Menu is printed to the screen:
    gotoxY(1,1);
    printf("1. New Game:");

    gotoxY(1,2);
    printf("2. Load a Saved Game:");

    gotoxY(1,3);
    printf("3. Save Current Game:");

    if (firstini==0) { //to know if menu is opened by Esc or not
    gotoxY(1,4);
    printf("4. Return to Game:");
    }

    gotoxY(1,5);
    printf("5. Exit:");

    int menu_;
    gotoxY(1,6);
    scanf("%d", &menu_); //Reads the number given and gives that value to menu_ integer

    //According to the value of menu_, the cases are done
    switch (menu_) {
    case 1:
        //Initializing the values
        score=0;
        score_board=0;
        y=0;
        x=0;
        delay=200;
        word_length=3;
        word_count=2;
        i=0;

        //randomWord function is called to generate a random word
        randomWord();

        //line string is equalized to word string
        strcpy(word, line);

        //gamePlay function is called so game starts
        gamePlay();
        break;

    case 2:
        //readingFile function called to read the saved game variables
        readingFile();

        //randomWord function called, with the length of previous word is generated
        randomWord();
        strcpy(word, line);

        //gamePlay function is called so game starts with the variables read
        gamePlay();
        break;

     case 3:
        //creatingFile function is called to save the current state of game
        creatingFile();
        break;

     case 4:
         if (firstini==1) {break;} //If menu is not opened by Esc
        //Otherwise, the game continues by calling gamePlay
        gamePlay();
        break;

     case 5:
        //Game is closed
        printf("Game is closed successfully!");
        return 0;
    }
    }

}

//gamePlay function plays the game
void gamePlay( ) {

    firstini=0; //makes it 0 to understand if Esc is pressed during game

    //to keep the game play from start if at the end the player presses 'y'
    int gameplayi=1;
    while (gameplayi<=3) {

    //for loop keeps plane moving from left to right
  for (i; i<58; i++) {

        //Following 3 lines calculate the execution time of game, for me to see
        t2 = t1;
        t1 = clock();
        score_t = t1-t2;

    if (i==57) { i=0; }
    //Printing the city to the screen
    gotoxY(0,22);
    printf("  _____        _____   _________________ ________     _________\n |o o o|_______|    |__|               | | # # # |____|o o o o|\n |o o o|* * *|: ::|. . |               |o| # # # |. . |o o o o|\n |o o o|* * *|::  |. . | []  []  []  []|o| # # # |. . |o o o o|\n |o o o|**** |:  :| . .| []  []  []    |o| # # # |. . |o o o o|\n |_[]__|__[]_|_||_|__< |____________;;_|_|___[]__|_.|_|__[]___| ");

    //The scoreboard
    gotoxY(65,1);
    printf("Score: %d ", score);

    /* This part shows me the current score, execution time, word count and word length on the screen for me to check

    gotoxY(65,2);
    printf("Score: %d ", score);

    gotoxY(65,3);
    printf("time: %f", score_t);

    gotoxY(55,4);
    printf("wordcount: %d", word_count);

    gotoxY(55,5);
    printf("wordlength: %d", word_length);

    gotoxY(55,6);
    printf("delay: %d", delay);
    */

    //Position of plane
    gotoxY(i,1);
    printf("(|__.-. |");
    gotoxY(i,2);
    printf("== ===_]+");
    gotoxY(i,3);
    printf("        |");

    //Position of bomb is also using the same speed unit with plane but 3 times slower because it is moving in y axis
    if (i%3==0) { y+=1; }
    //If the bomb reaches city, game is lost
    if (y>=18) { break; }

    //Position of bomb
    gotoxY(x, y + 3);
    printf("<|>");
    gotoxY(x, y + 4);
    printf(" |");
    gotoxY(x, y + 5);
    printf(" *");

    //Shows the word of bomb
    gotoxY(x+3, y + 4);
    printf("%s", word);

    //The function that reads the keyboard without waiting
   while (_kbhit()) {
        char key = _getch();

        //If Esc key is pressed
        if( (int)key == 27) { return 0;}

        //If the player presses the right letter
        if (key == word[0]){

        //word's first letter is gone
        for(int ii = 0; ; ii++)
        {
        word[ii] = word[ii+1];
        if(word[ii] == '\0')
		break;
        }
                score+=1; //current score increases by 1
        }
        //If the letter is mistyped, current score is decreased by 1
        else { score-=1; }
        }

        //Shows this printed screen for "delay" miliseconds
   Sleep(delay);
        //Then cleans the screen for new positioning
    system("cls");


        //If the word is completely correctly written
       if (word[1]=='\0') {
            score_board=score; //the score which will be seen is screen is equalized to current score

            //new random word is generated and equalized
            randomWord();
            strcpy(word, line);

            //The new bombs position
            x=i;
            y=0;

            //Word count is increased
            word_count+=1;
            //If 5 words of same length is written
            if (word_count==6) {
                word_count=1; //count returns to 1
               //until length of 10 is found
                if (word_length != 10 ) {
                word_length+=1; //word length is increased
                delay-=27; } //the games's speed increases by delay decreasing 27 miliseconds
             }
       }
    }

    system("cls"); //cleaning screen for game over

    //GAME OVER printed to the middle of the screen
    gotoxY(40, 10);
    printf("GAME OVER\n");
    //Player is asked to press y or n

    printf("%d", score_board);

    gotoxY(40, 12);
    printf("Press y to restart the game, n to go to the menu\n");

    //Initializing the values for a possible new game to be started by player pressing y
        score=0;
        score_board=0;
        y=0;
        x=0;
        delay=200;
        word_length=3;
        word_count=2;
        i=0;

        randomWord();
        strcpy(word, line);

        //String yorn is y or n, which will be scanned from the players keyboard
    char yorn[50];

    gotoxY(40,13);
    scanf("%s", &yorn);

    Sleep(1000);

    //If n is pressed, the gamePlay returns 0 and menu is opened
    if (yorn[0]=='n') { return 0;}

    else if (yorn[0]!= 'y') {
        //If a character other than y or n is pressed, the menu opens
        printf("Incorrect letter is typed, going to menu!");
        Sleep(2000);
        return 0;
    } //If y is typed, if statements does not work and gamePlay function starts again
}
}

//Function of creating a file to save values of wanted variables
void creatingFile() {

     //A structure is created with structure variables of variables needed to load saved game
     struct variablesstruct
    {
    int score_s;
    int score_board_s;
    int y_s;
    int x_s;
    unsigned int delay_s;
    unsigned int word_length_s;
    unsigned int word_count_s;
    int i_s;
    };

     FILE *outfile; //file pointer

     //string of the files name
     char fname[50];

     //Player enters a file name
    printf("Enter a name to the file where your game status will be saved: ");
    scanf("%s", &fname);

    //outfile is written with name fname
    outfile = fopen (fname, "w");

    //If there is a problem with file
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    //Structure variable are equalized to the latest values of those variables
    struct variablesstruct input = { score, score_board, y, x, delay, word_length, word_count, i };

    //Writing structure to file
    fwrite (&input, sizeof(struct variablesstruct), 1, outfile);

    //If the contents to file are written successfully or not
    if(fwrite != 0) {
        printf("Contents to file written successfully !\n");
        Sleep(2000); }
    else {
        printf("Error writing file !\n");
         Sleep(2000); }

    //Close file
    fclose (outfile);

    return 0;

}

//Function of reading values of structure from a file to load a saved game
void readingFile() {

    //Same structure inside createFile function
    struct variablesstruct
    {
    int score_s;
    int score_board_s;
    int y_s;
    int x_s;
    unsigned int delay_s;
    unsigned int word_length_s;
    unsigned int word_count_s;
    int i_s;
    };

    //Pointer to open the file
    FILE *infile;
    struct variablesstruct input;

    char fname[50];

    //Player is asked to write the name of saved game
    printf("Enter the name of the file you want to load game from: ");
    scanf("%s", &fname);

    // Open fname for reading
    infile = fopen (fname, "r");

    //If there is a problem opening the file
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    //Read file contents till end of file
    while(fread(&input, sizeof(struct variablesstruct), 1, infile))

        /* For me to see the outcome of values
        printf ("%d %d %d %d %d %d %d %d\n", input.score_s,
        input.score_board_s, input.y_s, input.x_s, input.delay_s, input.word_length_s, input.word_count_s, input.i_s);
        */

        //Equalizing the values of structure variables to the game variables
        score= input.score_s;
        score_board= input.score_board_s;
        y= input.y_s,
        x= input.x_s;
        delay= input.delay_s;
        word_length= input.word_length_s;
        word_count= input.word_count_s;
        i= input.i_s;

        /* For me to see the values of game variables
        printf( "%d %d %d %d %d %d %d %d\n ", score, score_board, y, x, delay, word_length, word_count, i);
        */

    //Close file
    fclose (infile);

    return 0;
}

//Function that comes up with a random word
void randomWord() {

    //Random line finder by word length, it finds lines because the text file I use is in increasing order of word letter lengths
    //Generates a random number between 0 and 4
    srand(time(0));
    int r = rand()% 5;

    //Because line number of every same length words are 5, the formula is decrease the wordlength by 3, times 5 and plus the random integer generated
    int lineNumber = (word_length - 3)*5 + r;

    //The specific line of text file of words is read
    static const char filename[] = "codewords.txt";
    FILE *file = fopen(filename, "r"); //Reads file
    //Initializing a variable named count to look for lines until the word is found
    int count = 0;
    if ( file != NULL )
    {
        //Loops until count is equal to line number we generated by random
        while (fgets(line, sizeof line, file) != NULL)
        {
            if (count == lineNumber)
            {
                break;
            }
            else
            {
                count++;
            }
    }
    //Close file
    fclose(file);
}
}

//The function which goes to the coordinates of x and y in those axis's
void gotoxY(int x, int y){
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD); //This is a ready to use function to move the cursor
}
