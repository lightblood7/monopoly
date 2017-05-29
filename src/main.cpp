/********************************************************************************
 main.cpp : Defines the entry point for the console application.
 The program runs here, from here the user can select to play, view records of current game and
 if need be, delete records.
********************************************************************************/
#include "MonopolyHeader.h"
#include "game.h"

//prototypes of functions and procedures in the main
int choiceGameMenu();
int choiceRecordsMenu();

//main
int main()
{
    int choice;
    bool progEnd = false;
    //create a object of game
    game* g = new game;
    cout <<"monopoly"<<endl;
    //defining boardState, used to record data
    boardState bs;
    //loop until user chooses the option to end the program
    while (progEnd == false)
    {
        system("cls");

        //check if a game is on currently and output correct info to user
        if (bs.getSize()==0)
        {
            cout <<"No game on currently"<<endl;
        }
        else if(bs.gameEnded == false)
        {
            cout<<"game of "<<bs.getSize()+1<<" turns is currently active"<<endl;
        }
        else
        {
            cout<<"game is finished, delete game record to start a new game"<<endl;
        }
        //displaying info and getting options
        choice = choiceGameMenu();
        cin.ignore();
        switch (choice)
        {
        //menu options
        case 1:
        {
            //resume game/ play game
            system("cls");
            if(bs.gameEnded == false)
            {
                bs = g->gameStart(bs);
            }
            else
            {
                cout<<"game is finished, cant resume"<<endl;
                if(!cin)
                {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                system("pause");
            }
            break;

        }
        case 2:
        {
            // if a game been recorded, go to records menu
            if(bs.getSize()!=0)
            {
                system("cls");
                choice = choiceRecordsMenu();
                cin.ignore();
                //records menu choices
                switch(choice)
                {
                case 1:
                {
                    //display every turns info
                    system("cls");
                    bs.displayAllStates();
                    break;
                }
                case 2:
                {
                    //display a selected turn info
                    system("cls");
                    cout <<"please enter a turn to view (total turns = "<<bs.getSize()<<" )"<<endl;
                    cout <<"--------------------------------------------------------------------"<<endl;
                    cout<<"selection: ";
                    cin>>choice;
                    while(cin.fail())
                    {
                        cout << "invalid value" << endl;
                        cout << "try Again: "<<endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        cin >> choice;
                    }
                    cin.ignore();
                    system("cls");
                    bs.displayState(choice);
                    break;
                }

                }
                //error message displayed if no game is currently active
            }
            else
            {
                cout <<"no game records to view, make sure a game has been played first"<<endl;
                if(!cin)
                {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                }
                system("pause");
            }
            break;

            //delete current game, allowing for a new game to be played
        }
        case 3:
        {
            cout <<"game data deleted"<<endl;
            delete g;
            bs.deleteGameData();
            if(!cin)
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
            system("pause");
            bs.gameEnded = false;
            game* g = new game;
            break;

        }
        case 4:
        {
            //ending program
            progEnd = true;
            break;
        }
        }
    }
    return 0;
}

//game menu - display and get option
int choiceGameMenu()
{
    int choice;
    cout <<endl<<"do you want to do?"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"1: start game /continue game"<<endl;
    cout<<"2: view previous game Records"<<endl;
    cout<<"3: delete game data"<<endl;
    cout<<"4: exit program"<<endl;
    cout<<"selection: ";
    cin>>choice;
    while(cin.fail())
    {
        cout << "invalid value" << endl;
        cout << "try Again: "<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choice;
    }
    return choice;
}

//record menu - display and get option
int choiceRecordsMenu()
{
    int choice;
    cout <<endl<<"do you want to do?"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"1: view all"<<endl;
    cout<<"2: view specific turn"<<endl;
    cout<<"3: leave records"<<endl;
    cout<<"selection: ";
    cin>>choice;
    while(cin.fail())
    {
        cout << "invalid value" << endl;
        cout << "try Again: "<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choice;
    }
    return choice;
}



