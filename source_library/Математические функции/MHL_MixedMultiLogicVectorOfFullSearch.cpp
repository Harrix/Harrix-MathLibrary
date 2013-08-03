void MHL_MixedMultiLogicVectorOfFullSearch(int *VMHL_Vector, int I, int *HowMuchInElements, int VMHL_N)
{
/*
Функция генерирует определенный вектор k-значной логики, где каждый элемент может
принимать разное максимальное значение, в полном переборе вариантов.
Генерируется I вектор в этом полном переборе.
Входные параметры:
 VMHL_Vector - выходной вектор, в который записывется результат;
 I - номер в массиве в полном переборе, начиная с нуля (от 0 и до произведения всех элементов массива HowMuchInElements - 1);
 HowMuchInElements - сколько значений может принимать элемент в векторе. То есть элемент может быть 0 и HowMuchInElements[i] - 1;
 VMHL_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
    int *CountInBlock = new int[VMHL_N];

    int CountOfAllVariants = TMHL_ProductOfElementsOfVector(HowMuchInElements, VMHL_N);

    CountInBlock[0] = CountOfAllVariants/HowMuchInElements[0];

    for (int i=1;i<VMHL_N;i++)
        CountInBlock[i] = CountInBlock[i-1]/HowMuchInElements[i];

    for (int i=0;i<VMHL_N;i++)
        VMHL_Vector[i] = (I/CountInBlock[i])%HowMuchInElements[i];

    delete [] CountInBlock;
}