void HML_TwopointCrossoverForReal(double *Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Двухточечное скрещивание для вещественных векторов.
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
HML_TwopointCrossover(Parent1, Parent2, VHML_ResultVector, VHML_N);
}