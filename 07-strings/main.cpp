#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string file_name = "text.txt";
    ifstream fin(file_name);
    if (!fin.is_open())
    {
        cout << "Can't open file: " << file_name << ".\n";
        return 1;
    }

    char buf;
    string sentences;
    int num_sentences = 0;
    while ((fin.get(buf)) && (num_sentences < 3))
    {
        sentences += buf;
        if ((buf == '.') || (buf == '?') || (buf == '!'))
            num_sentences++;
    }

    cout << "Three sentences:\n" << sentences << endl;

    cout << "\nInverted sentences:\n";
    for (int i = sentences.length() - 1; i >= 0; i--)
        cout << sentences[i];
    cout << endl;

    fin.close();
    return 0;
}