void MHL_RandomRealVector(double *VMHL_ResultVector, double Left, double Right, int VMHL_N)
{
/*
Функция заполняет массив случайными вещественными числами из определенного интервала [Left;Right].
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 Left - левая граница интервала;
 Right - правая граница интервала;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomUniform(Left,Right);
}