int MHL_GiveRainbowColorB(double position)
{
    /*
    Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала B.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента.
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    position = TMHL_AcceptanceLimitsNumber(position,0.,1.);

    int B=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        B = 0;
        break;
    };
    case 1: {
        B = 0;
        break;
    };
    case 2: {
        B = t;
        break;
    };
    case 3: {
        B = 255;
        break;
    };
    case 4: {
        B = 255;
        break;
    };
    case 5: {
        B = 255 - t;
        break;
    };

    }; // case

    return B;
}