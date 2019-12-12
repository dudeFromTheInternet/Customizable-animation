#include "TXlib.h"
#include <stdlib.h>

int main()
{
    txCreateWindow(1200, 550);
    txSetColor(TX_WHITE);
    txClear();
    txSetColor(TX_BLACK);

    int firstPlayerField[8][8];
    int secondPlayerField[8][8];
    int xFirstPlayer = 100, yFirstPlayer = 100, xSecondPlayer = 700, ySecondPlayer = 100, xStart = 500, yStart = 220, xExit = 500, yExit = 350, stage = 1, shipsPlayer = 0, player = 0, score1player = 0, score2player = 0, game = 0, randomnumberX, randomnumberY;
    COLORREF colorForDiedShip = RGB (255, 0, 0);
    bool bot = FALSE;
    const string textStart = "Все готово, можем начинать!", three = "3", two = "2", one = "1", textFinish = "Начинаем!";

    while (1==1)
    {
        txClear();

        if (game == 0)
        {
            for (int j=0; j < 8; j++)
            {
                for (int i=0; i < 8; i++)
                {
                    firstPlayerField[j][i] = 0;
                    secondPlayerField[j][i] = 0;
                }
            }

            txSelectFont("Calibri", 90);
            txDrawText(0, 85, 1200, 165, "Морской бой", DT_CENTER);

            txRectangle(xStart, yStart, xStart + 200, yStart + 100);
            txSelectFont("Calibri", 70);
            txDrawText(xStart, yStart, xStart+200, yStart+100, "START");

            txRectangle(xExit, yExit, xExit + 200, yExit + 100);
            txSelectFont("Calibri", 70);
            txDrawText(xExit, yExit, xExit+200, yExit+100, "EXIT");

            if ((xStart<=txMouseX()) and (txMouseX()<=(xStart + 200)) and (yStart<=txMouseY()) and (txMouseY()<=(yStart + 100)) and (txMouseButtons() & 1))
            {
                game = 1;
                txSleep (80);
                txClear();
            }

            if ((xExit<=txMouseX()) and (txMouseX()<=(xExit + 200)) and (yExit<=txMouseY()) and (txMouseY()<=(yExit + 100)) and (txMouseButtons() & 1))
            {
                GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
            }

        }

        if (game == 1)
        {
            txSelectFont("Calibri", 80);
            txDrawText(0, 85, 1200, 165, "Выберите режим игры", DT_CENTER);

            txRectangle(xStart, yStart, xStart + 200, yStart + 100);
            txSelectFont("Calibri", 70);
            txDrawText(xStart, yStart, xStart+200, yStart+100, "2 PLAYERS");

            txRectangle(xExit, yExit, xExit + 200, yExit + 100);
            txSelectFont("Calibri", 70);
            txDrawText(xExit, yExit, xExit+200, yExit+100, "BOT");

            if((xStart<=txMouseX()) and (txMouseX()<=(xStart + 200)) and (yStart<=txMouseY()) and (txMouseY()<=(yStart + 100)) and (txMouseButtons() & 1))
            {
                game = 2;
                txClear();
            }

            if((xExit<=txMouseX()) and (txMouseX()<=(xExit + 200)) and (yExit<=txMouseY()) and (txMouseY()<=(yExit + 100)) and (txMouseButtons() & 1))
            {
                bot = TRUE;
                game = 2;
                txClear();
            }
        }

        if (game == 2)
        {
            for (int j=0; j < 8; j++)
            {
                for (int i=0; i < 8; i++)
                {
                    txRectangle(xFirstPlayer, yFirstPlayer, xFirstPlayer + 40, yFirstPlayer + 40);

                    if ((firstPlayerField[j][i] == 1) or (firstPlayerField[j][i] == 4) or (firstPlayerField[j][i] == 5))
                    {
                        if (firstPlayerField[j][i] == 5)
                        {
                            txSetColor(colorForDiedShip);
                        }
                        txLine(xFirstPlayer, yFirstPlayer, xFirstPlayer + 40, yFirstPlayer + 40);
                        txLine(xFirstPlayer + 40, yFirstPlayer, xFirstPlayer, yFirstPlayer + 40);
                        txSetColor(TX_BLACK);
                    }

                    xFirstPlayer = xFirstPlayer + 45;
                }
                yFirstPlayer = yFirstPlayer + 45;
                xFirstPlayer = xFirstPlayer - (45*8);
            }
            yFirstPlayer = yFirstPlayer - (45*8);

            for (int j=0; j < 8; j++)
            {
                for (int i=0; i < 8; i++)
                {
                    txRectangle(xSecondPlayer, ySecondPlayer, xSecondPlayer + 40, ySecondPlayer + 40);

                    if ((secondPlayerField[j][i] == 1) or (secondPlayerField[j][i] == 4) or (secondPlayerField[j][i] == 5))
                    {
                        if(secondPlayerField[j][i] == 5)
                        {
                            txSetColor(colorForDiedShip);
                        }
                        txLine(xSecondPlayer, ySecondPlayer, xSecondPlayer + 40, ySecondPlayer + 40);
                        txLine(xSecondPlayer + 40, ySecondPlayer, xSecondPlayer, ySecondPlayer + 40);
                        txSetColor(TX_BLACK);
                    }

                    xSecondPlayer = xSecondPlayer + 45;
                }
                ySecondPlayer = ySecondPlayer + 45;
                xSecondPlayer = xSecondPlayer - (45*8);
            }
            ySecondPlayer = ySecondPlayer - (45*8);

            if (player == 1)
            {
                txSelectFont("Calibri", 40);
                txDrawText(450, 25, 700, 75, "Ходит 1 игрок");

                for (int j=0; j < 8; j++)
                {
                    for (int i=0; i < 8; i++)
                    {
                        if ((xSecondPlayer<=txMouseX()) and (txMouseX()<=(xSecondPlayer + 40)) and (ySecondPlayer<=txMouseY()) and (txMouseY()<=(ySecondPlayer + 40)) and (txMouseButtons() & 1) and ((secondPlayerField[j][i] == 0) or (secondPlayerField[j][i] == 3)))
                        {
                            if (secondPlayerField[j][i] == 0)
                            {
                                secondPlayerField[j][i] = 4;

                                txSelectFont("Calibri", 40);
                                txDrawText(610, 25, 1150, 75, "Мимо!");
                                txSleep(500);

                                player = 2;
                            }

                            if (secondPlayerField[j][i] == 3)
                            {
                                secondPlayerField[j][i] = 5;

                                txSelectFont("Calibri", 40);
                                txDrawText(610, 25, 1150, 75, "В точку!");
                                txSleep(500);

                                score1player = score1player + 1;
                                player = 2;
                            }
                        }
                        xSecondPlayer = xSecondPlayer + 45;
                    }
                        ySecondPlayer = ySecondPlayer + 45;
                        xSecondPlayer = xSecondPlayer - (45*8);
                }
                ySecondPlayer = ySecondPlayer - (45*8);
            }

            if (player == 2)
            {
                if (bot)
                {
                    txSetColor(TX_WHITE);
                    txSetFillColor(TX_WHITE);
                    txRectangle(450, 25, 700, 75);
                    txRectangle(610, 25, 1150, 75);

                    txSetColor(TX_BLACK);
                    txSelectFont ("Calibri", 40);
                    txDrawText(450, 25, 700, 75, "Ходит бот");

                    randomnumberX = 0 + rand() %7;
                    randomnumberY = 0 + rand() %7;

                    if (firstPlayerField[randomnumberX][randomnumberY] == 0)
                    {
                    firstPlayerField[randomnumberX][randomnumberY] = 4;

                    txSelectFont("Calibri", 40);
                    txDrawText(50, 25, 500, 75, "Бот промазал!");
                    txSleep(500);

                    player = 1;
                    }


                    if (firstPlayerField[randomnumberX][randomnumberY] == 3)
                    {
                    firstPlayerField[randomnumberX][randomnumberY] = 5;

                    txSelectFont("Calibri", 40);
                    txDrawText(50, 25, 500, 75, "Бот попал!");
                    txSleep(500);

                    score2player = score2player + 1;
                    player = 1;
                    }
                }

                else
                {
                    txSelectFont ("Calibri", 40);
                    txDrawText(450, 25, 700, 75, "Ходит 2 игрок");

                    for (int j=0; j < 8; j++)
                    {
                        for (int i=0; i < 8; i++)
                        {
                            if ((xFirstPlayer<=txMouseX()) and (txMouseX()<=(xFirstPlayer + 40)) and (yFirstPlayer<=txMouseY()) and (txMouseY()<=(yFirstPlayer + 40)) and (txMouseButtons() & 1) and ((firstPlayerField[j][i] == 0) or (firstPlayerField[j][i] == 3)))
                            {
                                if (firstPlayerField[j][i] == 0)
                                {
                                firstPlayerField[j][i] = 4;

                                txSelectFont("Calibri", 40);
                                txDrawText(50, 25, 500, 75, "Мимо!");
                                txSleep(500);

                                player = 1;
                            }

                                if (firstPlayerField[j][i] == 3)
                                {
                                firstPlayerField[j][i] = 5;

                                txSelectFont("Calibri", 40);
                                txDrawText(50, 25, 500, 75, "В точку!");
                                txSleep(500);

                                score2player = score2player + 1;
                                player = 1;
                            }
                            }
                            xFirstPlayer = xFirstPlayer + 45;
                        }
                            yFirstPlayer = yFirstPlayer + 45;
                            xFirstPlayer = xFirstPlayer - (45*8);
                    }
                    yFirstPlayer = yFirstPlayer - (45*8);
                }
            }

            if (score1player == 4)
            {
                txClear();

                if(bot)
                {
                    if(txMessageBox ("Начнем игру заново?", "Ты победил!", MB_YESNO) == IDYES)
                    {
                        stage = 1;
                        game = FALSE;
                        score1player = 0;
                        score2player = 0;
                        player = 0;
                    }
                    else
                    {
                        GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
                    }
                }


                else
                {
                    if(txMessageBox ("Начнем игру заново?", "Победил 1 игрок!", MB_YESNO) == IDYES)
                    {
                        stage = 1;
                        game = FALSE;
                        score1player = 0;
                        score2player = 0;
                        player = 0;
                    }
                    else
                    {
                        GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
                    }
                }
            }

            if (score2player == 4)
            {
                txClear();

                if(bot)
                {
                    if(txMessageBox ("Начнем игру заново?", "Победил бот!", MB_YESNO) == IDYES)
                    {
                        stage = 1;
                        game = FALSE;
                        score1player = 0;
                        score2player = 0;
                        player = 0;
                    }
                    else
                    {
                        GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
                    }
                }


                else
                {
                    if(txMessageBox ("Начнем игру заново?", "Победил 2 игрок!", MB_YESNO) == IDYES)
                    {
                        stage = 1;
                        game = FALSE;
                        score1player = 0;
                        score2player = 0;
                        player = 0;
                    }
                    else
                    {
                        GenerateConsoleCtrlEvent(CTRL_BREAK_EVENT,0);
                    }
                }
            }

            if (stage == 1)
            {

                    if (bot)
                    {
                    txSelectFont("Calibri", 40);
                    txDrawText(65, 25, 500, 75, "Расставь 4 корабля");
                    }

                    else
                    {
                    txSelectFont("Calibri", 40);
                    txDrawText(70, 25, 500, 75, "1 игрок должен расставить 4 корабля");
                    }

                    for (int j=0; j < 8; j++)
                    {
                        for (int i=0; i < 8; i++)
                        {
                            if ((xFirstPlayer<=txMouseX()) and (txMouseX()<=(xFirstPlayer + 40)) and (yFirstPlayer<=txMouseY()) and (txMouseY()<=(yFirstPlayer + 40)) and (txMouseButtons() & 1) and (firstPlayerField[j][i] == 0))
                            {
                                shipsPlayer = shipsPlayer + 1;
                                firstPlayerField[j][i] = 1;
                            }
                            xFirstPlayer = xFirstPlayer + 45;
                        }
                        yFirstPlayer = yFirstPlayer + 45;
                        xFirstPlayer = xFirstPlayer - (45*8);
                    }
                    yFirstPlayer = yFirstPlayer - (45*8);

                    if (shipsPlayer == 4)
                    {
                        stage = stage + 1;
                        shipsPlayer = shipsPlayer - 4;
                    }

            }

            if (stage == 2)
            {
                for (int j=0; j < 8; j++)
                {
                    for (int i=0; i < 8; i++)
                        {
                            if (firstPlayerField[j][i] == 1)
                            {
                                firstPlayerField[j][i] = 3;
                            }
                        }
                }

                if(bot)
                {
                    for(int i=0; i < 5; i++)
                    {
                        randomnumberX = 0 + rand() %7;
                        randomnumberY = 0 + rand() %7;

                        if(secondPlayerField[randomnumberX][randomnumberY] == 0)
                        {
                            secondPlayerField[randomnumberX][randomnumberY] = 1;
                        }
                    }

                    stage = stage + 1;
                    shipsPlayer = 5;
                }

                else
                {

                    txSelectFont("Calibri", 40);
                    txDrawText(650, 25, 1150, 75, "Теперь 2 игрок должен расставить 4 корабля");

                    for (int j=0; j < 8; j++)
                        {
                        for (int i=0; i < 8; i++)
                        {
                            if ((xSecondPlayer<=txMouseX()) and (txMouseX()<=(xSecondPlayer + 40)) and (ySecondPlayer<=txMouseY()) and (txMouseY()<=(ySecondPlayer + 40)) and (txMouseButtons() & 1) and (secondPlayerField[j][i] == 0))
                            {
                                shipsPlayer = shipsPlayer + 1;
                                secondPlayerField[j][i] = 1;
                            }

                            xSecondPlayer = xSecondPlayer + 45;
                        }
                            ySecondPlayer = ySecondPlayer + 45;
                            xSecondPlayer = xSecondPlayer - (45*8);
                    }
                    ySecondPlayer = ySecondPlayer - (45*8);

                    if (shipsPlayer == 4)
                    {
                        stage = stage + 1;
                        shipsPlayer = shipsPlayer + 1;
                    }
                }
            }

            if (stage == 3)
            {
                for (int j=0; j < 8; j++)
                {
                    for (int i=0; i < 8; i++)
                    {
                        if (secondPlayerField[j][i] == 1)
                        {
                            secondPlayerField[j][i] = 3;
                        }
                    }
                }
                /*TODO:
                txClear();
                for (int i; i < 6; i++)
                {
                    txSelectFont("Calibri", 40);
                    if (shipsPlayer == 5)
                    {
                        txDrawText(0, 205, 1200, 245, textStart.c_str(), DT_CENTER);
                    }

                     if (shipsPlayer == 4)
                    {
                        txDrawText(0, 205, 1200, 245, three.c_str(), DT_CENTER);
                    }

                     if (shipsPlayer == 3)
                    {
                        txDrawText(0, 205, 1200, 245, two.c_str(), DT_CENTER);
                    }

                     if (shipsPlayer == 2)
                    {
                        txDrawText(0, 205, 1200, 245, one.c_str(), DT_CENTER);
                    }

                     if (shipsPlayer == 1)
                    {
                        txDrawText(0, 205, 1200, 245, textFinish.c_str(), DT_CENTER);
                    }
                    txSleep(700);
                    txClear();
                    shipsPlayer = shipsPlayer - 1;
                }
                player = 1;
                */
                if (shipsPlayer == 5)
                {
                    txClear();
                    txSelectFont("Calibri", 40);
                    txDrawText(0, 205, 1200, 245, textStart.c_str(), DT_CENTER);
                    txSleep(700);
                    txClear();
                    shipsPlayer = shipsPlayer - 1;
                }

                if (shipsPlayer == 4)
                {
                    txSelectFont("Calibri", 40);
                    txDrawText(0, 205, 1200, 245, three.c_str(), DT_CENTER);
                    txSleep(700);
                    txClear();
                    shipsPlayer = shipsPlayer - 1;
                }

                if (shipsPlayer == 3)
                {
                    txSelectFont("Calibri", 40);
                    txDrawText(0, 205, 1200, 245, two.c_str(), DT_CENTER);
                    txSleep(700);
                    txClear();
                    shipsPlayer = shipsPlayer - 1;
                }

                if (shipsPlayer == 2)
                {
                    txSelectFont("Calibri", 40);
                    txDrawText(0, 205, 1200, 245, one.c_str(), DT_CENTER);
                    txSleep(700);
                    txClear();
                    shipsPlayer = shipsPlayer - 1;
                }

                if (shipsPlayer == 1)
                {
                    txSelectFont("Calibri", 40);
                    txDrawText(0, 205, 1200, 245, textFinish.c_str(), DT_CENTER);
                    txSleep(700);
                    txClear();
                    shipsPlayer = shipsPlayer - 1;
                    player = 1;
                }
            }
        }

        txSleep (60);
    }

    return 0;
}
