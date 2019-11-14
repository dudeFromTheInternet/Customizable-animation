#include "TXlib.h"

void drawCar(int x, int yw, int y, double m, COLORREF colorforcar);
void drawTree(int x, int y, double m, COLORREF colorforseason, COLORREF colorfortrunk);
void drawStrip(int x, int y, double m);

int main()
{
    txCreateWindow (1500, 900);
    txSetColor (TX_WHITE);
    txClear ();
    txSetColor (TX_BLACK);

    //Var for the trees
    int xtree = 270, ytree = 330;
    double mtree = 1.3;
    COLORREF colorfortrunk = RGB (139, 69, 19);

    //Vars for the strips
    int xstrip = -105, ystrip = 784;
    double mstrip = 2;

    //Vars for the car
    int xcar = 1050, ycar = 520, ywheels = ycar;
    COLORREF colorforcar = RGB (250, 144, 0);
    double mcar = 1.4;

    //Animation
    int  stageforcar = 1, stageforstrips = 1, stagefortrees = 1, stageforseasons = 1, sleep = 100, numberofcolorcar = 1;
    bool cartoon = FALSE;
    COLORREF colorforseason = RGB (0, 128, 0), colorforbuttonSTOP = RGB (255, 0, 0);
    while (1==1)
    {
        txClear ();

        //Drawing sky
        txSetFillColor (TX_LIGHTCYAN);
        txRectangle (299, 0, 1500, 401);

        //Drawing grass above car
        txSetFillColor (colorforseason);
        txRectangle (299, 400, 1500, 561);

        //Drawing grass under car
        txSetFillColor (colorforseason);
        txRectangle (299, 560, 1500, 900);

        //Drawing road
        txSetFillColor (TX_DARKGRAY);
        txRectangle (299, 560, 1500, 710);

        //Drawing trees
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree+125;
        drawTree(xtree, ytree, mtree, colorforseason, colorfortrunk);
        xtree = xtree - (125*10);

        //Drawing strips
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip + 120;
        drawStrip(xstrip, ystrip, mstrip);
        xstrip = xstrip - (120*10);

        //Drawing car
        drawCar(xcar, ywheels, ycar, mcar, colorforcar);

        //Drawing options menu
        txSetFillColor (TX_WHITE);
        txRectangle (0, 0, 300, 900);

        //Drawing text: "Menu"
        txSelectFont ("Arial", 50);
        txDrawText (100, 20, 200, 70, "Menu");

        //Drawing button "STOP"
        txSetFillColor (colorforbuttonSTOP);
        txRectangle (50, 90, 250, 180);

        //Drawing text: "STOP"
        txSelectFont ("Arial", 50);
        txDrawText (50, 90, 250, 180, "STOP");

        //Drawing button "+ Speed"
        txSetFillColor (TX_WHITE);
        txRectangle (50, 200, 250, 290);

        //Drawing text: "+ Speed"
        txSelectFont ("Arial", 50);
        txDrawText (50, 200, 250, 290, "+ Speed");

        //Drawing button "- Speed"
        txSetFillColor (TX_WHITE);
        txRectangle (50, 310, 250, 400);

        //Drawing text: "- Speed"
        txSelectFont ("Arial", 50);
        txDrawText (50, 310, 250, 400, "- Speed");

        //Drawing button "Color of car"
        txSetFillColor (colorforcar);
        txRectangle (50, 420, 250, 510);

        //Drawing text: "Color of car"
        txSelectFont ("Arial", 40);
        txDrawText (50, 420, 250, 510, "Color of car");

        //Drawing button "Season"
        txSetFillColor (colorforseason);
        txRectangle (50, 530, 250, 620);

        //Drawing button "Exit"
        txSetFillColor (TX_BLACK);
        txRectangle (50, 780, 250, 870);

        //Drawing text: "EXIT"
        txSetColor (TX_WHITE);
        txSelectFont ("Arial", 40);
        txDrawText (50, 780, 250, 870, "EXIT");
        txSetColor (TX_BLACK);

        //Button "Exit"
        if ((50 <= txMouseX()) and (250 >= txMouseX()) and (780 <= txMouseY()) and (870 >= txMouseY()) and (txMouseButtons() & 1))
        {
            GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
        }

        //Button "Season"
        if ((50 <= txMouseX()) and (250 >= txMouseX()) and (530 <= txMouseY()) and (620 >= txMouseY()) and (txMouseButtons() & 1))
        {
            stageforseasons = stageforseasons + 1;
        }

        switch (stageforseasons)
        {
            case (1):
                colorforseason = RGB (0, 128, 0);

                //Drawing text: "Summer"
                txSelectFont ("Arial", 40);
                txDrawText (50, 530, 250, 620, "Summer");
                break;

            case (2):
                colorforseason = RGB (255, 165, 0);

                //Drawing text: "Autumn"
                txSelectFont ("Arial", 40);
                txDrawText (50, 530, 250, 620, "Autumn");
                break;

            case (3):
                colorforseason = RGB (255, 255, 255);

                //Drawing text: "Winter"
                txSelectFont ("Arial", 40);
                txDrawText (50, 530, 250, 620, "Winter");
                break;

            case (4):
                stageforseasons = 1;
                break;
        }



        //Button "STOP"
        if (cartoon == TRUE)
        {
            //Drawing button "STOP"
            txSetFillColor (colorforbuttonSTOP);
            txRectangle (50, 90, 250, 180);

            //Drawing text: "STOP"
            txSelectFont ("Arial", 50);
            txDrawText (50, 90, 250, 180, "STOP");
            if ((50 <= txMouseX()) and (250 >= txMouseX()) and (90 <= txMouseY()) and (180 >= txMouseY()) and (txMouseButtons() & 1))
            {
                cartoon = FALSE;
            }
        }

        else
        {
            //Drawing button "START"
            txSetFillColor (TX_LIGHTGREEN);
            txRectangle (50, 90, 250, 180);

            //Drawing text: "START"
            txSelectFont ("Arial", 50);
            txDrawText (50, 90, 250, 180, "START");
            if ((50 <= txMouseX()) and (250 >= txMouseX()) and (90 <= txMouseY()) and (180 >= txMouseY()) and (txMouseButtons() & 1))
            {
                cartoon = TRUE;
            }
        }

        //Button "Change color"
        if ((50 <= txMouseX()) and (250 >= txMouseX()) and (420 <= txMouseY()) and (510 >= txMouseY()) and (txMouseButtons() & 1))
            {
                numberofcolorcar = numberofcolorcar + 1;
            }

        if (numberofcolorcar == 6)
        {
            numberofcolorcar = 1;
        }

        switch (numberofcolorcar)
        {
            case (1):
                colorforcar = RGB (250, 144, 0);
                break;
            case (2):
                colorforcar = RGB (255, 0, 0);
                break;
            case (3):
                colorforcar = RGB (192, 192, 192);
                break;
            case (4):
                colorforcar = RGB (0, 0, 255);
                break;
            case (5):
                colorforcar = RGB (0, 255, 0);
                break;
        }

        //Button "+Speed"
        if ((50 <= txMouseX()) and (250 >= txMouseX()) and (200 <= txMouseY()) and (290 >= txMouseY()) and (txMouseButtons() & 1))
            {
                if (sleep == 0)
                {
                    MessageBox (txWindow(), "Быстрее сделать нельзя!", "Разработчик сообщает", 0);
                    sleep = sleep + 100;
                }
                else
                {
                    sleep = sleep - 100;
                }
            }

        //Button "-Speed"
        if ((50 <= txMouseX()) and (250 >= txMouseX()) and (310 <= txMouseY()) and (400 >= txMouseY()) and (txMouseButtons() & 1))
            {
                if (sleep == 700)
                {
                    MessageBox (txWindow(), "Медленнее сделать нельзя!", "Разработчик сообщает", 0);
                    sleep = sleep - 100;
                }
                else
                {
                    sleep = sleep + 100;
                }
            }

        txSleep (sleep);

        if (cartoon == TRUE)
        {
            //Animation with car
            if (stageforcar < 2)
            {
                ycar = ycar - 5;
                stageforcar = stageforcar + 1;
            }

            else
            {
                ycar = ycar + 5;
                stageforcar = 1;
            }

            //Animation with strips
            if (stageforstrips < 11)
            {
                xstrip = xstrip - 10;
                stageforstrips = stageforstrips + 1;
            }

            else
            {
                xstrip = xstrip + 100;
                stageforstrips = 1;
            }

            //Animation with trees
            if (stagefortrees < 14)
            {
                xtree = xtree - 9;
                stagefortrees = stagefortrees + 1;
            }

            else
            {
                xtree = xtree + 117;
                stagefortrees = 1;
            }
        }
    }

    return 0;
}

