template <class T> void HML_RandomIntVectorInElements(T *VHML_ResultVector, T *n, T *m, int VHML_N)
{
/*
Функция заполняет массив случайными целыми  числами из определенного интервала [n_i,m_i). При этом для каждого элемента массива свой интервал изменения.
Входные параметры:
 VHML_ResultVector - указатель на массив;
 n - указатель на массив левых границ интервала;
 m - указатель на массив правых границ интервала;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomUniform(int(n[i]),int(m[i]));
}