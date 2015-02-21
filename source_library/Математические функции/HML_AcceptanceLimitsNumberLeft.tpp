template <class T> T HML_AcceptanceLimitsNumberLeft(T Number, T Left)
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
    T VHML_Result = Number;

    if (Number<Left) VHML_Result=Left;//принятие граничного левого условия

    return VHML_Result;
}
