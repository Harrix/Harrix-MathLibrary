template <class T> void HML_RandomIntVector(T *VHML_ResultVector, T n, T m, int VHML_N)
{
/*
Функция заполняет массив случайными целыми числами из определенного интервала [n,m).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 n - левая граница интервала;
 m - правая граница интервала;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniformInt(int(n),int(m));
}