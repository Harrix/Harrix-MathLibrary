int MHL_MultiplyColorR(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через умножение каждого канала числа на p. Выдает значение канала R.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько увеличиваем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = TMHL_AcceptanceLimitsNumber(R,0,255);
    G = TMHL_AcceptanceLimitsNumber(G,0,255);
    B = TMHL_AcceptanceLimitsNumber(B,0,255);
    p = TMHL_AcceptanceLimitsNumber(p,1.,256.);

    int Rnew=R*p;
    Rnew = TMHL_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G*p;
    //Gnew = TMHL_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B*p;
    //Bnew = TMHL_AcceptanceLimitsNumber(Bnew,0,255);

    return Rnew;
}