void HML_BLXCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double alpha, int VHML_N)
{
/*
BLX скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 alpha - параметр скрещивания: [0;1];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    double cmin,cmax,I;

    if (alpha<0) alpha=0;
    if (alpha>1) alpha=1;

    for (int i=0;i<VHML_N;i++)
    {
        cmin=HML_Min(Parent1[i],Parent2[i]);
        cmax=HML_Max(Parent1[i],Parent2[i]);
        I=cmax-cmin;
        VHML_ResultVector[i]=HML_RandomUniform(cmin-I*alpha,cmax+I*alpha);
    }
}