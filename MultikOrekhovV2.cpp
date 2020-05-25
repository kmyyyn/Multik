#include "TXLib.h"

void draw_twin(int x, int y, double scale, COLORREF col, double floor, COLORREF pal, short mario);
void draw_krabik(int x, int y, double scale, COLORREF col, double armL, double armR, double legL, double legR, double eye, short claws);
void draw_destroyer(int x, int y, double scale, COLORREF col,COLORREF colcab, COLORREF coleng, double lentheng, short heat);
void draw_bomb(int x, int y, double scale, COLORREF col, double lenth, COLORREF colkr, short bah);
void title();
void introduction();
void culmination();
void draw_plane(int x, int y, double scale, COLORREF col, COLORREF colcabine, double lenthcab,  short terrorism);
void happyend();
void finaltitles();

int main()
{
    title();
    introduction();
    culmination();
    happyend();
    finaltitles();

    return 0;
}

void draw_twin(int x, int y,double scale, COLORREF col, double floor, COLORREF pal, short mario)
{

    double lu = x-100*scale;
    double ld = y-floor*(5*scale);
    if(mario == 1)
    {
        txSetFillColor(col);
        txSetColor(col);
        txRectangle(x-100*scale,y+floor*(5*scale),x+100*scale,y-floor*(5*scale));
        txRectangle(x-10*scale,y-floor*(5*scale),x+10*scale,(y-floor*(5*scale))-100*scale);
        while(lu <= x+100*scale)
        {
            txSetColor(pal);
            txLine(lu,y+floor*(5*scale),lu,y-floor*(5*scale));
            lu += 10*scale;
        }

        while(ld <= y+floor*(5*scale))
        {
            txSetColor(pal);
            txLine(x-100*scale,ld,x+100*scale,ld);
            ld += 10*scale;
        }
    }
    else
    {
        txSetFillColor(TX_WHITE);
        txSetColor(TX_WHITE);
        txRectangle(x-100*scale,y+floor*(5*scale),x+100*scale,y-floor*(5*scale));
        txRectangle(x-10*scale,y-floor*(5*scale),x+10*scale,(y-floor*(5*scale))-100*scale);
    }
}

void draw_krabik(int x, int y, double scale, COLORREF col, double armL, double armR, double legL, double legR, double eye, short claws)
{
    double kr = 30*scale;
    if( claws == 1)
    {
        txSetColor(col,5*scale);
        txSetFillColor(col);
        txCircle(x,y,75*scale);
        txLine(x-100*scale*legL,y+100*scale,x,y);
        txLine(x-190*scale*armL,y,x-75*scale,y);
        txRectangle(x-190*scale*armL,y,x-240*scale*armL,y-20*scale*armL);
        txRectangle(x-190*scale*armL,y,x-170*scale*armL,y+50*scale*armL);
        txLine(x+190*scale*armR,y,x+75*scale,y);
        txLine(x,y,x+100*scale*legR,y+100*scale);
        txRectangle(x+190*scale*armR,y,x+240*scale*armR,y-20*scale*armR);
        txRectangle(x+190*scale*armR,y,x+170*scale*armR,y+50*scale*armR);
        txSetColor(TX_WHITE);
        while(kr >= 20*scale)
        {
             txCircle(eye,y,kr);
             kr -= 1*scale;
        }
        txSetFillColor(TX_WHITE);
        txCircle(eye,y,10*scale);
        }
        else
        {
            txSetColor(col,5*scale);
            txSetFillColor(col);
            txCircle(x,y,75*scale);
            txLine(x-100*scale*legL,y+100*scale,x,y);
            txLine(x-190*scale*armL,y,x-75*scale,y);
            txRectangle(x-190*scale*armL,y,x-240*scale*armL,y+50*scale*armL);
            txRectangle(x-190*scale*armL,y,x-260*scale*armL,y+50*scale*armL);
            txLine(x+190*scale*armR,y,x+75*scale,y);
            txLine(x,y,x+100*scale*legR,y+100*scale);
            txRectangle(x+190*scale*armR,y,x+240*scale*armR,y+50*scale*armR);
            txRectangle(x+190*scale*armR,y,x+260*scale*armR,y+50*scale*armR);
            txSetColor(TX_WHITE);
            while(kr >= 20*scale)
            {
                 txCircle(eye,y,kr);
                 kr -= 1*scale;
            }
            txSetFillColor(TX_WHITE);
            txCircle(eye,y,10*scale);
     }
}

