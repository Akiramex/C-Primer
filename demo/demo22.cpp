/**
 * @file demo22.cpp
 * @author Akira
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<fstream>
#include<unordered_map>
#include<sstream>
#include<string>

using namespace std;

void func1()
{
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
}

void word_transform(ifstream &map_file, ifstream &input)
{
    unordered_map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule of " + key);
    
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            auto map_it = trans_map.find(word);
            if (map_it != trans_map.cend())
                cout << map_it->second;
            else
                cout << word;
        }
        cout << endl;
    }
}