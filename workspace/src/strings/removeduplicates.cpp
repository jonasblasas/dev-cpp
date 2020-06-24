#include <bits/stdc++.h> 
using namespace std; 

void sortUniqifyPrint(string text)
{
    sort(text.begin(), text.end()); 
  
    // Using unique() method 
    auto res = unique(text.begin(), text.end()); 
  
    cout << string(text.begin(), res) 
         << endl; 
}

void removeDuplicates(string text)
{
    // declaring character array 
    char str[text.length() + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(str, text.c_str());
    
    // Used as index in the modified string 
   int index = 0;    
     
   // Traverse through all characters 
   for (int i=0; i<sizeof(str); i++) { 
         
     // Check if str[i] is present before it   
     int j;   
     for (j=0; j<i; j++)  
        if (str[i] == str[j]) 
           break; 
       
     // If not present, then add it to 
     // result. 
     if (j == i) 
        str[index++] = str[i]; 
   } 
     
   cout << str << endl; 
}

void removeDuplicatesWithSet(string text)
{
    // declaring character array 
    char str[text.length() + 1]; 
  
    // copying the contents of the 
    // string to char array 
    strcpy(str, text.c_str());

    set<char> s (str, str+sizeof(str)-1); 

    for(auto c : s)
    {
        cout << c;
    }
    cout << endl;
}
  
int main() 
{ 
    string str = "microsoftmicrosoft"; 
    
    sortUniqifyPrint(str);

    removeDuplicates(str);

    removeDuplicatesWithSet(str);
} 