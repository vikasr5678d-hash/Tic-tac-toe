#include <iostream>
using namespace std;
void displayboard(char board[]){
    cout<<"\n";
    cout<<" "<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<"\n";
    cout<<"---+---+---\n";
     cout<<" "<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<"\n";
    cout<<"---+---+---\n";
     cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<"\n"; 
}

bool checkwin(char board[],char player){
    if(board[0]==player && board[1]==player && board[2]==player){
        return true;
    }
    if(board[3]==player && board[4]==player && board[5]==player){
        return true;
    }
    if(board[6]==player && board[7]==player && board[8]==player){
        return true;
    }

    if(board[0]==player && board[3]==player && board[6]==player){
        return true;
    }
    if(board[1]==player && board[4]==player && board[7]==player){
        return true;
    }
    if(board[2]==player && board[5]==player && board[8]==player){
        return true;
    }

    if(board[0]==player && board[4]==player && board[8]==player){
        return true;
    }
    if(board[2]==player && board[4]==player && board[6]==player){
        return true;
    }
        return false;
}
int main(){
    char board[9]={'1','2','3','4','5','6','7','8','9'};
    char player='X';
    int position;
    int moves=0;
    for(;;){
        displayboard(board);
        cout<<"\nplayer:"<<player<<"\nEnter position:";
        cin>>position;
        if(position<1 || position>9){
            cout<<"\ninvalid position!,try again";
            continue;
        }
        if(board[position-1]=='X' || board[position-1]=='O'){
            cout<<"\nposition is alredy acccupied!,try again";
            continue;
        }
        board[position-1]=player;
        moves++;
        if(checkwin(board,player)){
        displayboard(board);
        cout<<"\nplayer:"<<player<<" wins";
        break;
        }

         if(moves==9){
        displayboard(board);
        cout<<"\nits draw";
        break;
    }
   
    
    if(player=='X'){
        player='O';
    }
    else{
        player='X';
    }
}
    return 0;
}