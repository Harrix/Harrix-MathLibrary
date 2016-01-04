template <class T> T HML_KCombinations(T k, T n)
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
    if (k>n)  HML_NumberInterchange(&n,&k);//n должен быть больше m

    return HML_KCombinations(k, n - 1) + HML_KCombinations(k - 1, n - 1);
}