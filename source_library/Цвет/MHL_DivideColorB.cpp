int MHL_DivideColorB(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через деление каждого канала на число p. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - во сколько уменьшаем яркость. Число должно быть в интервале [1,256];
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    R = TMHL_AcceptanceLimitsNumber(R,0,255);
    G = TMHL_AcceptanceLimitsNumber(G,0,255);
    B = TMHL_AcceptanceLimitsNumber(B,0,255);
    p = TMHL_AcceptanceLimitsNumber(p,1.,256.);

    //int Rnew=double(R)/p;
    //Rnew = TMHL_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=double(G)/p;
    //Gnew = TMHL_AcceptanceLimitsNumber(Gnew,0,255);
    int Bnew=double(B)/p;
    Bnew = TMHL_AcceptanceLimitsNumber(Bnew,0,255);

    return Bnew;
}