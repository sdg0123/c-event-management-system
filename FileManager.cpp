#include <iostream>
#include <fstream>
#include "FileManager.h"

using namespace std;

void FileManager::save()
{
    ofstream file("data.txt");
    file<<"Data Saved";
    file.close();
}

void FileManager::load()
{
    ifstream file("data.txt");
    if(file)
    cout<<"Previous Data Loaded"<<endl;
}