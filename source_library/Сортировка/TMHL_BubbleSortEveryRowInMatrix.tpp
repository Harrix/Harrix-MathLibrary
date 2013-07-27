template <class T> void TMHL_BubbleSortEveryRowInMatrix(T **VMHL_ResultMatrix,int VMHL_N, int VMHL_M)
{
/*
Функция сортирует каждую строку матрицы в отдельности.
Входные параметры:
 VMHL_ResultMatrix - указатель на матрицу, которую будем сортировать;
 VMHL_N - количество строк в матрице;
 VMHL_M - количество столбцов в матрице.
Выходной параметр:
 Отсутствует.
*/
    int i,j,k;
    for (k=0;k<VMHL_N;k++)
    {
        for(i=VMHL_M-1;i>0;i--)
            for(j=0;j<i;j++)
                if(VMHL_ResultMatrix[k][j]>VMHL_ResultMatrix[k][j+1])
                {
                    TMHL_NumberInterchange(&(VMHL_ResultMatrix[k][j]),&(VMHL_ResultMatrix[k][j+1]));
                }
    }
}