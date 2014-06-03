template <class T> void TMHL_AcceptanceLimitsRight(T *VMHL_ResultVector, T *Right, int VMHL_N)
{
/*
Если значения вектора VMHL_ResultVector[i] справа выходят за Right[i], то она ограничивается Right[i].
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Right - вектор правых границ;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VMHL_N;i++)
    {
        if (VMHL_ResultVector[i]>Right[i]) VMHL_ResultVector[i]=Right[i];//принятие граничного правого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void TMHL_AcceptanceLimitsRight(T *VMHL_ResultVector, T Right, int VMHL_N)
{
/*
Если значения вектора VMHL_ResultVector[i] справа выходят за Right, то она ограничивается Right.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Right - правая граница;
 VMHL_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VMHL_N;i++)
    {
        if (VMHL_ResultVector[i]>Right) VMHL_ResultVector[i]=Right;//принятие граничного правого условия
    }
}