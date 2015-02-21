int HML_SeparateVectorLimitOnProductElements(int *VHML_Vector, int *Order, int Limit, int VHML_N)
{
    /*
Функция перегрупирует элементы массива так, чтобы произведение элементов в начале вектора было не больше Limit.
Для чего вообще функция нужна? У нас имеется несколько групп (в количестве VHML_N) с количеством элементов,
равных числу из вектора. Нужно разделить группы на две группы так, чтобы в одной из них произведение количеств элементов
было не больше Limit. При этом в Order сохраняем порядок элементов, а возвращаем количество элементов в первой подгруппе.
Задача возникла при построении таблицы, в которой надо показать все возможные комбинации (поэтому и произведение
учитывается), когда из каждой группы берем по одному элементу, а по горизонтали слишком много элементов не расставим.
Входные параметры:
 VHML_Vector - указатель на вектор, в котором хранится количество элементов в каждой группе (все должн быть положительны);
 Order - массив, в котором сохраняется новый порядок элементов. То есть это строка перестановка, где значение элемента
 говорит, что на этой позиции должен находится соответствующая группа из VHML_Vector.
 Limit - какое максимальное произведение элементов должно быть в первой группе.
 VHML_N - размер массива VHML_Vector и Order.
Возвращаемое значение:
 Количество первых элементов в Order, которые относятся к первой группировке групп.
 Если это невозможно, то возвращается -1 (в случае, если минимальный элемент).
Примечание. Да, функция специфическая.
*/
    int VHML_Result=-1;
    int *VHML_VectorTemp = new int[VHML_N];//временная копия массива
    int *VHML_NumberTemp = new int[VHML_N];//тут номера элементов будем хранить
    HML_VectorToVector(VHML_Vector,VHML_VectorTemp,VHML_N);
    HML_ZeroVector(Order,VHML_N);
    HML_OrdinalVectorZero(VHML_NumberTemp,VHML_N);

    //Отсортируем массив
    HML_BubbleSortWithConjugateVector(VHML_VectorTemp, VHML_NumberTemp, VHML_N);
    //скопируем в итоговый массив Order
    HML_VectorToVector(VHML_NumberTemp,Order,VHML_N);

    if (VHML_VectorTemp[0]>Limit)
    {
        VHML_Result=-1;
    }
    else
    {
        int p=1;
        int pTemp;
        int num=0;
        for (int i=0;i<VHML_N;i++)
        {
          pTemp=p*VHML_Vector[i];
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
        VHML_Result=num+1;
    }

    delete [] VHML_VectorTemp;
    delete [] VHML_NumberTemp;
    return VHML_Result;
}