template <class T> void TMHL_AcceptanceLimits(T *VMHL_ResultVector, T *Left, T *Right, int VMHL_N)
{
/*
Функция вмещает вектор VMHL_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 Right - вектор правых границ;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 {
 if (VMHL_ResultVector[i]<Left[i]) VMHL_ResultVector[i]=Left[i];//принятие граничного левого условия
 if (VMHL_ResultVector[i]>Right[i]) VMHL_ResultVector[i]=Right[i];//принятие граничного правого условия
 }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_AcceptanceLimits(T *VMHL_ResultVector, T Left, T Right, int VMHL_N)
{
/*
Функция вмещает вектор VMHL_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - левая граница;
 Right - правая граница;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
 {
 if (VMHL_ResultVector[i]<Left) VMHL_ResultVector[i]=Left;//принятие граничного левого условия
 if (VMHL_ResultVector[i]>Right) VMHL_ResultVector[i]=Right;//принятие граничного правого условия
 }
}