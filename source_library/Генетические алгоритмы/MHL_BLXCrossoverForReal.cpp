void MHL_BLXCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, double alpha, int VMHL_N)
{
/*
BLX скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 alpha - параметр скрещивания: [0;1];
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    double cmin,cmax,I;

    if (alpha<0) alpha=0;
    if (alpha>1) alpha=1;

    for (int i=0;i<VMHL_N;i++)
    {
        cmin=TMHL_Min(Parent1[i],Parent2[i]);
        cmax=TMHL_Max(Parent1[i],Parent2[i]);
        I=cmax-cmin;
        VMHL_ResultVector[i]=MHL_RandomUniform(cmin-I*alpha,cmax+I*alpha);
    }
}