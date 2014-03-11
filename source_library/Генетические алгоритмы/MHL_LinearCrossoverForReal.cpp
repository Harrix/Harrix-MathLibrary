void MHL_LinearCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N)
{
/*
Линейное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=MHL_RandomUniformInt(0,3);//0 или 1

    if (k==0) for (i=0;i<VMHL_N;i++) VMHL_ResultVector[i]= 0.5*Parent1[i]+0.5*Parent2[i];
    if (k==1) for (i=0;i<VMHL_N;i++) VMHL_ResultVector[i]= 1.5*Parent1[i]-0.5*Parent2[i];
    if (k==2) for (i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=-0.5*Parent1[i]+1.5*Parent2[i];
}