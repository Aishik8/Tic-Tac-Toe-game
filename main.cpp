#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool is_game_over(const vector<int> &scores){    

    //side
    if((int)scores[0]==(int)scores[1] && (int)scores[1] == (int)scores[2]){return true;}
    if((int)scores[3]==(int)scores[4] && (int)scores[5] == (int)scores[2]){return true;}
    if((int)scores[6]==(int)scores[7] && (int)scores[9] == (int)scores[2]){return true;}

    //vertical
    if((int)scores[0]==(int)scores[3] && (int)scores[3] == (int)scores[6]){return true;}
    if((int)scores[1]==(int)scores[4] && (int)scores[4] == (int)scores[7]){return true;}
    if((int)scores[2]==(int)scores[5] && (int)scores[5] == (int)scores[8]){return true;}

    //diagonal
    if((int)scores[0]==(int)scores[5] && (int)scores[5] == (int)scores[7]){return true;}
    if((int)scores[0]==(int)scores[5] && (int)scores[5] == (int)scores[9]){return true;}
}

void display_board(const vector<int> &score){

    for(int i=0;i<=8;i++){
        if(i%3==0){
            cout<<endl<<" | ";
        }
        if(score[i]>10){
            cout<<(char)score[i]<< " | ";
        }
        if(score[i]<10){
            cout<<score[i]<< " | ";
        }

    }
}

int main(){

    bool game_over {false};
    int turn = 1;
    vector<int> scores {1,2,3,4,5,6,7,8,9};

    while(!game_over){

        if(turn==1){
            display_board(scores);
            cout<<endl<< "YOU ARE HAVING X"<<endl;
            cout<<endl<< "Enter your turn" << endl;
            int user_choice ;
            cin>>user_choice;
            if(scores[user_choice-1]<10){scores[user_choice-1] = 120;}
            else{cout<<endl<<"Please Don't Override";continue;}

            if(is_game_over(scores)){
                display_board(scores);
                cout<<endl<<"You Won :)"<<endl;
                game_over = true;
                
            }
            else{
                turn=2;
            }
        }   
        else if(turn==2){

            bool done{false};
            while(!done){
                int computer_choice=rand()%10;
                if(scores[computer_choice]<9){
                    scores[computer_choice]=79;
                    done=true;
                }
            }
            if(is_game_over(scores)){
                display_board(scores);
                cout<<endl<<"You Lost :("<<endl;
                game_over = true;
                
            }
            else{
                turn = 1;
            }           
       }      
    }
    
    cout<<endl<<endl<<"Men are sometimes masters of their own fate!"<<endl;
    system("pause");
}