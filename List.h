//
// Created by Gnsh on 5/19/2024.
//

#include<iostream>
#include <string>

using namespace std;

#ifndef TODOLIST_LIST_H
#define TODOLIST_LIST_H

#include "Task.h"
class List {
private:
    Task* head;
    int nextId;
    int Size;

public:
    List() : head(nullptr), nextId(1) , Size(0) {}

    ~List() {
        Task* current = head;
        while (current != nullptr) {
            Task* next = current->next;
            delete current;
            current = next;
        }
    }

    void addTask(const string& taskName) {
        Task* newTask = new Task(nextId++, taskName);
        newTask->next = head;
        head = newTask;
        Size++;
        cout << "Task added:  Id [" << newTask->id << "], " << taskName << endl;
    }

    void deleteTask(int id) {
        Task* current = head;
        Task* previous = nullptr;
        while (current != nullptr && current->id != id) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "There is no task with ID: " << id << endl;
            return;
        }

        Size--;
        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        cout << "Task of Id [" << id << "] was deleted" << endl;
        delete current;
    }

    void viewTasks() const {
        Task* current = head;
        if (current == nullptr) {
            cout << "No tasks to display." << endl;
            return ;
        }
        cout << "Task List : "<<endl;
        while (current != nullptr) {
            cout << "[" << current->id << "] " << current->taskName << endl;
            current = current->next;
        }
    }
    void getSize()
    {
        cout << "Number of Tasks: " <<  Size << endl;
    }
};

#endif //TODOLIST_LIST_H
