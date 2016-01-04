double HML_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double))
{
/*
Интегрирование по формуле трапеции с оценкой точности по правилу Рунге.
Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.
Входные параметры:
 a - начало отрезка интегрирования;
 b - конец отрезка интегрирования;
 Epsilon - погрешность;
 Function - подынтегральная функция.
Возвращаемое значение:
 Значение определенного интеграла.
Примечание: значимые цифры в ответе определяются Epsilon.
*/
int i,n;
double h, s1, VHML_Result;
n=1;
h=b-a;
VHML_Result=h*(Function(a)+Function(b))/2.;
do
 {
 s1=VHML_Result;
 VHML_Result=0;
 i=1;
 do
  {
  VHML_Result=VHML_Result+Function(a-h/2.+h*i);//вычисляем интегральную сумму
  i=i+1;
  }
 while (i<=n);
 VHML_Result=s1/2.+VHML_Result*h/2.;
 n=2*n;
 h=h/2.;
 }
while (fabs(VHML_Result-s1)>3.*Epsilon);
return VHML_Result;
}