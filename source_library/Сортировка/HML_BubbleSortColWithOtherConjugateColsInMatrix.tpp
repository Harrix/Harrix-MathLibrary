template <class T> void HML_BubbleSortColWithOtherConjugateColsInMatrix(T **VHML_ResultMatrix,int Col, int VHML_N, int VHML_M)
{
/*
Функция сортирует матрицу по какому-то столбцу под номером в порядке возрастания методом "Сортировка пузырьком".
При этом все остальные столбцы являются как бы сопряженным с данным столбцом. То есть элементы в этом столбце сортируются,
а все строки остаются прежними.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 Col - номер сортируемого столбца в матрице;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for(i=VHML_N-1;i>0;i--)
        for(j=0;j<i;j++)
            if(VHML_ResultMatrix[j][Col]>VHML_ResultMatrix[j+1][Col])
            {
                for (k=0;k<VHML_M;k++)
                    HML_NumberInterchange(&(VHML_ResultMatrix[j][k]),&(VHML_ResultMatrix[j+1][k]));
            }
}