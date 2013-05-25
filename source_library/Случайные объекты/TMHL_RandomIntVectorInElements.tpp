template <class T> void TMHL_RandomIntVectorInElements(T *VMHL_ResultVector, T *n, T *m, int VMHL_N)
{
/*
Функция заполняет массив случайными целыми  числами из определенного интервала [n_i,m_i). При этом для каждого элемента массива свой интервал изменения.
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 n - указатель на массив левых границ интервала;
 m - указатель на массив правых границ интервала;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomUniform(int(n[i]),int(m[i]));
}