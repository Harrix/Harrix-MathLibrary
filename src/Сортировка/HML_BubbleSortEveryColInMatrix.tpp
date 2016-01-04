template <class T> void HML_BubbleSortEveryColInMatrix(T **VHML_ResultMatrix,int VHML_N, int VHML_M)
{
/*
Функция сортирует каждый столбец матрицы в отдельности.
Входные параметры:
 VHML_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VHML_N - количество строк в матрице;
 VHML_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VHML_M;k++)
    {
        for(i=VHML_N-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VHML_ResultMatrix[j][k]>VHML_ResultMatrix[j+1][k])
                {
                    HML_NumberInterchange(&(VHML_ResultMatrix[j][k]),&(VHML_ResultMatrix[j+1][k]));
                }
    }
}