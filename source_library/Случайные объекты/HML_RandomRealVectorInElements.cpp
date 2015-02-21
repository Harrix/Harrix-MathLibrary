void HML_RandomRealVectorInElements(double *VHML_ResultVector, double *Left, double *Right, int VHML_N)
{
/*
Функция заполняет массив случайными вещественными числами из определенного интервала, где на каждую координату свои границы изменения.
Входные параметры:
 VHML_ResultVector - указатель на массив;
 Left - левые границы интервалов (размер VHML_N);
 Right - правые границы интервалов (размер VHML_N)
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniform(Left[i],Right[i]);
}