void draw_destroyer(int x, int y,double scale, COLORREF col, COLORREF colcab, COLORREF coleng, double lentheng, short heat)
{
    POINT tr2[3] = {{int(x-100*scale), int(y+10*scale)}, {int(x+100*scale), int(y+40*scale)}, {int(x+100*scale), int(y-20*scale)}};

    txSetFillColor(colcab);
    txSetColor(colcab);
    txCircle(x-50*scale,y+5*scale,13*scale);
    txSetColor(col);
    txSetFillColor(col);
    txPolygon(tr2, 3);
    txSetColor(coleng);
    txSetFillColor(coleng);
    if( heat == 1)
    {
        txSetColor(coleng);
        txSetFillColor(coleng);
        txRectangle(x+100*scale,y+35*scale,x+125*scale*lentheng,y+25*scale);
        txRectangle(x+100*scale,y-15*scale,x+125*scale*lentheng,y-5*scale);
    }
    else
    {
        txSetColor(RGB(207 , 16, 32));
        txSetFillColor(RGB(207 , 16, 32));
        txRectangle(x+100*scale,y+35*scale,x+125*scale*lentheng,y+25*scale);
        txRectangle(x+100*scale,y-15*scale,x+125*scale*lentheng,y-5*scale);
    }
}

void draw_bomb(int x, int y, double scale, COLORREF col, double lenth, COLORREF colkr, short bah)
{

    POINT tr[3] = {{x+ int(80*scale*lenth), y}, {int(x+120*scale*lenth), y-int(25*scale)}, {int(x+ 120*scale*lenth), int(y+ 25*scale)}};
    POINT babah[16] = {{ x+100, y}, {x+60, y+5}, {x+100, y+50}, {x+55, y+10}, {x+50 , y+50}, { x+45, y+5}, {x, y+50}, {x+40, y+5}, {x , y}, {x+40 , y-5}, {x , y-50}, {x+45 , y-10}, {x+50 , y-50}, {x+55 , y-10}, {x+100 , y-50}, {x+60 , y-5}};

    if( bah == 1)
    {
        txSetColor(col);
        txSetFillColor(col);
        txEllipse(x,y+25*scale,x+100*scale*lenth,y-25*scale);
        txPolygon(tr, 3);
        txSetColor(colkr,2.5*scale);
        txSetFillColor(col);
        txCircle(x+50*scale*lenth,y,20*scale);
        txCircle(x+50*scale*lenth,y,15*scale);
        txCircle(x+50*scale*lenth,y,10*scale);
        txCircle(x+50*scale*lenth,y,5*scale);
    }
    else
    {
        txSetFillColor(RGB(250, 255, 0));
        txSetColor(TX_RED,5);
        txPolygon(babah, 16);
    }
}

void title()
{
     txPlaySound ("ruin.wav");

     txCreateWindow(1280,800);
     txSetFillColor(TX_BLACK);
     txClear();
     txSetFillColor(TX_WHITE);
     txSelectFont ("Comic Sans MS", 100);
     txTextOut (200, 200, "Представляю вам фильм");
     txTextOut (400, 400, "Под названием");
     txTextOut (300, 600, "Жизнь башен-близнецов");
     txSleep(5000);
}

void introduction()
{
    short wsahf = 0;
    short delen = 0;
    int dest = 1280;
    double glaz = 600;
    int bomba;

    txBegin();

    txSetFillColor(RGB(0,191,255));
    txClear();

    txPlaySound ("krabik.wav");

    for(wsahf = 0; wsahf < 10; wsahf ++)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        delen = wsahf%2;
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_krabik(600, 250, 1, TX_RED, 1, 1, 1, 1, 600, delen);
        txSleep(1000);
    }

    txPlaySound (NULL);
    txPlaySound ("megalovania.wav");

    for(dest = 1280; dest > 800; dest -= 3, glaz += 0.3)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        draw_destroyer(dest, 150, 1, TX_GREEN, TX_BLUE, TX_BLACK, 1, 1);
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_krabik(600, 250, 1, TX_RED, 1, 1, 1, 1, glaz, 2);
        txSleep(15);
    }

    for( bomba = 200; bomba < 250; bomba ++)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        draw_bomb(800 ,bomba, 0.5, TX_BLACK, 2, TX_GREEN, 1);
        draw_destroyer(800, 150, 1, TX_GREEN, TX_BLUE, TX_BLACK, 1, 2);
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_krabik(600, 250, 1, TX_RED, 1, 1, 1, 1, 650, 2);
        txSleep(40);
    }

    for( int bombx = 800; bombx > 650; bombx --)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        draw_bomb(bombx, 250, 0.5, TX_BLACK, 2, TX_GREEN, 1);
        draw_destroyer(800, 150, 1, TX_GREEN, TX_BLUE, TX_BLACK, 1, 2);
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_krabik(600, 250, 1, TX_RED, 1, 1, 1, 1, 650, 2);
        txSleep(20);
    }
    txSetFillColor(RGB(0,191,255));
    txClear();
    draw_bomb(650, 250, 0.5, TX_BLACK, 2, TX_GREEN, 2);
    draw_destroyer(800, 150, 1, TX_GREEN, TX_BLUE, TX_BLACK, 1, 2);
    draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
    draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
    draw_krabik(600, 250, 1, TX_RED, 1, 1, 1, 1, 650, 2);
    txSleep(1000);
    txSetFillColor(RGB(0,191,255));
    txClear();

    txPlaySound (NULL);
    txPlaySound ("grustno.wav");

    for( int destx = 800; destx >  600; destx -= 2)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        draw_destroyer( destx, 150, 1, TX_GREEN, TX_BLUE, TX_BLACK, 1, 2);
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        txSleep(10);
    }

    for(int desty = 150; desty < 1000; desty += 10)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        draw_destroyer( 600, desty , 1, TX_GREEN, TX_BLUE, TX_BLACK, 1, 2);
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        txSleep(10);
    }

    txPlaySound (NULL);

    txEnd();

}

