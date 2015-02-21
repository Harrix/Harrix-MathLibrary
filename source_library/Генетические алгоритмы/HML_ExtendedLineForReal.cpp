void HML_ExtendedLineForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, double w, int VHML_N)
{
/*
Расширенное линейчатое скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 w - параметр скрещивания, который означает долю второго родителя в потомке: [-0.25;1.25];
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок только один.
*/
    if (w<-0.25) w=-0.25;
    if (w> 1.25) w= 1.25;

    for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i]+w*(Parent2[i]-Parent1[i]);
}