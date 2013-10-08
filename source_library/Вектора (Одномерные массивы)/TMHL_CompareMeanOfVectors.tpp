template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией MHL_WilcoxonW.
*/
    int VMHL_Result=0;
    for (int i=0;i<VMHL_N;i++)
        if (a[i]!=b[i]) VMHL_Result=-1;

    if (VMHL_Result==-1)
    {
        double Ma=TMHL_SumVector(a,VMHL_N)/double(VMHL_N);
        double Mb=TMHL_SumVector(b,VMHL_N)/double(VMHL_N);

        if (Ma>Mb)
            VMHL_Result=1;
        else
            VMHL_Result=2;
		if (Ma==Mb) VMHL_Result=0;
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> int TMHL_CompareMeanOfVectors(T *a, T *b, int VMHL_N1, int VMHL_N2)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_N1 - размер вектора a;
 VMHL_N2 - размер вектора b.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией MHL_WilcoxonW.
*/
    int VMHL_Result=0;
    if (VMHL_N1==VMHL_N2)
        for (int i=0;i<VMHL_N1;i++)
            if (a[i]!=b[i]) VMHL_Result=-1;
            else
                VMHL_Result=-1;

    if (VMHL_Result==-1)
    {
        double Ma=TMHL_SumVector(a,VMHL_N1)/double(VMHL_N1);
        double Mb=TMHL_SumVector(b,VMHL_N2)/double(VMHL_N2);

        if (Ma>Mb)
            VMHL_Result=1;
        else
            VMHL_Result=2;
		if (Ma==Mb) VMHL_Result=0;
    }

    return VMHL_Result;
}