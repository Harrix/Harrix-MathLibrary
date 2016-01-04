template <class T> void HML_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VHML_ResultMatrix,int Row, int VHML_N, int VHML_M)
{
/*
Функция сортирует матрицу по какой-то строке под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные строки являются как бы сопряжеными с данной строкой. То есть элементы в этой строке сортируются,
а все столбцы остаются прежними.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Row - номер сортируемой строки в матрице;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VHML_M-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VHML_ResultMatrix[Row][j]>VHML_ResultMatrix[Row][j+1])
            {
                for (k=0;k<VHML_N;k++)
                    HML_NumberInterchange(&(VHML_ResultMatrix[k][j]),&(VHML_ResultMatrix[k][j+1]));
            }
}