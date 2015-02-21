void HML_MakingVectorForNonparametricEstimatorOfDerivative6(double *VHML_ResultVector, double *X, double *Y, int VHML_N, double C, int V)
{
/*
Создание вектор непараметрической оценки производной в точках выборках. Служебная функция.
Нужна для функции HML_NonparametricEstimatorOfDerivative6.
Входные параметры:
 VHML_ResultVector - сюда сохраняется результат (количество элементов, как и в других векторах VHML_N);
 X - выборка: значения входов;
 Y - выборка: соответствующие значения выходов;
 VHML_N - размер выборки;
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
    for (int i=0;i<VHML_N;i++)
     {
     //непараметрическая оценка производной
     VHML_ResultVector[i]=HML_NonparametricEstimatorOfDerivative5(X[i], X, Y, VHML_N, C, V, &b2);
     }
}