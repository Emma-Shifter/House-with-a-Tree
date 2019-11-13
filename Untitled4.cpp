#include <stdlib.h>
#include <string>
#include "TXLib.h"

const COLORREF MY_BLUE = RGB(175, 238, 238),
               MY_GREEN = RGB(127, 255, 0),
               MY_DARKGREEN = RGB(0, 100, 0);

using namespace std;
void paintTree1 (int x1, int y1, int size_);
void paintSun (int x2, int y2, int size_);


int main()
{
    txCreateWindow(800,600);

    int xTree = 520; //место расположения дерева 1 по оси Ох
    int yTree = 520; // место расположения дерева 1 по оси Оу
    int zTree = 10; // высота дерева
    int speed = 5; // скорость мультика
    int buildinghouse; // строительство дома

    do // опросник поп оводу дома
    {
        txSetColour (TX_BLACK);
        cout<<"Строить дом? (напечатайте 1, если да, и 0, если нет):"<<endl;
        cin>>buildinghouse;
    }
    while(!((buildinghouse == 1)||(buildinghouse == 0)));



    txClear();
    txClearConsole ();

    txSetFillColour(RGB(240, 230, 140));//новое окно с приветствием
    txRectangle(0, 0, 800, 600);
    txTextOut(100, 200, "Привет! Эта программа нарисует мультик по твоему желанию высказанному ранее");
    txTextOut(300, 250, "Просто нажми START ");
    txSetFillColour(MY_GREEN);
    txRectangle (300, 300, 500, 380); //создание кнопки "START"
    txSetColour (TX_BLACK);
    txTextOut (380, 340, "START");

    RECT area = {300, 300, 500, 380};

    while (txMouseButtons() !=3)
    {
        if (txMouseButtons() & 1)
        {
            if (In (txMousePos(), area))
            {
                txBegin();
                txClear();

                txSetFillColour(MY_BLUE);
                txRectangle (175, 0, 800, 460);

                txSetFillColour(MY_DARKGREEN);
                txRectangle (175, 460, 800, 600);

                paintSun(600, 60, 25);

                txSetFillColour(RGB(240, 128, 128));//инструкция
                txRectangle(5, 5, 178, 240);
                txSetColour(TX_BLACK);
                txTextOut(5, 10, "Привет! Это Info ");
                txTextOut(5, 25, "блок ");
                txTextOut(5, 40, "1Для разблоки-");
                txTextOut(5, 55, "ровки анимации нажми ");
                txTextOut(5, 70, "SHIFT   ");
                txTextOut(5, 85, "2Для запуска роста  ");
                txTextOut(5, 100, "ели нажми стрелку ");
                txTextOut(5, 115, "вверх ");
                txTextOut(5, 130, "3Если будешь удер-");
                txTextOut(5, 145, "живать стрелку вверх   ");
                txTextOut(5, 160, "ель будет расти ");
                txTextOut(5, 175, "4Для завершения ани-");
                txTextOut(5, 190, "мации одновременно ");
                txTextOut(5, 205, "нажми на правую и  ");
                txTextOut(5, 220, "левую кнопки мыши ");
                txTextOut(5, 235, "Приятного просмотра!");


                txSetFillColour(TX_WHITE);

                if(buildinghouse == 1)
                {
                    txSetColour(RGB(139, 69, 19), 3);//постройка дома(декор)
                    txLine(180, 400, 180, 500);
                    txLine(180, 500, 320, 500);
                    txLine(320, 500, 320, 400);
                    txLine(320, 400, 180, 400);
                    txSetFillColour(RGB(210, 105, 30));
                    txRectangle(181, 401, 321, 501);
                    txSetFillColour(RGB(160, 82, 45));
                    POINT roof[5] = {{180, 400}, {200, 380}, {280, 340}, {360, 380}, {320, 400}};
                    txPolygon (roof, 5);
                    txSetColour(RGB(139, 69, 19), 3);
                    txLine(180, 400, 280, 340);
                    txLine(180, 400, 200, 380);
                    txLine(200, 380, 280, 340);
                    txLine(320, 400, 280, 340);
                    txLine(360, 380, 280, 340);
                    txSetFillColour(RGB(139, 69, 19));
                    POINT wall[4] = {{320, 400}, {360, 380}, {360, 480}, {320, 500}};
                    txPolygon (wall, 4);
                    txSetColour(RGB(222, 184, 135), 2);
                    txRectangle(200, 420, 240, 460);
                    txSetFillColour(RGB(176, 196, 222));
                    txRectangle(201, 421, 241, 461);
                    txSetColour(RGB(222, 184, 135), 2);
                    txLine(220, 420, 220, 460);
                    txLine(200, 440, 240, 440);
                    txRectangle(270, 440, 300, 500);
                    txSetFillColour(TX_GREEN);
                    txRectangle(271, 441, 299, 499);
                    txSetFillColour(TX_BLACK);
                    txCircle(290, 470, 5);

                    txSetFillColour(TX_WHITE);
                }

            }
            txSleep (0);
        }

        if(GetAsyncKeyState(VK_SHIFT))
        {
            if(buildinghouse == 1)
            {
                while(zTree<200)
                {
                    txBegin();
                    txClear();

                    txSetFillColour(MY_BLUE);
                    txRectangle (175, 0, 800, 460);

                    txSetFillColour(MY_DARKGREEN);
                    txRectangle (175, 460, 800, 600);

                    txSetFillColour(RGB(240, 128, 128));//инструкция
                    txRectangle(5, 5, 178, 240);
                    txSetColour(TX_BLACK);
                    txTextOut(5, 10, "Привет! Это Info ");
                    txTextOut(5, 25, "блок ");
                    txTextOut(5, 40, "1Для разблоки-");
                    txTextOut(5, 55, "ровки анимации нажми ");
                    txTextOut(5, 70, "SHIFT   ");
                    txTextOut(5, 85, "2Для запуска роста  ");
                    txTextOut(5, 100, "ели нажми стрелку ");
                    txTextOut(5, 115, "вверх ");
                    txTextOut(5, 130, "3Если будешь удер-");
                    txTextOut(5, 145, "живать стрелку вверх   ");
                    txTextOut(5, 160, "ель будет расти ");
                    txTextOut(5, 175, "4Для завершения ани-");
                    txTextOut(5, 190, "мации одновременно ");
                    txTextOut(5, 205, "нажми на правую и  ");
                    txTextOut(5, 220, "левую кнопки мыши ");
                    txTextOut(5, 235, "Приятного просмотра!");

                    txSetColour(RGB(139, 69, 19), 3);//постройка дома(декор)
                    txLine(180, 400, 180, 500);
                    txLine(180, 500, 320, 500);
                    txLine(320, 500, 320, 400);
                    txLine(320, 400, 180, 400);
                    txSetFillColour(RGB(210, 105, 30));
                    txRectangle(181, 401, 321, 501);
                    txSetFillColour(RGB(160, 82, 45));
                    POINT roof[5] = {{180, 400}, {200, 380}, {280, 340}, {360, 380}, {320, 400}};
                    txPolygon (roof, 5);
                    txSetColour(RGB(139, 69, 19), 3);
                    txLine(180, 400, 280, 340);
                    txLine(180, 400, 200, 380);
                    txLine(200, 380, 280, 340);
                    txLine(320, 400, 280, 340);
                    txLine(360, 380, 280, 340);
                    txSetFillColour(RGB(139, 69, 19));
                    POINT wall[4] = {{320, 400}, {360, 380}, {360, 480}, {320, 500}};
                    txPolygon (wall, 4);
                    txSetColour(RGB(222, 184, 135), 2);
                    txRectangle(200, 420, 240, 460);
                    txSetFillColour(RGB(176, 196, 222));
                    txRectangle(201, 421, 241, 461);
                    txSetColour(RGB(222, 184, 135), 2);
                    txLine(220, 420, 220, 460);
                    txLine(200, 440, 240, 440);
                    txRectangle(270, 440, 300, 500);
                    txSetFillColour(TX_GREEN);
                    txRectangle(271, 441, 299, 499);
                    txSetFillColour(TX_BLACK);
                    txCircle(290, 470, 5);

                    paintSun(600, 60, 25);


                    if(GetAsyncKeyState(VK_UP))
                    {
                        int kol = 0;
                        paintTree1(xTree+kol,yTree, zTree);
                        kol = kol +100;
                        txSleep(speed);
                        zTree = zTree+1;
                    }

                    txEnd();
                }
                txSleep (0);
            }
            else if (buildinghouse == 0)
            {
                while(zTree<200)
                {
                    txBegin();
                    txClear();

                    txSetFillColour(MY_BLUE);
                    txRectangle (175, 0, 800, 460);

                    txSetFillColour(MY_DARKGREEN);
                    txRectangle (175, 460, 800, 600);

                    paintSun(600, 60, 25);

                    txSetFillColour(RGB(240, 128, 128));//инструкция
                    txRectangle(5, 5, 178, 240);
                    txSetColour(TX_BLACK);
                    txTextOut(5, 10, "Привет! Это Info ");
                    txTextOut(5, 25, "блок ");
                    txTextOut(5, 40, "1Для разблоки-");
                    txTextOut(5, 55, "ровки анимации нажми ");
                    txTextOut(5, 70, "SHIFT   ");
                    txTextOut(5, 85, "2Для запуска роста  ");
                    txTextOut(5, 100, "ели нажми стрелку ");
                    txTextOut(5, 115, "вверх ");
                    txTextOut(5, 130, "3Если будешь удер-");
                    txTextOut(5, 145, "живать стрелку вверх   ");
                    txTextOut(5, 160, "ель будет расти ");
                    txTextOut(5, 175, "4Для завершения ани-");
                    txTextOut(5, 190, "мации одновременно ");
                    txTextOut(5, 205, "нажми на правую и  ");
                    txTextOut(5, 220, "левую кнопки мыши ");
                    txTextOut(5, 235, "Приятного просмотра!");

                    txSetFillColour(TX_WHITE);

                    if(GetAsyncKeyState(VK_UP))
                    {
                        int kol = 0;
                        paintTree1(xTree+kol,yTree, zTree);
                        kol = kol +100;
                        txSleep(speed);
                        zTree = zTree+1;
                    }

                    txEnd();
                }
                txSleep (0);
            }

        }
    }
}

