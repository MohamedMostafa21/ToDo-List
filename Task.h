//
// Created by Gnsh on 5/19/2024.
//
#include<iostream>
#include <string>

#ifndef TODOLIST_TASK_H
#define TODOLIST_TASK_H

using namespace std;

class Task {
public:
    int id; // data
    string taskName; //
    Task* next;
    Task(int id, const string& desc) : id(id), taskName(desc), next(nullptr) {}
};

#endif
