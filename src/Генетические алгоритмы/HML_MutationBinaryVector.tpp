template <class T> void HML_MutationBinaryVector(T *VHML_ResultVector, double ProbabilityOfMutation, int VHML_N)
{
/*
Мутация для бинарного вектора. Оператор генетического алгоритма.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый вектор;
 ProbabilityOfMutation - вероятность мутации;
 VHML_N - размер массива VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
    ProbabilityOfMutation = HML_AcceptanceLimitsNumber(ProbabilityOfMutation,0.,1.);

    for(int i=0;i<VHML_N;i++)
        if (HML_RandomNumber()<ProbabilityOfMutation)
        {
            //Инвертируем ген
            if (VHML_ResultVector[i]==0) VHML_ResultVector[i]=1; else VHML_ResultVector[i]=0;
        }
}