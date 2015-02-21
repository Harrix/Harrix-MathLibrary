int HML_GiveRainbowColorG(double position)
{
    /*
    Функция выдает код канала RGB из градиента радуги для любой позиции от 0 до 1 из этого градиента. Выдает значение канала G.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента.
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    position = HML_AcceptanceLimitsNumber(position,0.,1.);

    int G=0;//

    int nmax=6;// number of color bars
    double m=nmax* position;
    int n=int(m); // integer of m
    double f=m-n;  // fraction of m
    int t=int(f*255);

    switch( n){
    case 0: {
        G = t;
        break;
    };
    case 1: {
        G = 255;
        break;
    };
    case 2: {
        G = 255;
        break;
    };
    case 3: {
        G = 255 - t;
        break;
    };
    case 4: {
        G = 0;
        break;
    };
    case 5: {
        G = 0;
        break;
    };

    }; // case

    return G;
}