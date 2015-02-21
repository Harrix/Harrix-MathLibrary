template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T *Left, T *Right, int VHML_N)
{
/*
Функция вмещает вектор VHML_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 Right - вектор правых границ;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 {
 if (VHML_ResultVector[i]<Left[i]) VHML_ResultVector[i]=Left[i];//принятие граничного левого условия
 if (VHML_ResultVector[i]>Right[i]) VHML_ResultVector[i]=Right[i];//принятие граничного правого условия
 }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimits(T *VHML_ResultVector, T Left, T Right, int VHML_N)
{
/*
Функция вмещает вектор VHML_ResultVector в прямоугольную многомерной области,
определяемой левыми границами и правыми границами. Если какая-то координата
вектора выходит за границу, то значение этой координаты принимает граничное значение.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - левая граница;
 Right - правая граница;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
 {
 if (VHML_ResultVector[i]<Left) VHML_ResultVector[i]=Left;//принятие граничного левого условия
 if (VHML_ResultVector[i]>Right) VHML_ResultVector[i]=Right;//принятие граничного правого условия
 }
}