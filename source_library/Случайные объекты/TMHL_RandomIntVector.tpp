template <class T> void TMHL_RandomIntVector(T *VMHL_ResultVector, T n, T m, int VMHL_N)
{
/*
Функция заполняет массив случайными целыми числами из определенного интервала [n,m).
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 n - левая граница интервала;
 m - правая граница интервала;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomUniformInt(int(n),int(m));
}