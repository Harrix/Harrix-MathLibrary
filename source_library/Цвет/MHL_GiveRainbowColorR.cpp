int MHL_GiveRainbowColorR(double position)
{
    /*
    Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала R.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента.
    Возвращаемое значение:
     Строка содержащая R канал итогового цвета.
    */
    position = TMHL_AcceptanceLimitsNumber(position,0.,1.);

    int R=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        R = 255;
        break;
    };
    case 1: {
        R = 255 - t;
        break;
    };
    case 2: {
        R = 0;
        break;
    };
    case 3: {
        R = 0;
        break;
    };
    case 4: {
        R = t;
        break;
    };
    case 5: {
        R = 255;
        break;
    };

    }; // case

    return R;
}