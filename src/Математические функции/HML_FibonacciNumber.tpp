template <class T> T HML_FibonacciNumber(T n)
{
/*
Функция вычисляет число Фибоначчи, заданного номера.
Входные параметры:
 n - номер числа Фибоначчи.
Возвращаемое значение:
 Число Фибоначчи, заданного номера.
*/
T F1,F2,VHML_Result;

if (n==0) return 0;

if (n>=1)//иницилизация
 {
 VHML_Result=1;
 F1=1;
 }

if (n>=2) F2=1;

if (n>2)
 {
 for (int i=2;i<n;i++)
  {
  VHML_Result=F1+F2;//итерационное складывание
  F1=F2;
  F2=VHML_Result;
  }
 }

return VHML_Result;
}