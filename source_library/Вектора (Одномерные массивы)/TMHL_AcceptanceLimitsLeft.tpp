template <class T> void TMHL_AcceptanceLimitsLeft(T *VMHL_ResultVector, T *Left, int VMHL_N)
{
/*
Если значения вектора VMHL_ResultVector[i] слева выходят за Left[i], то она ограничивается Left[i].
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VMHL_N;i++)
    {
        if (VMHL_ResultVector[i]<Left[i]) VMHL_ResultVector[i]=Left[i];//принятие граничного левого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_AcceptanceLimitsLeft(T *VMHL_ResultVector, T Left, int VMHL_N)
{
/*
Если значения вектора VMHL_ResultVector[i] слева выходят за Left, то она ограничивается Left.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - левая граница;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VMHL_N;i++)
    {
        if (VMHL_ResultVector[i]<Left) VMHL_ResultVector[i]=Left;//принятие граничного левого условия
    }
}