void drawCar (int x, int yw, int y, double m, COLORREF colorforcar)
{
    //BodyArray
    POINT coordBody[39] = {{x-95*m, y+20*m},
                           {x-100*m, y+16*m},
                           {x-150*m, y+16*m},
                           {x-160*m, y+20*m},
                           {x-170*m, y+24*m},
                           {x-180*m, y+30*m},
                           {x-190*m, y+34*m},
                           {x-200*m, y+40*m},
                           {x-210*m, y+50*m},
                           {x-220*m, y+55*m},
                           {x-230*m, y+60*m},
                           {x-235*m, y+70*m},
                           {x-235*m, y+80*m},
                           {x-230*m, y+90*m},
                           {x-220*m, y+90*m},
                           {x-214*m, y+90*m},
                           {x-210*m, y+80*m},
                           {x-204*m, y+74*m},
                           {x-196*m, y+70*m},
                           {x-185*m, y+72*m},
                           {x-180*m, y+77*m},
                           {x-176*m, y+83*m},
                           {x-175*m, y+90*m},
                           {x-168*m, y+90*m},
                           {x-54*m, y+90*m},
                           {x-50*m, y+84*m},
                           {x-46*m, y+78*m},
                           {x-40*m, y+73*m},
                           {x-30*m, y+71*m},
                           {x-24*m, y+74*m},
                           {x-15*m, y+80*m},
                           {x-10*m, y+90*m},
                           {x+10*m, y+90*m},
                           {x+16*m, y+80*m},
                           {x+16*m, y+70*m},
                           {x+10*m, y+60*m},
                           {x-0*m, y+55*m},
                           {x-40*m, y+55*m},
                           {x-70*m, y+55*m}};

    //WindowArray
    POINT coordWindow [4] = {{x-80*m, y+55*m},
                             {x-105*m, y+25*m},
                             {x-150*m, y+25*m},
                             {x-167*m, y+55*m}};

    //FirstHeadlampArray
    POINT coordFirstHeadlamp [6] = {{x+16*m, y+70*m},
                                    {x+5*m, y+70*m},
                                    {x-0*m, y+73*m},
                                    {x-0*m, y+77*m},
                                    {x+5*m, y+80*m},
                                    {x+16*m, y+80*m}};

    //SecondHeadlampArray
    POINT coordSecondHeadlamp [6] = {{x-235*m, y+70*m},
                                     {x-225*m, y+70*m},
                                     {x-220*m, y+73*m},
                                     {x-220*m, y+77*m},
                                     {x-225*m, y+80*m},
                                     {x-235*m, y+80*m}};

    //Body
    txSetFillColor (colorforcar);
    txPolygon (coordBody, 39);
    txLine(x-70*m, y+55*m, x-80*m, y+55*m);
    txLine(x-167*m, y+55*m, x-223*m, y+55*m);
    txLine(x-167*m, y+55*m, x-168*m, y+90*m);
    txLine(x-80*m, y+55*m, x-75*m, y+60*m);
    txLine(x-75*m, y+60*m, x-75*m, y+80*m);
    txLine(x-75*m, y+80*m, x-86*m, y+90*m);
    txLine(x-70*m, y+55*m, x-80*m, y+55*m);
    txLine(x-125*m, y+80*m, x-125*m, y+60*m);
    txLine(x-125*m, y+60*m, x-145*m, y+60*m);
    txLine(x-145*m, y+60*m, x-145*m, y+80*m);
    txLine(x-145*m, y+80*m, x-125*m, y+80*m);
    txLine(x-120*m, y+70*m, x-110*m, y+60*m);
    txLine(x-110*m, y+60*m, x-110*m, y+80*m);
    txLine(x-100*m, y+80*m, x-120*m, y+80*m);

    //Window
    txSetFillColor (TX_LIGHTCYAN);
    txPolygon (coordWindow, 4);
    txLine(x-105*m, y+25*m, x-105*m, y+55*m);

    //FirstHeadlamp
    txSetFillColor (TX_YELLOW);
    txPolygon (coordFirstHeadlamp, 6);

    //SecondHeadlamp
    txSetFillColor (TX_RED);
    txPolygon (coordSecondHeadlamp, 6);

    //FirstWheel
    txSetFillColor (TX_BLACK);
    txCircle (x-31*m, yw+88*m, 17*m);
    txSetFillColor (TX_GRAY);
    txCircle (x-31*m, yw+88*m, 10*m);

    //SecondWheel
    txSetFillColor (TX_BLACK);
    txCircle (x-193*m, yw+86*m, 17*m);
    txSetFillColor (TX_GRAY);
    txCircle (x-193*m, yw+86*m, 10*m);
}

