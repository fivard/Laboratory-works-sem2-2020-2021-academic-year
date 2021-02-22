//
// Created by Admin on 04.02.2020.
//

#ifndef LABOR1_FUNCTIONS_H
#define LABOR1_FUNCTIONS_H

#include <vector>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

struct benchData{
    double timeGeneratingAndSaving;
    double timeReading;
    double timeSearching;
    double memoryOfData;

};

class FullTime{
public:
    short year;
    short month;
    short day;
    short hour;
    short minutes;
    short sec;

    bool moreThen(FullTime) const;
    void setCurrentTime(int delta = 0);
};

class MessageLog;

class Message{
    int id;
    int countWords;
    string text;
    FullTime timeCreated;
    string typeOfError;
    int priority;
    double loading;
    bool savedInFiles;

public:
    int toCountWords(const string& s);
    void outElem();

    friend MessageLog;
};

class MessageLog{

    int currentFreeId;
    vector<Message> log;
    vector<Message> temp;
    string fileName;
    string arrOfErrors[5] = {
            "debug",
            "info",
            "fatal",
            "warning",
            "error"
    };

public:
    explicit MessageLog(const string& fileName);

    void defineId();
    bool emptyVector();
    void clearVector();
    int countMessagesInTheVector();

    //Додавання елементів
    void createNewElemAndAddToVector(const string& message);

    //Зберігання даних (запис даних у файл)
    void saveToFile(bool fromTemp = false);

    //Відновлення даних (зчитування даних з файлу);
    void readFromTxt(bool inTemp = false);
    void readFromBin(bool inTemp = false);

    //Вивід всіх збережених даних;
    void outFromTxt() const;
    void outFromBin() const;
    void outFromVector() const;

    //Пошук за заданими критеріями (див. підваріанти a-c );
    vector<Message> searchBetweenTime(FullTime, FullTime);
    vector<Message> searchTypeAndLoading(string, double);
    vector<Message> searchSubString(const string& subStr, bool inVector = false);

    //Видалення елементів (додаткові бали)
    void deleteOneMessage(int);

    //Модифікація елементів (додаткові бали)
    void updateOneMessage(int id, const string& newMessage);

    //Допоміжні
    void generateMessagesToFile(int count);
    bool subString(string, string);
    void clearFiles();

    benchData forBenchmark(int);//generate N message, save to files,
                                //reading from files and searching random element
};

#endif //LABOR1_FUNCTIONS_H
