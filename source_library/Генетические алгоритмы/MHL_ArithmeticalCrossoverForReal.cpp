void MHL_ArithmeticalCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, double w, int VMHL_N)
{
/*
Равномерное арифметическое скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 w - параметр скрещивания, который означает долю какого-то родителя в потомке: [0;1];
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=MHL_RandomUniformInt(0,2);//0 или 1

    if (w<0) w=0;
    if (w>1) w=1;

    if (k==0)//какой потомок "выживет": первый вариант или второй
     {
     for (i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=w*Parent1[i]+(1.-w)*Parent2[i];
     }
    else
     {
     for (i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=w*Parent2[i]+(1.-w)*Parent1[i];
     }
}