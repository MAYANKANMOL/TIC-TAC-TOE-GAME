#include <bits/stdc++.h>
#include <time.h> 
using namespace std;
bool check(vector<vector<char>>& grid, int row, int col){
    int c = grid[row][col];
    if(grid[0][col]==c && grid[1][col]==c && grid[2][col]==c){
        return true;
    }
    if(grid[row][0]==c && grid[row][1]==c && grid[row][2]==c){
        return true;
    }
    if(row==col && grid[0][0]==c && grid[1][1]==c && grid[2][2]==c){
        return true;
    }
    if(row+col==2 && grid[2][0]==c && grid[0][2]==c && grid[1][1]==c){
        return true;
    }
    return false;
}
void displaygrid(vector<vector<char>>& grid){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<grid[i][j]<<" ";
            if(j==0||j==1){
                cout<<"|"<<" ";
            }
        }
        cout<<endl;
        if(i==0||i==1){
            cout<<"----------"<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<char>> grid(3, vector<char>(3, ' '));
    displaygrid(grid);
    string player1, player2;
    cout<<"enter the 1st player name "<<" "<<endl;
    cin>>player1;
    cout<<"enter the 2nd player name "<<" "<<endl;
    cin>>player2;
    char c1, c2;
    srand(time(NULL));
    int temp = rand()%2;
    if(temp==0){
        cout<<player1<<" choose 0 or X ";
        cin>>c1;
        if(c1=='0'){
            c2 = 'X';
        }else{
            c2 = '0';
        }
    }else{
        cout<<player2<<" choose 0 or X ";
        cin>>c2;
        if(c2=='0'){
            c1 = 'X';
        }else{
            c1 = '0';
        }
    }
    int count = 0, playerswitch = temp, row, col, won=0;
    while(count<9){
        if(playerswitch == 1){
            cout<<player1<<" "<<"enter the box location"<<endl;
            do{
                int location;
                cin>>location;
                location=location-1;
                row=location/3;
                col=location%3;
                while(row<0 || row>2 || col<0 || col>2){
                    cout<<"This location is INVALID"<<endl;
                    cin>>location;
                    location=location-1;
                    row=location/3;
                    col=location%3;
                }
                if(grid[row][col]!=' '){
                    cout<<"This box is already used."<<endl;
                }
            }while(grid[row][col]!=' ');
            grid[row][col] = c1;
            count++;
        }else{
            cout<<player2<<" "<<"enter the box location"<<endl;
            do{
                int location;
                cin>>location;
                location=location-1;
                row=location/3;
                col=location%3;
                while(row<0 || row>2 || col<0 || col>2){
                    cout<<"This location is INVALID"<<endl;
                    cin>>location;
                    location=location-1;
                    row=location/3;
                    col=location%3;
                }
                if(grid[row][col]!=' '){
                    cout<<"This box is already used."<<endl;
                }
            }while(grid[row][col]!=' ');
            grid[row][col] = c2;
            count++;
        }
        displaygrid(grid);
        if(count>=5){
            if(check(grid, row, col)){
                if(playerswitch == 1){
                    cout<<player1<<" WON!"<<endl;
                    won=1;
                    break;
                }else{
                    cout<<player2<<" WON!"<<endl;
                    won=1;
                    break;
                }
            }
        }
        playerswitch=!playerswitch;
    }
    if(!won){
        cout<<"DRAW!"<<endl;
    }
}