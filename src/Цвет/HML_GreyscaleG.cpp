int HML_GreyscaleG(int R, int G, int B)
{
    /*
    Функция переводит цвет в серый цвет. Выдает значение канала G.
    Входные параметры:
    R,G,B - RGB код цвета. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее G канал итогового цвета.
    */
    R = HML_AcceptanceLimitsNumber(R,0,255);
    G = HML_AcceptanceLimitsNumber(G,0,255);
    B = HML_AcceptanceLimitsNumber(B,0,255);

    //int Rnew=(R+G+B)/3;
    int Gnew=(R+G+B)/3;
    //int Bnew=(R+G+B)/3;

    return Gnew;
}