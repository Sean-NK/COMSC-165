//
//  main.cpp
//  Hyun_Namkoong_165_assign8
//
//  Created by Hyun Namkoong on 4/10/22.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector <string> read_teams_file(string s);
void display_teams(vector <string> vec);
string write_teams();
int check_wins(string s,vector<string> vec);
void display_wins(int i,string s);

int main()
{
    vector <string> vec(read_teams_file("Winners.txt"));
    vector <string> vec1(read_teams_file("Teams.txt"));

    display_teams(vec1);
    string str=write_teams();
    int count=check_wins(str,vec);
    display_wins(count, str);
    
    return 0;
}

vector <string> read_teams_file(string s)
{
    vector <string> vec;
    ifstream ifs(s);
    while(ifs)
    {
        string str;
        getline(ifs, str);
        vec.push_back(str);
    }

    return vec;
}

void display_teams(vector <string> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout << vec[i];
        if((i%3)==2)
        {
            cout << endl;
        }
        else
        {
            for(int i=0; i<30-vec[i].size();i++)
            {
                cout << " ";
            }
        }
    }
}

string write_teams()
{
    string str;
   
    cout << "Enter the name of one of the teams: ";
    getline(cin,str);
    
    return str;
}

int check_wins(string s,vector<string> vec)
{
    int count =0;

    for(int i=0;i<vec.size(); i++)
    {
        if(s==vec[i])
        {
            count+=1;
        }
    }
   
    return count;
}

void display_wins(int i,string s)
{
    cout << "The " << s << " have won the world Series " << i << " times between 1903 and 2012" << endl;
}




//int main()
//{
//    cout << "A" << "a"<< endl;
//
//    return 0;
//}
