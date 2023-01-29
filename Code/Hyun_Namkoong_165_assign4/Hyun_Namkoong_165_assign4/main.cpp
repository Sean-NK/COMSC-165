//
//  main.cpp
//  Hyun_Namkoong_165_assign4
//
//  Created by Hyun Namkoong on 3/7/22.
//

#include <iostream>
#include <array>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    cout << "Please enter the student's answers for each of the questions." << endl;
    cout << "Please Enter after typing each answer." << endl;
    cout << "Please enter only an A, B, C, or D for each question." << endl;
    
    array<char,20> correct_answer= {'A','D','B','B','C','B','A','B','C','D','A','C','D','B','D','C','C','A','D','B'};
    array<char,20> student_answer;
    for (int i = 0; i < 20; i++)
    {
        while(i<20)
        {
            cout << "Question " << i+1 << ": ";
            char a;
            cin >> a;
           if(a=='A'||a=='B'||a=='C'||a=='D')
            {
               student_answer.at(i)=a;
                i++;
             }
            else
            {
              cout << "Use only an A, B, C, or D!" << endl;
              cout << "Please try again." <<endl;
            }
            
        }
        
    }
    int same=0;
    vector<int> vec;
    for(int j=0;j<20;j++)
       {
            if (correct_answer.at(j)== student_answer.at(j))
            {
                same=same+1;
            }
            else
            {
                vec.push_back(j);
            }
        }
        
     if(same>=15)
     {
         cout << "The student passed the exam." << endl;
         cout << endl;
     }
    else
    {
        cout << "The student failed the exam." << endl;
        cout << endl;
    }
    
    
    cout << "Correct Answers: " << 20-vec.size()<<endl;
    cout << "Incorrect Answers: " << vec.size()<< endl;
    cout << endl;
    cout << "Questions that were answered incorrectly: " << endl;
    for(int i=0;i<vec.size();i++)
    {
        cout << vec[i]+1 << endl;
    }
        
    
    return 0;
    
}

