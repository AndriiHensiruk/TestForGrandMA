#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    string edin[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teen[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    string des[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    string sto[] = { "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};
    string thousand[] = { "one thousand", "two thousand", "three thousand", "four thousand", "five thousand", "six thousand", "seven thousand", "eight thousand", "nine thousand"};

    double numb, i, drobn;
    int natur, dr;          //variables for working with integer and fractional
    int a, b, c, d, e, f;   //"temporary" variables for integer
    int x, y, z;            //"temporary" variables for the fractional part
    string odin, dva, tri, chetir, pyat, shest; //variables for integer
    string otr;             //change for minus
    string one, two, three; //fractional variables

    cout << "Enter the number:";
    cin >> numb;

    if (numb < 0)
    {
        otr = "minus";
        numb *= -1;
    }

    drobn = modf(numb, &i);
    drobn *= 1000;
    dr = drobn + 0.5;
    natur = (int)numb;

    
    a = natur % 10;                 
    b = (natur % 100) / 10;        
    c = (natur % 1000) / 100;       
    f = natur / 100000;            
    e = (natur % 100000) / 10000;  
    d = (natur % 10000) / 1000;

    if (a != 0 && b != 1)
        odin = edin[a - 1];
    else if (a == 0 && b == 1)
        odin = "ten";
    else if (a == 0 && b == 0)
        odin = "";

    if (b == 0)
        dva = "";
    else if (b == 1 && a != 0)
        dva = teen[a - 1];
    else if (b != 1)
        dva = des[b - 2];

    if (c != 0)
        tri = sto[c - 1];

    if (a == 0 && b == 0 && c == 0)
        odin = "zero";

    if (d != 0)
        chetir = thousand[d - 1];
    else if (d == 0 && e == 1)
        chetir = "ten thousand";
    else if (d != 0 && e == 1)
        pyat = teen[d - 1] + " thousand";

    if (e != 0 && e != 1 && d == 0)
        pyat = des[e - 2] + " thousand";
    else if (e != 0 && e != 1 && d != 0)
        pyat = des[e - 2];

    if (f != 0 && d == 0 && e == 0)
        shest = sto[f - 1] + " thousand";
    else if (f != 0)
        shest = sto[f - 1];

   // Finding cents
    x = dr / 100;
    y = (dr % 100) / 10;
    z = dr % 10;

    if (y == 0 && z == 0)       
    {
        if (x == 0)
            one = "";
        else if (x == 1)
            one = edin[x - 1] + " cent";
        else
            one = edin[x - 1] + " cents";
    }

    if (z == 0 && y != 0)      
    {
        if (x == 0)
        {
            if (y == 1)
                two = edin[y - 1] + " cents";
            else
                two = edin[y - 1] + " cents";
        }
        else if (x == 1)
            two = teen[y - 1] + " cents";
        else if (x != 0)
        {
            two = des[x - 2];
            if (y == 1)
                one = edin[y - 1] + " cents";
            else
                one = edin[y - 1] + " cents";
        }
    }
   

    cout << otr << " " << shest << " " << pyat << " " << chetir;
    cout << " " << tri << " " << dva << " " << odin;
    if (a == 1)
        cout << " dollar ";
    else
        cout << " dollares ";
    cout << " " << two << " " << one;
}
