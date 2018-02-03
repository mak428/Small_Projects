// Check if two given strings are anagrams of each other
#include <iostream>
#include <string>
#include <locale>  

using namespace std;

char charHistogram[26] = {0};


bool isAnagram(string a, string b)
{
    std::locale loc;

    for(auto elem : a)
        std::cout << std::tolower(elem,loc);

    for(auto elem : b)
        std::cout << std::tolower(elem,loc);

    if (a.length() != b.length())
    {
        return false;
    }

    int counter = 0; 
    for(int i = 0; i < a.length(); ++i)
    {
         charHistogram[a[i] - '0']++;
    }
    for(int j = 0; j < b.length(); ++j)
    {
         charHistogram[b[j] - '0']--;
    }
    for(int i = 0; i < 26; ++i)
    {
         if (charHistogram[i] != 0) 
         {
	      cout << "charHistogram[" << i << "] is non zero and = " << charHistogram[i] << endl;             
              return false;
         }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " <string 1> <string2> \n";
        return -1;
    }
    
    string a(argv[1]);
    string b(argv[2]);

    if (isAnagram(a, b))
    {
        cout << a << " is an anagram of " << b << endl;
    }
    else
    {
        cout << a << " is NOT an anagram of " << b << endl;
    }
    return 0;
}
