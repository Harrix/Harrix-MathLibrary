double MHL_IntegralOfTrapezium(double a, double b, double Epsilon,double (*Function)(double))
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
double h, s1, VMHL_Result;
n=1;
h=b-a;
VMHL_Result=h*(Function(a)+Function(b))/2.;
do
 {
 s1=VMHL_Result;
 VMHL_Result=0;
 i=1;
 do
  {
  VMHL_Result=VMHL_Result+Function(a-h/2.+h*i);//вычисляем интегральную сумму
  i=i+1;
  }
 while (i<=n);
 VMHL_Result=s1/2.+VMHL_Result*h/2.;
 n=2*n;
 h=h/2.;
 }
while (fabs(VMHL_Result-s1)>3.*Epsilon);
return VMHL_Result;
}