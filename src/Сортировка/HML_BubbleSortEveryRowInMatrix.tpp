template <class T> void HML_BubbleSortEveryRowInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M)
{
/*
Функция сортирует каждую строку матрицы в отдельности.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VHML_N;k++)
    {
        for(i=VHML_M-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VHML_ResultMatrix[k][j]>VHML_ResultMatrix[k][j+1])
                {
                    HML_NumberInterchange(&(VHML_ResultMatrix[k][j]),&(VHML_ResultMatrix[k][j+1]));
                }
    }
}