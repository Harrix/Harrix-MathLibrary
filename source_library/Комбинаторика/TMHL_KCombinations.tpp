template <class T> T TMHL_KCombinations(T k, T n)
{
/*
Функция возвращает число сочетаний из n по m (без возвращения).
Выходные параметры:
 k - по сколько элементов надо брать в группу;
 n - общее число элементов.
Возвращаемое значение:
 Число сочетаний из n по k.
*/
    if ((k == 0) || (n == k)) return 1;
    if (k>n)  TMHL_NumberInterchange(&n,&k);//n должен быть больше m

    return TMHL_KCombinations(k, n - 1) + TMHL_KCombinations(k - 1, n - 1);
}