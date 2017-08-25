/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * 我的字典
 * 1） 新增词条
 * 2）查询单词
 */

/* 
 * File:   main.cpp
 * Author: Administrator
 *
 * Created on August 25, 2017, 3:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include <cstring>


using namespace std;

void showMainMenu();
void addVocabulary();
void searchVocabulary();
void saveVocabulary(string);
void loadDictionary(vector<string>&);
 
/*
 * 
 */
int main(int argc, char** argv) {
    
   
     
    string action;
      
    //选择操作
    while(action != "exit")
    {
         //显示主菜单
        showMainMenu();
        
        cin >> action;
        
        if(action == "add")
        {
            //1) 新增词条
                 addVocabulary();
        }else if(action == "search")
        {
              //2)查询单词
                 searchVocabulary();
        }
        else
        {
            
        }
     
    }
    
  
     
    return 0;
}


void showMainMenu()
{
   
    cout << "请选择操作" << endl;
    cout << "1) 新增词条，输入add并回车" <<endl;
    cout << "2) 查询单词，输入search并回车" <<endl;
    cout << "3) 退出系统， 输入 exit并回车" <<endl;
}

/**
 * 新增词条
 */
void addVocabulary()
{
  //  string input;
    
    //提示用户
    cout << "输入语法: <英文>(空格)<中文>" << endl;
    
    //输入内容
    cin.ignore(10000, '\n');
    char buff[100];
    cin.getline(buff, 100);

    cout << buff;
    
    //保存 ：载入单词库，新增单词，保存至文件
    saveVocabulary(buff);
 
    
 
}

void searchVocabulary()
{
    //提示
    cout << "输入查询单词" << endl;
    
    //输入
  //  cin.ignore(10000, '\n');
    string word;
    cin >> word;
    
    //根据输入单词从库中查询词条: 载入词库 循环比对 
    vector<string> dic;
    loadDictionary(dic);
    for(string voc : dic)
    {
        if(strstr(voc.c_str(), word.c_str()) != NULL )
        {
            cout << voc << endl;
        }
    }
    
}

void parseInput(string input, vector<string>& out)
{
    stringstream ss(input);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
   // out(begin, end);
}

void saveVocabulary(string input)
{
    ifstream in;
    in.open("dict.data");
   //载入词库，
    string line;
    vector<string> dic;
    loadDictionary(dic);
    
    //把新单词加入词库
    dic.push_back(input);
    
  //  vector<string> out;
  //  parseInput(input,  out);
    //新增单词，保存至文件
    ofstream out;
    out.open("dict.data");
    for(string voc  :  dic)
    {
        out << voc << '\n';
    }
    
    out.close();
     
}

/**
 * 载入词库
 * 
 * @param dic
 */
void loadDictionary(vector<string>& dic)
{
     ifstream in;
    in.open("dict.data");
   //载入词库，
    string line;
    while(!in.fail() && !in.eof())
    {
        getline(in, line);
        if(line.length() > 0 ) {
             dic.push_back(line);
        }
    }
    in.close();
}