void HML_RandomVectorOfProbability(double *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет вектор случайными значениями вероятностей. Сумма всех элементов вектора равна 1.
Входные параметры:
 VHML_ResultVector - указатель на вектор вероятностей (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 VHML_ResultVector[i]=HML_RandomNumber();
//Вычислим сумму вектора
double sum=HML_SumVector(VHML_ResultVector,VHML_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1./double(VHML_N);
 }
else
 {
 //Нормализуем
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]/=sum;
 }
}