#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <ctime>
#include <time.h>
using namespace std;
class TODO
{
    private:
        string Task_State;                            // task Name
        size_t Task_priority;                         // task priority
        size_t Task_ID;                               // task ID
        size_t fordelete;                             //
        char Is_Favorite;                             // favourite or not
        char Is_Finishd;                              // finished or not
    public:
        void SHOW_ALL_TASK(vector<TODO> &);           // for showing entire tasks
        void SHOW_FINISHED_TASK(vector <TODO> &);     // for showing finshed tasks
        void SHOW_UNFINISHED_TASK(vector <TODO> &);   // for showing unfinished task
        void EDIT_TASK(vector <TODO> &);              // for editing a task
        void COMPLETE_TASK(vector <TODO> &);          // for completing unfinshed task
        void ADD_TASK(vector<TODO> & , TODO & T);     // for adding a new task
        void DELETE_TASK(vector <TODO> &);            // for deleting a task
        void ADD_TASK_TOFAVORITE(vector <TODO> &);    // for adding a task to a favourite list
        void SET_TASK(vector <TODO> & , TODO &);      // for seting data into a task
};

//////////////////////////////////////////////
// set task
void TODO::SET_TASK(vector <TODO> & VEC , TODO & T)
{
    string name;
    cout<<"Task name :"<<endl;
    cin.ignore();
    getline(cin,name);
    T.Task_State= name;
    cout<<"Task Priority: (from 1 to 5)"<<endl;
    cin>>T.Task_priority;
    cout<<"Task status:(finshed:y , unfinshed: n)"<<endl;
    cin>>T.Is_Finishd;
    cout<<"Task favority:(favorite:y , not favorite: n)"<<endl;
    cin>>T.Is_Favorite;
    T.fordelete=0;
    srand(time(NULL));
    T.Task_ID = rand() % 8999+1000;
    VEC.push_back(T);
}

//////////////////////////////////////////////
// delete task
void TODO::DELETE_TASK(vector <TODO> & VEC )
{
    
    size_t id;
    char answer;
    if(VEC.size()!=0)
    {
    cout<<"enter Task ID :";
    cin>>id;
    for (int i=0;i<VEC.size(); i++)
    {
        if(id==VEC[i].Task_ID)
        {
            cout<<"Found !"<<VEC[i].Task_State<<endl;
            cout<<"DELETE (y/n):";
            cin>>answer;
            if(answer=='y')
            {
                cout<<"task"<<VEC[i].Task_State<<", deleted."<<endl;
                VEC.erase(VEC.begin()+i);
            }
        }
    }
    }
    else
    {
        cout<<"there is no task"<<endl;
    }

}

///////////////////////////////////////////////
// show finished task
void TODO::SHOW_FINISHED_TASK(vector <TODO> & T) 
{
    int position=0;
    if(T.size()==0)
    {
        cout<<"there is no Task to do"<<endl;
        exit(0);
    }
    else{
        cout<<setw(20)<<"task"<<setw(20)<<"priority"<<setw(20)<<"favorite"<<setw(20)<<"finish"<<endl;
        for (int i=0;i<T.size();i++)
        {
             if(T[i].Is_Finishd=='y')
            {
                cout<<setw(20)<<T[i].Task_State<<setw(20)<<T[i].Task_priority<<setw(20)<<T[i].Is_Favorite<<setw(20)<<T[i].Is_Finishd<<setw(20)<<T[i].Task_ID<<endl;
                position = 1;
            }
        }
        if(position !=1)
            cout<<"there is no finished task"<<endl;
    }
}

////////////////////////////////////////////////
// show all task
void TODO::SHOW_ALL_TASK(vector <TODO> & T)
{
    cout<<setw(20)<<"task"<<setw(10)<<"*"<<setw(10)<<"priority"<<setw(20)<<"favorite"<<setw(20)<<"finish"<<setw(20)<<"ID"<<endl;
    for (int i=0;i<T.size();i++)
    {
        cout<<"*********************************************************************************"<<endl;
        cout<<setw(20)<<T[i].Task_State<<setw(20)<<T[i].Task_priority<<setw(20)<<T[i].Is_Favorite<<setw(20)<<T[i].Is_Finishd<<setw(20)<<T[i].Task_ID<<endl;
    }
}

//////////////////////////////////////////
// add task
void TODO::ADD_TASK(vector <TODO> &Ob , TODO & T)
{
    T.SET_TASK(Ob,T);
}

///////////////////////////////////////////\
// complete task
void TODO::COMPLETE_TASK(vector <TODO> &T)
{
    size_t id;
    char answer;
    int position=0;
    cout<<"Enter Task ID:";
    cin>>id;
    for (int i=0;i<T.size();i++)
    {
        if(id==T[i].Task_ID)
        {
            cout<<"Found!"<<T[i].Task_State<<"."<<endl;
            cout<<"complete(y/n) :";
            cin>>answer;
            if(answer=='y')
                {
                    T[i].Is_Finishd='y';
                    position = 1;
                    cout<<"task"<<"'"<<T[i].Task_State<<"'"<<", completed"<<endl;
                }
            else
            {
                position=0;
            }
            
        }
    }
    if(position != 1)
        cout<<"There is no Task with the Id that you entered or you had not complete the task"<<endl;
}

