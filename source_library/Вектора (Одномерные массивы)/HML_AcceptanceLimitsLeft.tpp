template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T *Left, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] слева выходят за Left[i], то она ограничивается Left[i].
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - вектор левых границ;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]<Left[i]) VHML_ResultVector[i]=Left[i];//принятие граничного левого условия
    }
}
//---------------------------------------------------------------------------
template <class T> void HML_AcceptanceLimitsLeft(T *VHML_ResultVector, T Left, int VHML_N)
{
/*
Если значения вектора VHML_ResultVector[i] слева выходят за Left, то она ограничивается Left.
Входные параметры:
 VHML_ResultVector - указатель на вектор (в него же записывается "исправленный вектор");
 Left - левая граница;
 VHML_N - размерность вектора.
Возвращаемое значение:
 Отсутствует.
*/
    for (int i=0;i<VHML_N;i++)
    {
        if (VHML_ResultVector[i]<Left) VHML_ResultVector[i]=Left;//принятие граничного левого условия
    }
}