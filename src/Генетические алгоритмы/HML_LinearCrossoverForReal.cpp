void HML_LinearCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Линейное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=HML_RandomUniformInt(0,3);//0 или 1

    if (k==0) for (i=0;i<VHML_N;i++) VHML_ResultVector[i]= 0.5*Parent1[i]+0.5*Parent2[i];
    if (k==1) for (i=0;i<VHML_N;i++) VHML_ResultVector[i]= 1.5*Parent1[i]-0.5*Parent2[i];
    if (k==2) for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=-0.5*Parent1[i]+1.5*Parent2[i];
}