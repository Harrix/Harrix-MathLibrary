template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T *Right, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] справа выходят за Right[i], то она ограничивается Right[i].
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Right - вектор правых границ;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]>Right[i]) VHML_ResultVector[i]=Right[i];//принятие граничного правого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimitsRight(T *VHML_ResultVector, T Right, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] справа выходят за Right, то она ограничивается Right.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Right - правая граница;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]>Right) VHML_ResultVector[i]=Right;//принятие граничного правого условия
    }
}