void paintTree1 (int x1, int y1, int z1) //метод рисования дерева 2
{
    txSetColour(RGB(0, 128, 0), 5);
    txLine(x1, y1, x1, y1-z1);
    txSetColour(RGB(0, 128, 0), 5);
    int a = 0;
    int b = 0;
    for (int i=0; i<10; i++)
    {
        txLine(x1, y1-z1+a, x1+30, y1-z1+a+40);
        txLine(x1, y1-z1+a, x1-30, y1-z1+a+40);
        a = a+10;
        for (int j=5; j<10; j++)
        {
            txLine(x1, y1-z1+a, x1+40, y1-z1+a+60);
            txLine(x1, y1-z1+a, x1-40, y1-z1+a+60);
        }

    }
}

void paintSun (int x2, int y2, int size_) // метод рисования солнца
{
    txSetFillColour(TX_YELLOW);
    txSetColour(TX_YELLOW);
    txCircle(x2, y2, size_);
    txSetFillColour(TX_WHITE);
    txSetColour(TX_YELLOW, 5);
    txLine(x2-size_, y2, x2-size_-15, y2-10);
    txLine(x2-size_, y2, x2-size_-15, y2+10);
    txLine(x2, y2+size_, x2-10, y2+size_+15);
    txLine(x2, y2+size_, x2+10, y2+size_+15);
    txLine(x2+size_, y2, x2+size_+15, y2-10);
    txLine(x2+size_, y2, x2+size_+15, y2+10);
    txLine(x2, y2-size_, x2-10, y2-size_-15);
    txLine(x2, y2-size_, x2+10, y2-size_-15);
    txLine(x2-size_+ 0.5*size_, y2-size_+ 0.5*size_, x2-size_+ 0.5*size_-20, y2-size_+ 0.5*size_-10);
    txLine(x2-size_+ 0.5*size_, y2-size_+ 0.5*size_, x2-size_+ 0.5*size_-10, y2-size_+ 0.5*size_-20);
    txLine(x2+size_- 0.5*size_, y2+size_- 0.5*size_, x2+size_- 0.5*size_+10, y2+size_- 0.5*size_+20);
    txLine(x2+size_- 0.5*size_, y2+size_- 0.5*size_, x2+size_- 0.5*size_+20, y2+size_- 0.5*size_+10);
    txLine(x2-size_+ 0.5*size_, y2+size_- 0.5*size_, x2-size_+ 0.5*size_-10, y2+size_- 0.5*size_+20);
    txLine(x2-size_+ 0.5*size_, y2+size_- 0.5*size_, x2-size_+ 0.5*size_-20, y2+size_- 0.5*size_+10);
    txLine(x2+size_- 0.5*size_, y2-size_+ 0.5*size_, x2+size_- 0.5*size_+10, y2-size_+ 0.5*size_-20);
    txLine(x2+size_- 0.5*size_, y2-size_+ 0.5*size_, x2+size_- 0.5*size_+20, y2-size_+ 0.5*size_-10);
}
