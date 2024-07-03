#include<iostream>
#include <string>
#include "List.h"

using namespace std;

void Menu() {
    cout << "\nTo-Do List Menu:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Delete Task" << endl;
    cout << "3. View Tasks" << endl;
    cout << "4. View How many Tasks" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {

    List toDoList;
    int choice;
    string taskName;

    do {
        Menu();
        cin >> choice;
        cin.ignore();
        cout << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        switch (choice) {
            case 1:
                cout << "Enter The task Name : ";
                getline(cin, taskName);
                toDoList.addTask(taskName);
                break;
            case 2:
                cout << "Enter the task id to be deleted: ";
                int id;
                cin >> id;
                cout << endl;
                toDoList.deleteTask(id);
                break;
            case 3:
                toDoList.viewTasks();
                break;
            case 4:
                toDoList.getSize();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}