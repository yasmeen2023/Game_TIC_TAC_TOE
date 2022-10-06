#include <iostream>

using namespace std;
//global variables
char matrix[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char player='x';
//function to show structure of game
void show_structure_of_game();
//function to ask for player to enter position and replace it by x or o
void replace_element();
//function to check who win
char WhoWin();
int main()
{
    while(WhoWin()=='S'){
      show_structure_of_game();
      replace_element();
    }
    cout<<endl;
    if(WhoWin()=='E'){
        cout<<"NO Winner"<<endl;
    }
    else{
        cout<<"the Winner is player<< "<<WhoWin()<<" >>  congratulation !!!"<<endl;
    }
    return 0;
}

//function to show structure of game
void show_structure_of_game(){
    cout<<endl;
    for(int i=0; i<3; i++){
            cout<<"\t\t";
        for(int j=0; j<3; j++){
            cout<<matrix[i][j]<<" | ";
        }
      cout<<endl;
      cout<<"\t\t";
      cout<<"--- --- ---"<<endl;
    }
}
void replace_element(){
    char *position=new char;
    cout<<"choose your position _ player<<"<< player <<">> ";
    cin>>position;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j]==*position){
                matrix[i][j]=player;
            }
        }
    }
    if(player=='x'){
        player='o';
    }
    else{
        player='x';
    }
}
char WhoWin(){
    int X_counter=0,O_counter=0,counter=0;

    //nested for loop to count x and o to know who win(for loop on rows)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j]=='x'){
                X_counter++;
            }
            else if(matrix[i][j]=='o'){
                O_counter++;
            }
            if(X_counter==3 || O_counter==3){
                return X_counter> O_counter? 'x' : 'o';
            }
        }
        X_counter=0;
        O_counter=0;
    }
    //nested for loop to count x and o to know who win(for loop on columns)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[j][i]=='x'){
                X_counter++;
            }
            else if(matrix[j][i]=='o'){
                O_counter++;
            }
            if(X_counter==3 || O_counter==3){
                return X_counter> O_counter? 'x' : 'o';
            }
        }
        X_counter=0;
        O_counter=0;
    }

    //check of diagonal
    if(matrix[0][0]=='x' && matrix[1][1]=='x' && matrix[2][2]=='x'){
        return 'x';
    }
    else if(matrix[0][0]=='o' && matrix[1][1]=='o' && matrix[2][2]=='o'){
        return 'o';
    }
    else if(matrix[0][2]=='x' && matrix[1][1]=='x' && matrix[2][0]=='x'){
        return 'x';
    }
    else if(matrix[0][2]=='o' && matrix[1][1]=='o' && matrix[2][0]=='o'){
        return 'o';
    }

    //for loop to check if there is number to replace it by (x or o) or not
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(matrix[i][j]!='x' && matrix[i][j]!='o'){
                counter++;
            }
            else{
                continue;
            }
        }
    }
    if(counter==0){
        return 'E'; //this mean that matrix not have any number to replace it by(x or o) and no one win
    }
    return 'S'; //this mean that game is going on
}
