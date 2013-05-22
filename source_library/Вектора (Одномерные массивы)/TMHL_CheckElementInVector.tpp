template <class T> int TMHL_CheckElementInVector(T *x, int VMHL_N, T a)
{
/*
Функция проверяет наличие элемента а в векторе x.
Входные параметры:
 x - указатель на вектор;
 VMHL_N - размер массива;
 a - проверяемый элемент.
Возвращаемое значение:
 Номер (начиная с нуля) первого элемента, равного искомому. Если такого элемента нет, то возвращается -1.
*/
int VMHL_Result=-1;
int i=0;
while ((i<VMHL_N)&&(VMHL_Result==-1))
 {
 if (x[i]==a) VMHL_Result=i;//нашли
 i++;
 }
return VMHL_Result;
}