//
//  main.cpp
//  Hyun_Namkoong_165_assign9
//
//  Created by Hyun Namkoong on 4/21/22.
//

#include <iostream>

using namespace std;

int getMode(int*, int);
int* makeArray(int);

int main()
{
 const int SIZE = 5;
 int test[SIZE] = {1, 2, 3, 4, 5};
 int mode;
 mode = getMode(test, SIZE);
   
 if (mode == -1)
 cout << "The test set has no mode.\n";
 else
 cout << "\nThe mode of the test set is: "
      << mode << endl;
     system("PAUSE");
 return 0;
}

int getMode(int *array, int size)
{
    int mode=0;
 
 int* frequencies = makeArray(size);
    for(int i=0;i<size;i++)
    {
        int count=0;
        for(int j=0;j<size;j++)
        {
           if(array[i]==array[j])
           {
               count++;
           }
        }
        *(frequencies+i)=count;
    }
    
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=*(frequencies+i);
        if(sum==size)
        {
            mode = -1;
        }
        else
        {
            int max =0;
         for(int j=0;j<size;j++)
         {
                if(*(frequencies+0)<*(frequencies+j))
                {
                    *(frequencies+0)=*(frequencies+j);
                    max = j;
                }
         }
         mode = *(array+max);
        }
    }
   

 delete[] frequencies;
    
    return mode;
}
// makeArray has been completed for you
int* makeArray(int size)
{
 return new int[size];
}
