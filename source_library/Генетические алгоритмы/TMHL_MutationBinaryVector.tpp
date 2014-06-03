template <class T> void TMHL_MutationBinaryVector(T *VMHL_ResultVector, double ProbabilityOfMutation, int VMHL_N)
{
/*
Мутация для бинарного вектора. Оператор генетического алгоритма.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый вектор;
 ProbabilityOfMutation - вероятность мутации;
 VMHL_N - размер массива VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
    ProbabilityOfMutation = TMHL_AcceptanceLimitsNumber(ProbabilityOfMutation,0.,1.);

    for(int i=0;i<VMHL_N;i++)
        if (MHL_RandomNumber()<ProbabilityOfMutation)
        {
            //Инвертируем ген
            if (VMHL_ResultVector[i]==0) VMHL_ResultVector[i]=1; else VMHL_ResultVector[i]=0;
        }
}