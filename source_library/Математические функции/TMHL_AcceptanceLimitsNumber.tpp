template <class T> T TMHL_AcceptanceLimitsNumber(T Number, T Left, T Right)
{
/*
Функция проверяет не выходит ли число за заданные рамки [Left, Right]. Если выходит, то
принимает граничные значения.
Входные параметры:
 Number - проверяемое число;
 Left - левая граница;
 Right - правая граница.
Возвращаемое значение:
 Число в рамках.
*/
    T VMHL_Result = Number;

    if (Number<Left) VMHL_Result=Left;//принятие граничного левого условия
    if (Number>Right) VMHL_Result=Right;//принятие граничного правого условия

    return VMHL_Result;
}