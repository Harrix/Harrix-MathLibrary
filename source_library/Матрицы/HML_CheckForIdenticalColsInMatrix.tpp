template <class T> bool HML_CheckForIdenticalColsInMatrix(T **VHML_ResultMatrix, int VHML_N, int VHML_M)
{
    /*
Функция проверяет наличие одинаковых столбцов в матрице.
Входные параметры:
 VHML_ResultMatrix - указатель на массив;
 VHML_N - размер массива VHML_ResultMatrix (число строк);
 VHML_M - размер массива VHML_ResultMatrix (число столбцов);
Возвращаемое значение:
 true - если есть одинаковые столбцы;
 false - если таких столбцы нет.
*/
    bool VHML_Result=false;
    bool b;
    for (int i=0;i<VHML_M;i++)
        for (int ii=0;ii<VHML_M;ii++)
        {
            if (ii!=i)
            {
            b=true;
            for (int j=0;j<VHML_N;j++)
            {
                if (VHML_ResultMatrix[j][i]!=VHML_ResultMatrix[j][ii]) b=false;
            }
            if (b) VHML_Result=true;
            }
        }
    return VHML_Result;
}