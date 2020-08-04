#include <string.h>
#include <fstream>                                                                               
#include <sstream>
#include <stdlib.h> 

#include <array>
#include <iostream>
#include <cassert>

using namespace std;

constexpr unsigned N = 2000; 


struct StringMark
{
    const char marker='\0';
    std::array<char, N> strM = { marker };

    void erase(int first, int second)
    {
        assert(first < second);
        int def = second - first-1;
        for (first; second < N && strM[second] != marker; second++, first++)
        
        {
            strM[first+1] = strM[second];
            
        }
        strM[second -def] = marker;
    }

};


StringMark readStream(istream& input, char* filename)
{
    StringMark sm;
    char s;
    int i = 0;
    input.unsetf(ios::skipws);

        while (!input.eof())
        {
            input >> s;
            sm.strM[i++] = s;
            
            if ((input).eof())
            {
                break;
            }

        }

    
    sm.strM[--i] = sm.marker;
    if (sm.strM[0] == sm.marker)
    {
        cout << "net strok dlia obrabotki " << endl;
        exit(0);
    }
    return sm;
}



int main()
{
    const unsigned lensize = 60;
    char filename1[lensize];
    cout << "enter the file name: ";
    cin >> filename1;

    
    ifstream input(filename1);
    
    if (!input.is_open())
    {
        cout << "the file was not detected " << endl;
        exit(0);
    }

    StringMark originalS = readStream(input, filename1);

    
    
    for (int i = 0; originalS.strM[i] != originalS.marker; i++)
    {
        char c = originalS.strM[i];
        cout << c;
    }
    cout << endl;

    cout << "vvedite vid skobok cherez probel, chtobi udalit simvoli vnutri ";
    char openElem, closeElem;
    cin >> openElem >> closeElem;

    int fistopen = 0, lastclose = 0;
    for (int j = 0; originalS.strM[j] != originalS.marker; j++)
    {
        for (int i = 0; originalS.strM[i] != originalS.marker; i++)
        {
            if (originalS.strM[i] == openElem)
            {
                fistopen = i;
            }
            if (originalS.strM[i] == closeElem)
            {
                lastclose = i;
            }
            if (fistopen != 0 && lastclose != 0)
            {
                originalS.erase(fistopen, lastclose);
                fistopen = 0;
                lastclose = 0;

            }

        }
    }

    

    for (int i = 0; originalS.strM[i] != originalS.marker; i++)
    {
        char c = originalS.strM[i];
        cout << c;
    }
    cout << endl;

    char filename2[lensize];
   
    cout << "enter the file name to : ";
    cin >> filename2;
    
    ofstream output(filename2);
    
    if (output.is_open())
    { 
        output << endl;
        for (int i = 0; originalS.strM[i] != originalS.marker; i++)
        {
            
            char c = originalS.strM[i];
            output << c;
        }
        cout << endl;
    }
    else 
    {
        cout<< "the file was not detected " << endl;
    }

}


