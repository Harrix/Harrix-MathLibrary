int HML_SubtractColorB(int R, int G, int B, double p)
{
    /*
    Функция уменьшает яркость цвета через отнимание от каждого канала числа p. Выдает значение канала B.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько уменьшаем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее B канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    //int Rnew=R-p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    //int Gnew=G-p;
    //Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    int Bnew=B-p;
    Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Bnew;
}