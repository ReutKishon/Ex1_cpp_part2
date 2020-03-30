//Student: Reut Keyshawn

#include <cctype>
#include <string>
#include <locale>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

#include "PhoneticFinder.hpp"

using namespace std;

struct NoWordFoundException : public exception
{
private:
    string target_word;
    string *result_str;

public:
    NoWordFoundException(string word) : result_str(new string("Did not find the word '" + word + "' in the text"))
    {
    }
    const char *what() const throw()
    {
        return this->result_str->c_str();
    }

    ~NoWordFoundException()
    {
        delete this->result_str;
    }
};

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
        if (find(group.begin(), group.end(), tolower(a)) != group.end() &&
            find(group.begin(), group.end(), tolower(b)) != group.end())
        {
            return true;
        }
    }

    return false;
}

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
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

namespace phonetic
{
string find(string text, string target_word)
{
    // making a string stream
    stringstream words_stream(text);
    string word;

    // Read and print each word.
    cout << "Checking word: " << target_word << endl;

    while (words_stream >> word)
    {
        if (are_words_equal(trim(word), trim(target_word)))
        {
            cout << "word found: " << word << endl;
            return word;
        }
    }

    throw NoWordFoundException(target_word);
}

} // namespace phonetic
