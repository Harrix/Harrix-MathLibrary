void MHL_MakingVectorForNonparametricEstimatorOfDerivative3(double *VMHL_ResultVector, double *X, double *Y, int VMHL_N, double C, int V)
{
/*
Создание вектор непараметрической оценки производной в точках выборках. Служебная функция.
Нужна для функции MHL_NonparametricEstimatorOfDerivative3.
Входные параметры:
 VMHL_ResultVector - сюда сохраняется результат (количество элементов, как и в других векторах VMHL_N);
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VMHL_N - размер выборки;
 C - коэффициент размытости;
 V - тип ядра
  0 - прямоугольное (не рекомендуется);
  1 - треугольное;
  2 - параболическое (считается оптимальным);
  3 - экспоненциальное.
Возвращаемое значение:
 Отсутствует.
*/
    bool b2;
    for (int i=0;i<VMHL_N;i++)
     {
     //непараметрическая оценка производной
     VMHL_ResultVector[i]=MHL_NonparametricEstimatorOfDerivative(X[i], X, Y, VMHL_N, C, V, &b2);
     }
}