void draw_plane(int x, int y, double scale, COLORREF col, COLORREF colcabine, double lenthcab,  short terrorism)
{
    POINT tr3[3] = {{x+int(100*scale), y+int(75*scale)}, {x+int(100*scale), y+int(100*scale)}, {x+int(150*scale*lenthcab), y+int(100*scale)}};
    POINT tr4[3] = {{x+int(100*scale), y+int(80*scale)}, {x+int(100*scale), y+int(95*scale)}, {x+int(140*scale*lenthcab), y+int(99*scale)}};
    POINT ch[4] = {{x-int(50*scale), y+int(50*scale)}, {x-int(50*scale), y+int(75*scale)}, {x-int(25*scale), y+int(75*scale)}, {x-int(35*scale), y+int(50*scale)}};
    POINT ch2[4] = {{x+int(75*scale), y+int(75*scale)}, {x+int(50*scale), y+int(75*scale)}, {x+int(25*scale), y+int(25*scale)}, {x+int(50*scale), y+int(25*scale)}};
    POINT babah[16] = {{ x+100, y}, {x+60, y+5}, {x+100, y+50}, {x+55, y+10}, {x+50 , y+50}, { x+45, y+5}, {x, y+50}, {x+40, y+5}, {x , y}, {x+40 , y-5}, {x , y-50}, {x+45 , y-10}, {x+50 , y-50}, {x+55 , y-10}, {x+100 , y-50}, {x+60 , y-5}};

    if( terrorism == 0)
    {
        txSetColor(col);
        txSetFillColor(col);
        txRectangle(x+100*scale,y+100*scale,x-50*scale,y+75*scale);
        txPolygon(tr3, 3);
        txSetFillColor(colcabine);
        txPolygon(tr4, 3);
        txSetFillColor(col);
        txPolygon(ch, 4);
        txPolygon(ch2, 4);
    }
    else
    {
        txSetColor(TX_RED, 5);
        txSetFillColor(RGB(250, 255, 0));
        txPolygon(babah, 16);
    }
}


void culmination()
{
    short delen1 = 0;
    int floor = 50;

    txBegin();

    txPlaySound("plane.wav");

    for(int planex = 0; planex<1140; planex += 5)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        draw_plane(planex, 400, 1, TX_WHITE, TX_LIGHTBLUE, 1, 0);
        draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
        txSleep(10);
    }

    txSetFillColor(RGB(0,191,255));
    txClear();
    draw_plane(1140, 400, 1, TX_WHITE, TX_LIGHTBLUE, 1, 1);
    draw_twin(400, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
    draw_twin(800, 600, 1, RGB(104,108,94), 50, TX_BLACK, 1);
    txSleep(1250);
    txSetFillColor(RGB(0,191,255));
    txClear();
    for(short marioo = 0; marioo < 10; marioo ++)
    {
        txSetFillColor(RGB(0,191,255));
        txClear();
        delen1 = marioo%2;
        floor -= 5;
        draw_twin(400, 600, 1, RGB(104,108,94), floor, TX_BLACK, delen1);
        draw_twin(800, 600, 1, RGB(104,108,94), floor, TX_BLACK, delen1);
        txSleep(500);
    }
    txSetFillColor(RGB(0,191,255));
    txClear();

    txPlaySound(NULL);

    txEnd();
}

void happyend()
{
    int happyy = 100;

    txPlaySound("end.wav");

    for(int happyx = 100; happyx < 1300; happyx += 50, happyy += 50)
    {
        draw_krabik(happyx, happyy, 1, TX_RED, 1, 1, 1, 1, happyx, 1);
    }
    txSleep(1000);
}

void finaltitles()
{
     txSetFillColor(TX_WHITE);
     txSelectFont ("Comic Sans MS", 50);
     txTextOut (200, 100, "В этом фильме пострадали");
     txTextOut (200, 150, "- Огромный краб хрен пойми откуда");
     txTextOut (200, 200, "- Истребитель, который оказался браком");
     txTextOut (200, 250, "- Самолет террористов(может это хорошо)");
     txTextOut (200, 300, "- Башни - близнецы. Опять");
 }
