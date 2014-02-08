void MHL_UniformCrossoverForReal(double*Parent1, double *Parent2, double *VMHL_ResultVector, int VMHL_N)
{
/*
Равномерное скрещивание для вещественных векторов.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
TMHL_UniformCrossover(Parent1, Parent2, VMHL_ResultVector, VMHL_N);
}