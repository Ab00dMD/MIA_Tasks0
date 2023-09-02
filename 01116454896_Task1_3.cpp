#include<iostream>
#include <time.h>
#include <conio.h>
#include <limits>
#include<cmath>
#include <stdlib.h>
using namespace std;
const int N = 1000;
string tasks[N];
bool complete[N];
int added;
void stopSpoilers(int &x);
void delay(int);
bool outBounds(int);
void nOne(int);
void goBack();
void addTask();
void removeTask();
void viewTasks();
void markAsComplete();
void exit();
void op();
void showMenu();
int main()
{
    showMenu();

    return 0;
}

void stopSpoilers(int &x){
    if (!(cin >> x)) { //to handle if the user input a string
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goBack();
    }
}
void delay(int sec){
    int ms = 1000 * sec;
    clock_t st = clock();
    while(clock() < st + ms);
}
bool outBounds(int idx){
    if(idx>added || idx<1) {
        cout << "!!OUT OF BOUNDS!!\n";
        delay(1);
        return true;
    }
    return false;
}
void nOne(int idx){
    if(idx==-1) showMenu();;
}
void goBack(){
    delay(1);
    showMenu();
}
void addTask(){
    string description;
    cout<<"Enter task description: ";
    getline(cin>>ws,description);
    if (added < N) {
        tasks[added]=description;
        complete[added]=false;
        added++;
        cout << "Task added successfully!\n";
    }
    else {
        cout << "Task limit reached. Unable to add more tasks.\n";
    }
    goBack();
}
void removeTask(){
    int idx;
    cout<<"Enter -1 to main menu\nEnter task ID to remove: ";
    stopSpoilers(idx);
    nOne(idx);
    if(outBounds(idx)) removeTask();
    for(int i=idx;i<added;i++){
        tasks[i-1]=tasks[i];
        complete[i-1]=complete[i];
    }
    added--;
    cout<<"Task removed successfully!\n";
    goBack();
}
void viewTasks(){
    cout<<"ID  | Status |  Description\n";
    for(int i=0;i<added;i++)
        cout<<i+1<<string(3-(int)log10(i+1),' ')<<"|    "<<(complete[i]? 'C': ' ')<<"   |  "<<tasks[i]<<'\n';
}
void markAsComplete(){
    int idx;
    cout<<"Enter -1 to main menu\nEnter task ID to mark as complete: ";
    stopSpoilers(idx);
    nOne(idx);
    if(outBounds(idx)) markAsComplete();
    complete[idx-1]=true;
    cout<<"Task marked as complete successfully!\n";
    goBack();
}
void exit(){
    cout<<"Exiting Minions Task Manager. Have a great day!";
    exit(0);
}
void showMenu(){
    system("CLS");
    cout<<"Minions Task Manager\n"
        <<"1. Add Task\n"
        <<"2. View Tasks\n"
        <<"3. Remove Task\n"
        <<"4. Mark Task as complete\n"
        <<"5. Exit\n"
        <<"select an option: ";
        op();

}
void op(){
    int x;
    stopSpoilers(x);
    switch(x){
    case 1:
        addTask();
        break;
    case 2:
        viewTasks();
        cout<<"For main menu press any key...";
        if(getch()) showMenu();
        break;
    case 3:
        viewTasks();
        removeTask();
        break;
    case 4:
        viewTasks();
        markAsComplete();
        break;
    case 5:
        exit();
        break;
    default:
        cout << "Invalid input\n";
        goBack();
    }
}
