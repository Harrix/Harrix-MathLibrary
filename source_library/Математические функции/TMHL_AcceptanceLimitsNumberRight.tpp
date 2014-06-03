template <class T> T TMHL_AcceptanceLimitsNumberRight(T Number, T Right)
{
/*
Функция проверяет не выходит ли число за правую рамку Right. Если выходит, то
принимает граничное значения.
Входные параметры:
 Number - проверяемое число;
 Right - правая граница.
Возвращаемое значение:
 Число в рамках.
*/
    T VMHL_Result = Number;

    if (Number>Right) VMHL_Result=Right;//принятие граничного правого условия

    return VMHL_Result;
}