void drawTree (int x, int y, double m, COLORREF colorforseason, COLORREF colorfortrunk)
{
    //TrunkArray
    POINT coordTrunk [6] = {{x+70*m, y+40*m},
                            {x+70*m, y+140*m},
                            {x+66*m, y+150*m},
                            {x+94*m, y+150*m},
                            {x+90*m, y+140*m},
                            {x+90*m, y+40*m}};

    //Trunk
    txSetFillColor (colorfortrunk);
    txPolygon (coordTrunk, 6);

    //Leaves
    txSetFillColor (colorforseason);
    txCircle (x+67*m, y+76*m, 21*m);
    txCircle (x+92*m, y+83*m, 21*m);
    txCircle (x+78*m, y+64*m, 21*m);
    txCircle (x+57*m, y+62*m, 21*m);
    txCircle (x+102*m, y+61*m, 21*m);
    txCircle (x+72*m, y+40*m, 21*m);
    txCircle (x+96*m, y+38*m, 21*m);
    txCircle (x+80*m, y+24*m, 21*m);
    txCircle (x+57*m, y+42*m, 21*m);
}

void drawStrip (int x, int y, double m)
{
    //WhiteStripArray
    POINT coordWhiteStrip [4] = {{x+220*m, y-80*m},
                                 {x+260*m, y-80*m},
                                 {x+250*m, y-70*m},
                                 {x+210*m, y-70*m}};

    //WhiteStrip
    txSetFillColor (TX_WHITE);
    txPolygon (coordWhiteStrip, 4);
}
