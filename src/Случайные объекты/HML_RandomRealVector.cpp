void HML_RandomRealVector(double *VHML_ResultVector, double Left, double Right, int VHML_N)
{
/*
Функция заполняет массив случайными вещественными числами из определенного интервала [Left;Right].
Входные параметры:
 VHML_ResultVector - указатель на массив;
 Left - левая граница интервала;
 Right - правая граница интервала;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniform(Left,Right);
}