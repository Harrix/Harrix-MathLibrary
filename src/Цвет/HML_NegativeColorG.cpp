int HML_NegativeColorG(int R, int G, int B)
{
    /*
    Функция инвертирует цвет. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    //int Rnew=255-R;
    int Gnew=255-G;
    //int Bnew=255-B;

    return Gnew;
}