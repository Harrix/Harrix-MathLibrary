int MHL_ColorFromGradientR(double position, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция выдает код канала RGB из градиента от одного цвета к другому цвету согласно позиции от 0 до 1. Выдает значение канала R.
    Входные параметры:
     position - позиция из интервала [0;1], которая говорит какой цвет выдать из градиента;
     R1,G1,B1 - RGB код первого цвета градиента. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента. Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
    position = TMHL_AcceptanceLimitsNumber(position,0.,1.);
    R1 = TMHL_AcceptanceLimitsNumber(R1,0,255);
    G1 = TMHL_AcceptanceLimitsNumber(G1,0,255);
    B1 = TMHL_AcceptanceLimitsNumber(B1,0,255);
    R2 = TMHL_AcceptanceLimitsNumber(R2,0,255);
    G2 = TMHL_AcceptanceLimitsNumber(G2,0,255);
    B2 = TMHL_AcceptanceLimitsNumber(B2,0,255);

    int R=R1+position*(R2-R1);
    //int G=G1+position*(G2-G1);
    //int B=B1+position*(B2-B1);

    return R;
}