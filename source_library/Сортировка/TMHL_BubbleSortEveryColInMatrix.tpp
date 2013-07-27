template <class T> void TMHL_BubbleSortEveryColInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M)
{
/*
Функция сортирует каждый столбец матрицы в отдельности.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VMHL_M;k++)
    {
        for(i=VMHL_N-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VMHL_ResultMatrix[j][k]>VMHL_ResultMatrix[j+1][k])
                {
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[j][k]),&(VMHL_ResultMatrix[j+1][k]));
                }
    }
}