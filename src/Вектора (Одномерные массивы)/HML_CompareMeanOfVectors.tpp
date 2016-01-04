template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией HML_WilcoxonW.
*/
    int VHML_Result=0;
    for (int i=0;i<VHML_N;i++)
        if (a[i]!=b[i]) VHML_Result=-1;

    if (VHML_Result==-1)
    {
        double Ma=HML_SumVector(a,VHML_N)/double(VHML_N);
        double Mb=HML_SumVector(b,VHML_N)/double(VHML_N);

        if (Ma>Mb)
            VHML_Result=1;
        else
            VHML_Result=2;
		if (Ma==Mb) VHML_Result=0;
    }

    return VHML_Result;
}
//---------------------------------------------------------------------------
template <class T> int HML_CompareMeanOfVectors(T *a, T *b, int VHML_N1, int VHML_N2)
{
    /*
Функция проверяет, какой вектор по среднему арифметическому больше.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_N1 - размер вектора a;
 VHML_N2 - размер вектора b.
Возвращаемое значение:
 0 - вектора совпадают или совпадает среднее арифметическое;
 1 - первый вектор имеет большее значение арифметического среднего;
 2 - второй вектор имеет большее значение арифметического среднего.
Примечание:
 Данную функцию удобно использовать вкупе с функцией HML_WilcoxonW.
*/
    int VHML_Result=0;
    if (VHML_N1==VHML_N2)
        for (int i=0;i<VHML_N1;i++)
            if (a[i]!=b[i]) VHML_Result=-1;
            else
                VHML_Result=-1;

    if (VHML_Result==-1)
    {
        double Ma=HML_SumVector(a,VHML_N1)/double(VHML_N1);
        double Mb=HML_SumVector(b,VHML_N2)/double(VHML_N2);

        if (Ma>Mb)
            VHML_Result=1;
        else
            VHML_Result=2;
		if (Ma==Mb) VHML_Result=0;
    }

    return VHML_Result;
}