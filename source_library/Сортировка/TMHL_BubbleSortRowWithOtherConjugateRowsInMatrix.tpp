template <class T> void TMHL_BubbleSortRowWithOtherConjugateRowsInMatrix(T **VMHL_ResultMatrix,int Row, int VMHL_N, int VMHL_M)
{
/*
Функция сортирует матрицу по какой-то строке под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные строки являются как бы сопряжеными с данной строкой. То есть элементы в этой строке сортируются,
а все столбцы остаются прежними.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Row - номер сортируемой строки в матрице;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VMHL_M-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VMHL_ResultMatrix[Row][j]>VMHL_ResultMatrix[Row][j+1])
            {
                for (k=0;k<VMHL_N;k++)
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[k][j]),&(VMHL_ResultMatrix[k][j+1]));
            }
}