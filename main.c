#include<stdio.h>
#include<stdlib.h>

#define True 1

int board[3][3];

void display_board();
void win_display(int);

void row_check(int);
void col_check(int);
void right_diagonal(int);
void left_diagonal(int);
void draw();

void player_chance(int, int, int);
int check_user_input(int);
int position_check(int, int);

int main(){
    int playerOne = 1, playerTwo = 2, posx, posy, counter=1;
    while(True){
        display_board();
        if(counter%2 == 0){
            //For O Player
            printf("\nO Turn\n");
            printf("Enter The Position(x y):"); scanf("%d%d",&posx,&posy);
            if(check_user_input(posx) && check_user_input(posy)){//checking user Enter A valid number which is between 1 to 3
                if(position_check(posx, posy)){//checking if that position is free
                    player_chance(posx,posy,2);
                }
                else{//if position is not free then this will run
                    system("clear");
                    printf("position Already filled\nChoose Another position\n");
                    continue;
                }
            }
            else{//If entered position is not in between 1 to 3 then this will run
                system("clear");
                printf("Invalid Positions !\nEnter Again\n");
                continue;
            }
            //checking if O wins
            row_check(2);
            col_check(2);
            right_diagonal(2);
            left_diagonal(2);
        }
        else{
            //For X player
            printf("\nX Turn\n");
            printf("Enter The Position(x y):"); scanf("%d%d",&posx,&posy);
            if(check_user_input(posx) && check_user_input(posy)){//checking user Enter A valid number which is between 1 to 3
                if(position_check(posx, posy)){//Checking ifn the position is free
                    player_chance(posx, posy, 1);
                }
                else{//if position is not free this will execute
                    system("clear");
                    printf("position Already filled\nChoose Another position\n");
                    continue;
                }
            }
            else{//if entered position is not in between 1 to 3 this will execute
                system("clear");
                printf("Invalid Positions !\nEnter Again\n");
                continue;
            }
            //Checking if X wins
            row_check(1);
            col_check(1);
            right_diagonal(1);
            left_diagonal(1);        
        }
        counter++;
        draw();
        system("clear");
    }
    return 0;
}

void display_board(){
    //This Display The Tic Tac Toe Screen
    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(board[row][col] == 1) printf(" X ");
            else if(board[row][col] == 2) printf(" O ");
            else printf(" _ ");
        }
        printf("\n");
    }  
    return;
}

void win_display(int user){
    //This Function Display winner name and exit from program
    char winner;
    winner = (user == 1)?'X':'O';
    printf("\n");
    display_board();
    printf("\n");
    printf("%c Wins\n", winner);
    exit(0);
}

void row_check(int user){
    //For checking row
    int counter;
    for(int row=0; row < 3; row++){
        counter = 0;
        for(int col = 0; col < 3; col++){
            if(board[row][col] == user) counter++;
        }
        if(counter > 2) win_display(user);
    }
    return;
}

void col_check(int user){
    //For Checking Column
    int counter;
    for(int row=0; row < 3; row++){
        counter = 0;
        for(int col = 0; col < 3; col++){
            if(board[col][row] == user) counter++;
        }
        if(counter > 2) win_display(user);
    }
    return;
}

void right_diagonal(int user){
    //For checking left Diagonal
    int counter=0;
    for(int row = 0; row < 3; row++){
        if(board[row][row] == user) counter++;
    }
    if(counter > 2) win_display(user);
    else return;
}

void left_diagonal(int user){
    //For Checking right diagonal
    int counter = 0;
    for(int index = 0; index < 3; index++){
        if(board[2-index][index] == user) counter++;
    }
    if(counter > 2) win_display(user);
    else return;
}

int check_user_input(int pos){
    //To see if user has entred valid number
    if(pos > 0 && pos < 4) return 1;
    else return 0;
}

void draw(){
    //To check if game has drawn
    int counter = 0;
    for(int row =0 ; row < 3; row++){
        for(int col = 0; col < 3; col++){
            if(board[row][col] == 0) counter++;
        }
    }
    if(counter == 0){
        system("clear");
        printf("\n");
        display_board();
        printf("\nDraw\n");
        exit(0);
    }
    else{
        return;
    }
}

void player_chance(int row, int col, int user){
    //To insert in the board
    if(board[row-1][col-1] == 0){
        board[row-1][col-1] = user;
        return;
    }
    return;
}

int position_check(int row, int col){
    //to check whether the position is free or not
    if(board[row-1][col-1] == 0) return 1;
    else return 0;
}