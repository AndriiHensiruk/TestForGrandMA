#include <iostream>
#include<ctime>

using namespace std;

int** arrayMem(int** parray, int frame_width, int frame_height);
void fillArray(int** parray, int frame_width, int frame_height, int pic_x, int pic_y);
void drawArray(int** parray, int frame_width, int frame_height);
void drawNextArray(int** parray, int pic_width, int pic_height);
void drawArray(int** parray, int frame_width);

int main()
{
    
   
    int frame_width = 0;
    int frame_height = 0;
    int** array = 0;
    int pic_x = 1;
    int pic_y = 1;

    cout << "Number of lines:\n";
    cin >> frame_width;
    cout << "Number of columns:\n";
    cin >> frame_height;
    cout << "The amount of garbage by X\n";
    cin >> pic_x;
    cout << "The amount of garbage by Y\n";
    cin >> pic_y;
    array = arrayMem(array, frame_width, frame_height);
    fillArray(array, frame_width, frame_height, pic_x, pic_y);
    drawArray(array, frame_width, frame_height);
    drawNextArray(array, frame_width, frame_height);
    return 0;
}

int** arrayMem(int** parray, int frame_width, int frame_height)
{
    parray = new int* [frame_width];
    for (int i = 0; i < frame_width; i++)
        parray[i] = new int[frame_height];
    return parray;
}

void fillArray(int** parray, int frame_width, int frame_height, int pic_x, int pic_y)
{
    for (int i = 0; i < frame_width; i++)
    {
        for (int j = 0; j < frame_height; j++)
        {
            if (i < pic_x || j < pic_y)
                parray[i][j] = NULL;
            else
            parray[i][j] = 10 + rand() % 41;
        }
    }
}

void drawArray(int** parray, int frame_width, int frame_height)
{
    for (int i = 0; i < frame_width; i++)
    {
        for (int j = 0; j < frame_height; j++)
        {
            cout << parray[i][j] << " | ";
        }cout << endl;
    }
}

void drawNextArray(int** parray, int pic_width, int pic_height)
{
    for (int i = 0; i < pic_width; i++)
    {
        for (int j = 0; j < pic_height; j++)
        {
            if(parray[i][j] !=NULL)
            cout << parray[i][j] << " | ";
        }cout << endl;
    }
}

void drawArray(int** parray, int frame_width)
{
    for (int i = 0; i < frame_width; i++)
    {
        delete[]parray[i];
        delete[]parray;
    }

}
