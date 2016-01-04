void HML_FibonacciOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод Фибоначчи. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Count - число вычислений целевой функции;
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение: 
 Отсутствует.
*/
double l,v,fl,fv,Fib1,Fib2;
int i=1,n;
n=Count-1;

Fib1=HML_FibonacciNumber(n-i-1);
Fib2=HML_FibonacciNumber(n-i+1);
l=Left+(Fib1/Fib2)*(Right-Left);

Fib1=HML_FibonacciNumber(n-i  );
Fib2=HML_FibonacciNumber(n-i+1);
v=Left+(Fib1/Fib2)*(Right-Left);

fl=Function(l);
fv=Function(v);
for (i=2;i<n;i++)
 {
 if (Function(l)<Function(v))
  {
  Right=v;
  v=l;
  fv=fl;

  Fib1=HML_FibonacciNumber(n-i-1);
  Fib2=HML_FibonacciNumber(n-i+1);
  l=Left+(Fib1/Fib2)*(Right-Left);

  fl=Function(l);
  }
 else
  {
  Left=l;
  l=v;
  fl=fv;

  Fib1=HML_FibonacciNumber(n-i  );
  Fib2=HML_FibonacciNumber(n-i+1);
  v=Left+(Fib1/Fib2)*(Right-Left);

  fv=Function(v);
  }
 }
*VHML_Result_X=(Left+Right)/2.;
*VHML_Result_Y=Function(*VHML_Result_X);
}