int MHL_AlphaBlendingColorToColorR(double alpha, int R1, int G1, int B1, int R2, int G2, int B2)
{
    /*
    Функция накладывает сверху на цвет другой цвет с определенной прозрачностью. Выдает значение канала R.
    Входные параметры:
     alpha - прозрачность второго накладываемого цвета из интервала [0;1];
     R1,G1,B1 - RGB код первого цвета градиента, например. Каждый параметр должен быть в интервале [0,255];
     R2,G2,B2 - RGB код второго цвета градиента, например: Каждый параметр должен быть в интервале [0,255].
    Возвращаемое значение:
     Число содержащее R канал итогового цвета.
    */
	alpha = TMHL_AcceptanceLimitsNumber(alpha,0.,1.);
    R1 = TMHL_AcceptanceLimitsNumber(R1,0,255);
    G1 = TMHL_AcceptanceLimitsNumber(G1,0,255);
    B1 = TMHL_AcceptanceLimitsNumber(B1,0,255);
    R2 = TMHL_AcceptanceLimitsNumber(R2,0,255);
    G2 = TMHL_AcceptanceLimitsNumber(G2,0,255);
    B2 = TMHL_AcceptanceLimitsNumber(B2,0,255);

    int R=alpha*R2+(1-alpha)*R1;
    //G=alpha*G2+(1-alpha)*G1;
    //B=alpha*B2+(1-alpha)*B1;

    return R;
}