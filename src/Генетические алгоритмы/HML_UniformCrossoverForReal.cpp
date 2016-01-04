void HML_UniformCrossoverForReal(double*Parent1, double *Parent2, double *VHML_ResultVector, int VHML_N)
{
/*
Равномерное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
HML_UniformCrossover(Parent1, Parent2, VHML_ResultVector, VHML_N);
}