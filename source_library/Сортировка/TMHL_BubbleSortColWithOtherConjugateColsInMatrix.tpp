template <class T> void TMHL_BubbleSortColWithOtherConjugateColsInMatrix(T **VMHL_ResultMatrix,int Col, int VMHL_N, int VMHL_M)
{
/*
Функция сортирует матрицу по какому-то столбцу под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные столбцы являются как бы сопряженным с данным столбцом. То есть элементы в этом столбце сортируются,
а все строки остаются прежними.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Col - номер сортируемого столбца в матрице;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VMHL_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VMHL_ResultMatrix[j][Col]>VMHL_ResultMatrix[j+1][Col])
            {
                for (k=0;k<VMHL_M;k++)
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[j][k]),&(VMHL_ResultMatrix[j+1][k]));
            }
}