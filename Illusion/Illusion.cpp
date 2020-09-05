#include <stdio.h>
#include <Windows.h>
#include <cmath>

double round(double r) { return (r > 0.0) ? (r + 0.5) : (r - 0.5); }
void print(int x, int y, char c) {
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    printf("%c", c);
}

int main()
{
    float pi = 3.14159265358979323846;
    float circle = pi * 2;
    int len = 12;
    int hlen = len / 2;
    int cx = 13;
    int cy = 8;
    float w = 11.0;
    float h = 8.0;
    float step = 0.0;

    while (1)
    {
        system("cls");

        for (int i = 0; i < len; i++)
        {
            float a = (i / (float)len) * circle;
            int x = cx + round(cos(a) * w);
            int y = cy + round(sin(a) * h);
            print(x, y, 'O');

            if (i < hlen) continue;

            step -= 0.05;
            float range = cos(a + step);
            x = cx + round(cos(a) * (w - 1) * range);
            y = cy + round(sin(a) * (h - 1) * range);
            print(x, y, 'O');
        }

        Sleep(100);
    }

    return 0;
}