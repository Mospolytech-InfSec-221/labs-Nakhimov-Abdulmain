#include <iostream>
#include <set>
#include <string>
#include <vector>

using std::string;

struct MyStruct
{
    string Name;
    int Scores;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<MyStruct> st;
    std::set<string> Names;
    int Score, flag;
    string Str;
    MyStruct Data;
    while (true) 
    {
        flag = 0;
        std::cout << "Ââåäèòå ñâîå èìÿ è êîëè÷åñòâî áàëëîâ ";
        std::cin >> Str >> Score;
        if (Score == -1) break;
        for (auto i : Names) 
        {
            if (i == Str) 
            {
                flag++;
                break;
            }
        }
        if (flag == 0) 
        {
            Data.Name = Str; Data.Scores = Score;
            Names.insert(Str);
            st.push_back(Data);
        }
    }
    for (auto i : st)
        std::cout << i.Name << " " << i.Scores << " ";
}
