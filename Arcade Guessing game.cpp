#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Arcade {
public:
    string name;
    int score;
    Arcade(string);
    
};

Arcade::Arcade(string name)
{
   this->name=name;
   score=-1;
}


int main() {
    
    
    int participants;
    cout << "Enter the number of participants? "<<endl;
    cin >> participants;
    
    
    vector<Arcade> players;
    for (int i = 1; i <= participants; i++) {
        string name;
        cout << "Enter name of player " << i << ": ";
        cin >> name;
        players.push_back(Arcade(name));
    }
    

 int randNum= rand() % 100 + 1;
 
 
 
  bool played = false;
    while (!played) {
    for (int i = 0; i < participants; i++) 
    {if (players[i].score <0) 
    {cout << players[i].name << "'s turn." << endl;
     int Num;
    cout << "Enter a number between 1 and 100: ";
    cin >> Num;
    if (Num == randNum)
    { players[i].score = i;
    cout << "Bingo!" << endl;} 
     if (Num < randNum) 
     {cout << "Too low." << endl;} 
     else 
     {cout << "Too high." << endl;}
            }
        }
        
        played = true;
        for (int i = 0; i < participants; i++) 
        {
            if (players[i].score <=0) 
            { played = false;}
        }
        
        if (!played) {
         randNum = rand() % 100 + 1;
        }
    }
        
        
        sort(players.begin(), players.end(), [](const Arcade& gamer1, const Arcade& gamer2) {
        return gamer1.score < gamer2.score;
    });
    
    
    
    cout << endl << "Scores:" << endl;
    for (int i = 0; i < participants; i++) {
        cout << i+1 << ". " << players[i].name << ": ";
        if (players[i].score >=0) {
        cout << "Guessed in " << players[i].score+1 << " tries." << endl; 
        } else {
            cout << "Did not play." << endl;
        }
    }
        
          return 0;
}
        
                
                

