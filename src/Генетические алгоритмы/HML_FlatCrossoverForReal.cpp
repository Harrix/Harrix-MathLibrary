void HML_FlatCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Плоское скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    double a,b;
     for (int i=0;i<VHML_N;i++)
     {
         a = Parent1[i];
         b = Parent2[i];
         if (a>b) HML_NumberInterchange(&a,&b);
         VHML_ResultVector[i]=HML_RandomUniform(a,b);
     }
}