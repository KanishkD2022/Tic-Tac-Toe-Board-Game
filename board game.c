#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

char board[3][3];
const char PLAYER = 'X';   /*setting the Player as X*/  /*capital letters used due to "const" func*/
const char COMPUTER = 'O';  /*setting computer as O*/
/*these are function prototypes - we tend to declare them before the main function*/
void resetBoard();  /*board is going to be a 2D character array*/
void printBoard();  /*prints our 2D character array*/
int checkFreeSpaces();   /*return type of int*/  /*if after invoking this function & this function returns 0 that means the game is over; there are no more places to move*/
void playerMove();  /*when its the players turn to move*/
void computerMove();  /*when its the computers turn to move*/
char checkWinner();  /*few different win conditions to check*/
void printWinner(char);  /*as there is one parameter a single character as "char"*/

int main()
{
    char winner = ' '; /*set winner as empty space; if the winner is an empty space that means there currently is no winner; if player wins thats X; if comp. wins thats O*/

    resetBoard();

    while(winner == ' ' && checkFreeSpaces() != 0)  /*empty space means there is currently no winner*/
    {
        printBoard();

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)   /*to check if the game is over*/
        {
            break;
        }

        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);

    return 0;
}

void resetBoard()  /*we need forloops here to characterize the 2D arrays*/
{
    for(int i=0;i<3;i++)  /*outer for loop for rows; inner for loops for columns*/
    {
        for(int j=0;j<3;j++)
        {
            board[i][j] = ' ';  /*setting the sequel to an empty space*/
        }                      /*when we call this "resetBoard" func. each element within this 2D array of characters will be an empty space*/
    }
}
void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);   /*these 3 format specifiers are place holders*/
    printf("\n---|---|---\n");                                         /*written as board[row=0][col=0]*/
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces()
{
    int freeSpaces = 9;  /*initially set up to 9*/

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] != ' ')   /*checking to see if our 2D array of characters of board does not equal an empty space*/
            {
                freeSpaces--;  /*if whatever spot we are on is currently occupied; we decrement the "freespace" variable*/
            }
        }
    }
    return freeSpaces;   /*if we return 0 that means the game is 0; their is no more spaces a player can move*/
}
void playerMove()
{
    int x;    /*declaring 2 local variables*/
    int y;

    do
    {
        printf("Enter row #(1-3): ");  /*ask user to enter a row no. & col. no. where they would like to move to*/
        scanf("%d",&x);
        x--;     /*decrement x by 1 as for arrays, 1 is denoted as 0*/
        printf("Enter column #(1-3): ");
        scanf("%d",&y);
        y--;

        if(board[x][y] != ' ')     /*that means that this spot is currently occupied by another character*/
        {
            printf("Invalid Move!\n");
        }
        else          /*that spot is open*/
        {
            board[x][y] = PLAYER;
            break;    /*"break" to exit while loop*/
        }
    } while (board[x][y] != ' ');   /*if spot is currently occupied then we will ask them again to enter some cordinates*/

}
void computerMove()
{
    /*create a seed based on current time*/
    srand(time(0));    /*creating a seed to generate random numbers; invoke "srand" function*/
    int x;
    int y;
                      /*we will generate 2 random numbers between 0 & 2; but first lets check if free spaces are available or not*/
    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;   /*generate 2 random no.s b/w 0 & 2*/
            y = rand() % 3;
        } while (board[x][y] != ' ');  /*so we will keep on generating random no.s until there is an open space & then escape the while loop*/

        board[x][y] = COMPUTER;
    }
    else    /*if there are no more spaces available*/
    {
        printWinner(' ');   /*this means there is no winner, its a draw*/
    }
}
char checkWinner()  /*we need to check all of the different win conditions*/
{
    /*check rows*/
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])  /*checking each set of horizontal elements*/
        {
            return board[i][0];  /*if all conditions are equal then board[i][0] is the winner*/
        }
    }
    /*check columns*/   /*win conditions checking*/
    for(int i=0;i<3;i++)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    /*check diagonals*/      /*win conditions checking*/
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0])   /*[0][2] is the bottom left; [1][1] is the middle*/
    {
        return board[0][2];
    }
                        /*if after checking all these win conditions their is no winner; then we return an empty character*/
    return ' ';    /*empty character resembles their currently is no winner*/
}
void printWinner(char winner)  /*parameter is char winner*/
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else{
        printf("IT'S A TIE!");
    }
}