//////////////////////////////////////////////////////
// show unfinished task
void TODO :: SHOW_UNFINISHED_TASK(vector <TODO> & T)
{
    cout<<setw(20)<<"task"<<setw(10)<<"*"<<setw(10)<<"priority"<<setw(20)<<"favorite"<<setw(20)<<"finish"<<endl;
    for(int i=0;i<T.size();i++)
    {
        if(T[i].Is_Finishd=='n')
        {

            cout<<setw(20)<<T[i].Task_State<<setw(20)<<T[i].Task_priority<<setw(20)<<T[i].Is_Favorite<<setw(20)<<T[i].Is_Finishd<<setw(20)<<T[i].Task_ID<<endl;
        }
    }

}

//////////////////////////////////////////////////////
// Edit Task
void TODO::EDIT_TASK(vector <TODO> & T)
{
    int answer;
    size_t id;
    if(T.size()==0)
        {
            cout<<"At first you should add a task!"<<endl;
        }
    else 
    {
        cout<<"which task you want to edit? enter it's ID"<<endl;
        cout<<">";
        cin>>id;
        for(int i=0;i<T.size();i++)
            {
                if(id==T[i].Task_ID)
                    {
                        cout<<setw(20)<<"task information"<<endl;
                        cout<<setw(20)<<T[i].Task_State<<setw(20)<<T[i].Task_priority<<setw(20)<<T[i].Is_Favorite<<setw(20)<<T[i].Is_Finishd<<endl;
                        cout<<"which part you want to edit?"<<endl;
                        cout<<"1)name"<<endl;
                        cout<<"2)priority"<<endl;
                        cout<<"3)favority"<<endl;
                        cout<<"4)completness"<<endl; 
                        cout<<"5)exit"<<endl;
                        cout<<">";
                        cin>>answer;
                        switch (answer)
                        {
                        case 1:
                            cout<<"enter new name:";
                            cin>>T[i].Task_State;
                            break;
                        case 2:
                            cout<<"enter new priorty number :";
                            cin>>T[i].Task_priority;
                            break;
                        case 3:
                            if(T[i].Is_Favorite=='y')
                                T[i].Is_Favorite='n';
                            else if(T[i].Is_Favorite=='n')
                                T[i].Is_Favorite='y';
                            break;
                        case 4:
                            if(T[i].Is_Finishd=='y')
                                T[i].Is_Finishd='n';
                            else if(T[i].Is_Finishd=='n')
                                T[i].Is_Finishd='y';
                            break;
                        default:
                            continue;
                            break;
                        }
                        cout<<endl;
                        cout<<setw(20)<<"task information after Edit"<<endl;
                        cout<<setw(20)<<T[i].Task_State<<setw(20)<<T[i].Task_priority<<setw(20)<<T[i].Is_Favorite<<setw(20)<<T[i].Is_Finishd<<endl;                       
                        cout<<"Edit operation is successfully Done!!"<<endl;
                    }
            }
    }
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
void menu();
int check_command(string &);

///////////////////////////////////////////////////////
string ADD_Command="add";
string DELETE_COMMAND="delete";
string COMPLETE_Command="complete";
string SHOWALL_Command="list-todo";
string SHOWCOMPLETE_Command="list-complete";
string EDIT_Command="edit";
string EXIT_Command="exit";
//////////////////////////////////////////////////a////////
int main()
{
    vector <TODO> object;
    int int_command;
    char Exit ='y';
    while (Exit == 'y')
    {
        TODO OBJECT;
        menu();
        string Command;
        cin>>Command;
        int_command = check_command(Command);
        switch (int_command)
        {
        case 1: // adding new task
            OBJECT.ADD_TASK(object , OBJECT);
            break;
        case 2: // deleting task
            OBJECT.DELETE_TASK(object);
            break;
        case 3: // completing task
            OBJECT.SHOW_UNFINISHED_TASK(object);
            break;
        case 4: // showing all tasks
            OBJECT.SHOW_ALL_TASK(object);
            break;
        case 5: // showing finished task
                OBJECT.SHOW_FINISHED_TASK(object);
            break;
        case 6: // editing task
            OBJECT.EDIT_TASK(object);
            break;
        case 7: // exit programm
            Exit=1;
            exit(0);
            break;
        default:
            cout<<">WRONG INPUT"<<endl;
            Exit=1;
            break;
        }
        cout<<">try something else?(y/n)"<<endl;
        cin>>Exit;
        
    }
    return 0;
}

void menu()
{
    cout<<"******************************************************************************"<<endl;
    cout<<"MENU"<<endl;
    cout<<"Please enter exactly the same phrase in front of each command in order to perform operation"<<endl;    
    cout<<">ADD TASK (add)"<<endl;
    cout<<">DELETING TASK(delete)"<<endl;
    cout<<">COMPLETING TASK(complete)"<<endl;
    cout<<">SHOWING ALL TASK(list-todo)"<<endl;
    cout<<">SHOWING FINISHED TASK(list-complete)"<<endl;
    cout<<">EDIT (edit)"<<endl;
    cout<<">EXIT PROGRAMM(exit)"<<endl;
}


int check_command(string & str)
{
    if(str==ADD_Command) // add task
        return 1;
        else if(str==DELETE_COMMAND) // delete task
            return 2;
            else if(str==COMPLETE_Command) // complete task
                return 3;
                else if(str==SHOWALL_Command) // show all task
                    return 4;
                    else if(str==SHOWCOMPLETE_Command) // show finished task
                        return 5;
                        else if(str==EDIT_Command)// edit task
                            return 6;
                            else if(str==EXIT_Command)// exit app
                                return 7;
    else
    {
        return -1;
    }               
}