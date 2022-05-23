#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int w = 20;
const int h = 20;

const int size1 = w * h;
int size2[size1];

int d;
int level=1;

int d1 = 1;
int head_x;
int head_y;

int snake_length=2;
int score = 0;

bool game1;

void s();
void s2();
void s3();
void s4(int x, int y);
void s5();
void s6();
char s7(int something);
void s8();

int main() {
    s8();
}

void s8() {
    HKL keyboard = GetKeyboardLayout(0);

    int layout = LOWORD(keyboard);

    if (layout == 0x0419)
    {
        cout << "First, please change the keyboard layout to English" << endl << endl;
    }
    cout << "Please select the difficulty:" << endl << endl;
    cout << "1 - Easy" << endl;
    cout << "2 - Medium" << endl;
    cout << "3 - Hard" << endl;
    cout << endl;
    cin >> d;
    cout << endl;
    int count = 0;
    if (d == 1 || d == 2 || d == 3)
    {
        s();
    }
    else
    {
        while (true)
        {
            count++;
            if (count == 4)
            {
                d = 1;
                s();
                break;
            }
            else {
                cout << "This level does not exist please choose another:" << endl << endl;
                cout << "1 - Easy" << endl;
                cout << "2 - Medium" << endl;
                cout << "3 - Hard" << endl;
                cout << endl;
                cin >> d;
                cout << endl;
                if (d == 1 || d == 2 || d == 3)
                {
                    s();
                    break;
                }
            }
        }
    }
    return;
}


void s() {//движение
    s3();
    game1 = true;
    while (game1)
    {
        if (_kbhit()) {
            char key = _getch();

            switch (key) {
            case 'w':
                if (d1 != 3) d1 = 1;
                break;
            case 'd':
                if (d1 != 4) d1 = 2;
                break;
            case 's':
                if (d1 != 1) d1 = 3;
                break;
            case 'a':
                if (d1 != 2) d1 = 4;
                break;
            }
        }
        s5();
        system("cls");
        s2();//скорость игры
        switch (d) {
        case 1: Sleep(500);
            break;
        case 2: Sleep(300);
            break;
        case 3: Sleep(100);
            break;
        }
    }
    cout << "!Game over!" << endl << "Number of points: " << score << endl << endl;

    cout << "Level: " << level << endl << endl;
    level++;
    cin.ignore();
    int k;
    cout << "Exit game - 0" << endl;
    cout << "Continue - (1-9)" << endl << endl;
    cin >> k;
    cout << endl;

    if (k == 0)
    {
        return;
    }
    else 
    {
        s8();
    }
}

void s6() //генерация еды рандомно (кроме рамки игры)
{
    int x = 0;
    int y = 0;
    do
    {
        srand(time(NULL));
        x = rand() % (w - 2) + 1;
        y = rand() % (h - 2) + 1;
    } while (size2[x + y * w] != 0);

    size2[x + y * w] = -2;
}

void s5()//обновление карты
{
    switch (d1)
    {
    case 1: s4(-1, 0);
        break;
    case 2: s4(0, 1);
        break;
    case 3: s4(1, 0);
        break;
    case 4: s4(0, -1);
        break;
    }
    for (int i = 0; i < size1; i++)
    {
        if (size2[i] > 0) {
            size2[i]--;
        }
    }
}



void s4(int x, int y)//логика игры
{

    int x1 = head_x + x;
    int y1 = head_y + y;

    if (size2[x1 + y1 * w] == -2) {
        snake_length++;
        score++;
        s6();
    }
    else if (size2[x1 + y1 * w] != 0) {
        game1 = false;
    }
    head_x = x1;
    head_y = y1;
    size2[head_x + head_y * w] = snake_length + 1;
}






void s3()//заполнение поля 
{

    head_x = w / 2;
    head_y = h / 2;
    size2[head_x + head_y * w] = 1;

    for (int i = 0; i < w; i++) {
        size2[i] = -1;
        size2[i + (h - 1) * w] = -1;
    }

    for (int j = 0; j < h; j++) {
        size2[0 + j * h] = -1;
        size2[(w - 1) + j * w] = -1;
    }
    s6();
}

void s2() //создание поля
{
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {

            cout << s7(size2[i + j * w]);//вывод поля

        }
        cout << endl;
    }
}

char s7(int value)//рамка игры, змейка, еда
{
    if (value > 0) return 'o';
    switch (value)
    {
    case -1: return '#';
    case -2: return '*';
    }
}




