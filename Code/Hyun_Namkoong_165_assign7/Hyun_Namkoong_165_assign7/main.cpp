//
//  main.cpp
//  Hyun_Namkoong_165_assign7
//
//  Created by Hyun Namkoong on 3/22/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void selectionSort(vector<string> &);

vector <string> getVector(string Names);
string getName(string s);
bool search(string s, vector<string> name);
void  displayResult(string s, string s1, bool b);
void writeToFile(string s, vector <string> vec);
void reverseVector(vector<string> &);

int main()
{
   string boyName, girlName;
   bool boyNameFound, girlNameFound;

   vector<string> boyNames(getVector("BoyNames.txt"));
   vector<string> girlNames(getVector("GirlNames.txt"));
    

   boyName = getName("boy's");
   girlName = getName("girl's");


   selectionSort(boyNames);
   selectionSort(girlNames);

   boyNameFound = search(boyName, boyNames);
   girlNameFound = search(girlName, girlNames);
    
   displayResult("boy's", boyName, boyNameFound);
   displayResult("girl's", girlName, girlNameFound);


   writeToFile("Boynames_asc.txt", boyNames);
   writeToFile("Girlnames_asc.txt", girlNames);

   reverseVector(boyNames);
   reverseVector(girlNames);
    
   
   writeToFile("Boynames_desc.txt", boyNames);
   writeToFile("Girlnames_desc.txt", girlNames);

   cout<<endl;

   //system("PAUSE");
   return 0;
}
void selectionSort(vector<string> &arr)
{
int startScan, minIndex;
string minValue;
   for (startScan = 0; startScan < (arr.size() - 1); startScan++)
   {
      minIndex = startScan;
      minValue = arr[startScan];
      for(int index = startScan + 1; index < arr.size(); index++)
      {
         if (arr[index] < minValue)
         {
            minValue = arr[index];
            minIndex = index;
         }
      }
      arr[minIndex] = arr[startScan];
      arr[startScan] = minValue;
   }
}

vector <string> getVector(string Names)
{
    vector <string> vec;
    
    ifstream ifs(Names);
    
    while(ifs)
    {
        string str;
        getline(ifs, str);
        
        vec.push_back(str);
    }
    return vec;
}

string getName(string s)
{
    string str;
    
    cout << "Enter a " << s << " name, or N if you" << endl << "do not wish to enter a " << s << " names: ";
    
    cin >> str;
    
    return str;
}

bool search(string s, vector<string> name)
{
    
    for(int i=0;i<name.size();i++)
    {
        if(name[i]==s)
        {
            return true;
        }
        
        
    }
    return false;
}

void displayResult(string s, string s1, bool b)
{
    if(s1=="N")
    {
        cout << "You chose not to enter a " << s << " name." << endl;
    }
    else
    {
        if(b==0)
        {
            cout << s1 << " is NOT one of the most popular " << s << " names." << endl;
        }
        else
        {
            cout << s1 << " is one of the most popular " << s << " names." << endl;
        }
    }
}

void writeToFile(string s, vector <string> vec)
{
    ofstream ofs(s);
    for(int i=0; i<vec.size();i++)
    {
        ofs << vec[i] << endl;
    }
}



void reverseVector(vector<string> &arr)
{
    int startScan, maxIndex;
    string maxValue;
       for (startScan = arr.size()-1; startScan > 0; startScan--)
       {
          maxIndex = startScan;
          maxValue = arr[startScan];
          for(int index = startScan - 1; index >= 0; index--)
          {
             if (arr[index] < maxValue)
             {
                maxValue = arr[index];
                maxIndex = index;
             }
          }
          arr[maxIndex] = arr[startScan];
          arr[startScan] = maxValue;
       }
}





























//int main()
//{
//    ifstream ifs("BoyNames.txt");
//
//    if(!ifs)
//    {
//        cout << "Cannot open file" << endl;
//        exit(1);
//    }
//    while(ifs)
//    {
//        string str;
//        getline(ifs, str);
//
//        cout << str << endl;
//    }
//    return 0;
//}
//int main()
//{
//    ofstream ofs("filestream.txt");
//
//    ofs << "Hi" << endl;
//    ofs << "study filestream" << endl;
//
//    return 0;
//}


//
//int main()
//{
//    cout << "A" << endl;
//
//    return 0;
//}
