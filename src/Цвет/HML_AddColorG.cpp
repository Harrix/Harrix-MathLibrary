int HML_AddColorG(int R, int G, int B, double p)
{
    /*
    Функция увеличивает яркость цвета через прибавление к каждому каналу числа p. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    p - на сколько увеличиваем яркость. Число должно быть в интервале [0,255];
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);
    p = HML_AcceptanceLimitsNumber(p,0.,255.);

    //int Rnew=R+p;
    //Rnew = HML_AcceptanceLimitsNumber(Rnew,0,255);
    int Gnew=G+p;
    Gnew = HML_AcceptanceLimitsNumber(Gnew,0,255);
    //int Bnew=B+p;
    //Bnew = HML_AcceptanceLimitsNumber(Bnew,0,255);

    return Gnew;
}