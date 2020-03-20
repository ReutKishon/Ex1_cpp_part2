#include "PhoneticFinder.hpp"
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<list<char>> letter_groups = {
    {'v', 'w'},
    {'b', 'f', 'p'},
    {'g', 'j'},
    {'c', 'k', 'q'},
    {'s', 'z'},
    {'d', 't'},
    {'o', 'u'},
    {'i', 'y'}};

bool are_letters_equal(char a, char b)
{

    if (a == b)
    {
        return true;
    }

    if (tolower(a) == tolower(b))
    {
        return true;
    }

    for (auto &group : letter_groups)
    {
        // Check if iterator points to end or not
        if (find(group.begin(), group.end(), a) != group.end() &&
            find(group.begin(), group.end(), b) != group.end())
        {
            return true;
        }
    }

    return false;
}

bool are_words_equal(string word1, string word2)
{
    if (word1.length() != word2.length())
        return false;
    for (auto i = 0; i < word1.length(); i++)
    {
        if (!are_letters_equal(word1[i], word2[i]))
            return false;
    }
    return true;
}

string find(string target_word, string text)
{
    // making a string stream
    stringstream words_stream(text);
    string word;
    // Read and print each word.
    cout << "Checking word: " << target_word << endl;

    while (words_stream >> word)
    {
        if (are_words_equal(word, target_word))
        {
            cout << "word found: " << word << endl;
            return word;
        }
    }
    throw std::invalid_argument("word not found!");
}
