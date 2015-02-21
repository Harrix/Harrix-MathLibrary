template <class T> int HML_CheckElementInVector(T *x, int VHML_N, T a)
{
/*
Функция проверяет наличие элемента а в векторе x.
Входные параметры:
 x - указатель на вектор;
 VHML_N - размер массива;
 a - проверяемый элемент.
Возвращаемое значение:
 Номер (начиная с нуля) первого элемента, равного искомому. Если такого элемента нет, то возвращается -1.
*/
int VHML_Result=-1;
int i=0;
while ((i<VHML_N)&&(VHML_Result==-1))
 {
 if (x[i]==a) VHML_Result=i;//нашли
 i++;
 }
return VHML_Result;
}