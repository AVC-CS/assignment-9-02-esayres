#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const int N = 5;
struct Student
{
    int id;
    string name;
    string major;
    Student *next;
};

Student *makeStudent();
void printStudent(Student *head);

Student *makeStudent(){
    Student *head, *tmp, *prev;
    ifstream file;
    file.open("students.txt");
    if(!file){
        cerr << "FILE FAILED TO OPEN" << endl;
        exit(0);
    }

    //prev = tmp;
    for(int i = 0; i < N; i++){
        tmp = (Student *)malloc(sizeof(Student));
        file >> tmp->id >> tmp->name >> tmp->major;
        tmp->next = NULL;
        if(i == 0){
            head = tmp;
        } else{
            prev->next = tmp;
        }
        prev = tmp;
    }
    return head;
}
void printStudent(Student *head)
{
    for(int i = 0; i < 5; i++){
        cout << head->id << " " << head->name << " " << head->major << endl;
        head = head->next;
    }
}