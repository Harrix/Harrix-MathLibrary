int MHL_SeparateVectorLimitOnProductElementsTwo(int *VMHL_Vector, int *Order, int Limit, int VMHL_N)
{
    /*
Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit.
Алгоритм в данной функции немного другой, чем в функции MHL_SeparateVectorLimitOnProductElements.
Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VMHL_N) с количеством элементов,
равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов
было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе.
Задача возникла при построении таблицы, в которой надо показать все возможные комбинации (поэтому и произведение
учитывается), когда из каждой группы берем по одному элементу, а по горизонтали слишком много элементов не расставим.
Входные параметры:
 VMHL_Vector - указатель на вектор, в котором хранится количество элементов в каждой группе (все должн быть положительны);
 Order - массив, в котором сохраняется новый порядок элементов. То есть это строка перестановка, где значение элемента
 говорит, что на этой позиции должен находится соответствующая группа из VMHL_Vector.
 Limit - какое максимальное произведение элементов должно быть в первой группе.
 VMHL_N - размер массива VMHL_Vector и Order.
Возвращаемое значение:
 Количество первых элементов в Order, которые относятся к первой группировке групп.
 Если это невозможно, то возвращается -1 (в случае, если минимальный элемент).
Примечание. Да, функция специфическая.
*/
    int VMHL_Result=-1;
    int *VMHL_VectorTemp = new int[VMHL_N];//временная копия массива
    int *VMHL_NumberTemp = new int[VMHL_N];//тут номера элементов будем хранить
    TMHL_VectorToVector(VMHL_Vector,VMHL_VectorTemp,VMHL_N);
    TMHL_ZeroVector(Order,VMHL_N);
    TMHL_OrdinalVectorZero(VMHL_NumberTemp,VMHL_N);

    //Отсортируем массив
    TMHL_BubbleSortWithConjugateVector(VMHL_VectorTemp, VMHL_NumberTemp, VMHL_N);
    TMHL_ReverseVector(VMHL_VectorTemp,VMHL_N);
    TMHL_ReverseVector(VMHL_NumberTemp,VMHL_N);
    //скопируем в итоговый массив Order
    TMHL_VectorToVector(VMHL_NumberTemp,Order,VMHL_N);

    if (VMHL_VectorTemp[VMHL_N-1]>Limit)
    {
        VMHL_Result=-1;
    }
    else
    {
        if (VMHL_VectorTemp[0]>Limit)
        {
           while (VMHL_VectorTemp[0]>Limit)
           {
               TMHL_ShiftLeftVector(VMHL_VectorTemp,VMHL_N);
               TMHL_ShiftLeftVector(VMHL_NumberTemp,VMHL_N);
               TMHL_ShiftLeftVector(Order,VMHL_N);
           }
        }

        int p=1;
        int pTemp;
        int num=0;
        for (int i=0;i<VMHL_N;i++)
        {
          pTemp=p*VMHL_Vector[i];
          if (pTemp>Limit)
          {
            break;
          }
          else
          {
              p=pTemp;
              num=i;
          }
        }
        VMHL_Result=num+1;
    }

    delete [] VMHL_VectorTemp;
    delete [] VMHL_NumberTemp;
    return VMHL_Result;
}