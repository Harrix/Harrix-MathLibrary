template <class T> T TMHL_AcceptanceLimitsNumberLeft(T Number, T Left)
{
/*
Функция проверяет не выходит ли число за левую рамку Left. Если выходит, то
принимает граничное значения.
Входные параметры:
 Number - проверяемое число;
 Left - левая граница.
Возвращаемое значение:
 Число в рамках.
*/
    T VMHL_Result = Number;

    if (Number<Left) VMHL_Result=Left;//принятие граничного левого условия

    return VMHL_Result;
}
