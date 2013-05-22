void MHL_RandomRealVectorInElements(double *VMHL_ResultVector, double *Left, double *Right, int VMHL_N)
{
/*
Функция заполняет массив случайными вещественными числами из определенного интервала, где на каждую координату свои границы изменения.
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 Left - левые границы интервалов (размер VMHL_N);
 Right - правые границы интервалов (размер VMHL_N)
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomUniform(Left[i],Right[i]);
}