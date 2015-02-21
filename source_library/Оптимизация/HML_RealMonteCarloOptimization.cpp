void HML_RealMonteCarloOptimization (double Left, double Right, double (*Function)(double), int Count, double *VHML_Result_X,double *VHML_Result_Y)
{
/*
Метод Монте-Карло (Monte-Carlo). Простейший метод оптимизации для решения задач на вещественных строках. Ищет минимум.
От функции HML_RealMonteCarloAlgorithm отличается тем, что ищет минимум, а не максимум, и не у многомерной функции,
а одномерной. Вводится, чтобы было продолжением однотипных методов оптимизации одномерных унимодальных функций.
Входные параметры:
 Left - начало интервала поиска
 Right - конец интервала поиска
 Function - унимодальная функция, минимум которой ищется
 Count - число вычислений целевой функции
 VHML_Result_X - вычисленная точка минимума (сюда записывается результат);
 VHML_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
int i;
double min,fmin,f,x;
min=HML_RandomUniform(Left,Right);
fmin=Function(min);
for (i=1;i<Count;i++)
 {
 x=HML_RandomUniform(Left,Right);
 f=Function(x);
 if (f<fmin)
  {
  min=x;
  fmin=f;
  }
 }
*VHML_Result_X=min;
*VHML_Result_Y=fmin;
}