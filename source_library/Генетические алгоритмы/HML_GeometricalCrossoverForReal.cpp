void HML_GeometricalCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N)
{
/*
Геометрическое скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 w - параметр скрещивания, который означает своеобразную долю какого-то родителя в потомке: [0;1];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
    int i;
    int k=HML_RandomUniformInt(0,2);//0 или 1

    if (w<0) w=0;
    if (w>1) w=1;

    if (k==0)//какой потомок "выживет": первый вариант или второй
     {
     for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=pow(Parent1[i],w)*pow(Parent2[i],1.-w);
     }
    else
     {
     for (i=0;i<VHML_N;i++) VHML_ResultVector[i]=pow(Parent2[i],w)*pow(Parent1[i],1.-w);
     }
}