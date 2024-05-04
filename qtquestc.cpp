#include "qtquestc.h"
#include "qmessagebox.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <shellapi.h>


using namespace std; //1
namespace fs = std::filesystem; //2
using namespace fs;  //3

qtQuestC::qtQuestC(QString rPath) {

    string path = rPath.toStdString();
    
    int countAll = 0, fileCount = 0;  //5
    ofstream ItogFile; //6

    ItogFile.open("OperatoriT.txt"); //7
    for (const auto& entry : fs::directory_iterator(path))
    {

        if (entry.path().extension() == ".cpp")
        {
            ifstream chtenie; //9
            chtenie.open(entry.path()); //10
            int countSFile = 0; //11
            if (chtenie.is_open())
            {
                string line; //12
                while (getline(chtenie, line))
                {
                    for (int i = 0; i < line.length(); i++)
                    {
                        if (i == 0 and (line[i] == '/' and line[i + 1] == '/') || (line[i] == '*' and line[i + 1] == '/' and line.find("/*") == false))
                            goto skip; //13
                        if (i > 0 and (line[i] == '/' and line[i + 1] == '/') || (line[i] == '*' and line[i + 1] == '/' and line.find("/*") == false))
                        {
                            int b = line.size() - i; //14
                            line.replace(i, b, ""); //15
                            i=0; //16
                        }
                        if (line.ends_with(" ") || line.ends_with("\t"))
                            line.replace(line.size() - 1, 1, ""); //17

                    }
                    if (line.ends_with(";"))
                    {
                        countAll++; //19
                        countSFile++; //20
                    }
                skip:; //21
                }
                if (ItogFile.is_open())
                {
                    ItogFile << countSFile << "\t" << entry.path() << std::endl; //22
                }
            }

            chtenie.close(); //23


        }

    }
    ItogFile.close(); //25

    ItogFile.open("Operatori.txt"); //26
    ItogFile << countAll << endl; //27

    ifstream ItF("OperatoriT.txt"); //28
    if (ItF.is_open())
    {
        string line; //29
        while (getline(ItF, line))
        {
            ItogFile << line << std::endl; //30
        }
    }
    ItF.close(); //31

    ItogFile.close(); //32
    remove("OperatoriT.txt"); //33

    ofstream SavingDirFileS("SavedDir.txt");
    SavingDirFileS << path;
    SavingDirFileS.close();


    if (countAll == 0)
    {
        QMessageBox msgBox;     // диалоговое окно
        msgBox.setText("Папка пуста!"); // устанавливаем текст
        msgBox.exec();  // отображаем диалоговое окно
    }
    else
    ShellExecute(NULL, L"open", L"Operatori.txt", NULL, NULL, SW_SHOW); //35

}
