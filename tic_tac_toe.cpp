#include<iostream>
#include<random>
#include<ctime>

using namespace std;

char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

// Show tic tac toe Board
void show_board(){
    cout<<"   " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
    cout<<"-------------------"<<endl;
    cout<<"   " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
    cout<<"-------------------"<<endl;
    cout<<"   " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;
    // cout<<"---------------------"<<endl;
}

//Getting the player X choice
void get_x_player_choice(){

    while(true){
        cout<<"Select Your position(1 - 9): "<<endl;

        int choice;
        cin >> choice;

        choice--;

        if(choice < 0 || choice>8){
            cout << "Please select Your Choice from (1 - 9)." << endl;
        }
        else if(board[choice] != ' '){
            cout << "Please select an Empty Choice." << endl;
        }

        else{
            board[choice] = 'X';
            break;
        }
    }
    
}

//Getting the player O choice
void get_o_player_choice(){

    while(true){
        cout<<"Select Your position(1 - 9): ";

        int choice;
        cin >> choice;

        choice--;

        if(choice < 0 || choice>8){
            cout << "Please select Your Choice from (1 - 9)." << endl;
        }
        else if(board[choice] != ' '){
            cout << "Please select an Empty Choice." << endl;
        }

        else{
            board[choice] = 'O';
            break;
        }
    }

}

//Getting computer choice
void computer_choice(){
    srand(time(0));

    int choice;

    do{
        choice = rand()%10;
    }while(board[choice] != ' ');

    board[choice] = 'O';
}

//count symbol of X and O on the board
int count_board(char symbol){
    int total = 0;
    for(int i=0;i<9;i++){
        if(board[i]==symbol){
            total += 1;
        }
    }

    return total;
}

//cheak winner
char cheak_winner(){
    // cheaking winner in row
    if(board[0]==board[1] && board[1]==board[2] && board[0] != ' '){
        return board[0];
    }
    if(board[3]==board[4] && board[4]==board[5] && board[3] != ' '){
        return board[3];
    }
    if(board[6]==board[7] && board[7]==board[8] &&board[0] != ' '){
        return board[6];
    }

    //cheaking in column
    if(board[0]==board[3] && board[3]==board[6] && board[0] != ' '){
        return board[0];
    }
    if(board[1]==board[4] && board[4]==board[7] && board[1] != ' '){
        return board[1];
    }
    if(board[2]==board[5] && board[5]==board[8] &&board[2] != ' '){
        return board[2];
    }

    //cheaking in daigonals
    if(board[0]==board[4] && board[4]==board[8] && board[0] != ' '){
        return board[0];
    }
    if(board[2]==board[4] && board[4]==board[6] && board[2] != ' '){
        return board[2];
    }

    if(count_board('X') + count_board('O') < 9){
        return 'C';// C for continue
    }
    else{
        return 'D';// D for drop
    }
}

// Computer vs player game
void computer_vs_player(){
    string player_name;
    cout<<"Enter Your Name: ";
    cin >> player_name;

    while(true){
        system("cls");
        show_board();

        if(count_board('X') == count_board('O')){
            cout<<player_name<<"'s Turn." << endl;
            get_x_player_choice();
        }
        else{
            computer_choice();
        }

        char winner = cheak_winner();
        if(winner == 'X'){
            system("cls");
            show_board();
            cout<<player_name<<" Won The Game."<<endl;
            break;
        }
        else if(winner == 'O'){
            system("cls");
            show_board();
            cout<<"Computer Won The Game."<<endl;
            break;
        }
        else if(winner == 'D'){
            cout<<"Game is Draw."<<endl;
            break;
        }
    }
}

// player vs player game
void player_vs_player(){
    string x_player_name,o_player_name;
    cout<<"Enter X Player Name: "<<endl;
    cin>>x_player_name;
    cout<<"Enter O Player Name: "<<endl;
    cin>>o_player_name;

    while(true){
        system("cls");
        show_board();

        if(count_board('X') == count_board('O')){
            cout<<x_player_name<<"'s Turn."<<endl;
            get_x_player_choice();
        }
        else{
            cout<<o_player_name<<"'s Turn."<<endl;
            get_o_player_choice();
        }

        char winner = cheak_winner();
        if(winner == 'X'){
            system("cls");
            show_board();
            cout<<x_player_name<<" Won the game."<<endl;
            break;
        }
        else if(winner == 'O'){
            system("cls");
            show_board();
            cout<<o_player_name<<" Won the game."<<endl;
            break;
        }
        else if(winner == 'D'){
            cout<<"Game is Draw."<<endl;
            break;
        }
    }
}



int main(){

    int mode;
    cout<<endl<<endl;
    cout<<"******************TIC TAC TOE*****************"<<endl;
    cout<<endl<<endl;
    cout<<"Select Game Mode."<<endl;
    cout<<"1. Computer Vs Player."<<endl;
    cout<<"2. Player Vs Player."<<endl;
    cin>>mode;

    switch (mode)
    {
    case 1:
        computer_vs_player();
        break;
    case 2:
        player_vs_player();
        break;
    default:
        break;
    }
    
    return 0;
}