void MHL_FlatCrossoverForReal(double *Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N)
{
/*
Плоское скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    double a,b;
     for (int i=0;i<VMHL_N;i++)
     {
         a = Parent1[i];
         b = Parent2[i];
         if (a>b) TMHL_NumberInterchange(&a,&b);
         VMHL_ResultVector[i]=MHL_RandomUniform(a,b);
     }
}