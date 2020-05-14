Тренировочное задание по программированию: Суммирование матриц

Условие

В этой задаче вам надо разработать класс Matrix для представления целочисленной матрицы. Более подробно класс Matrix должен иметь:

- конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём столбцов
- конструктор от двух целочисленных параметров: num_rows и num_cols, — которые задают количество строк и столбцов матрицы соответственно
- метод Reset, принимающий два целочисленных параметра, которые задают новое количество строк и столбцов матрицы соответственно; метод Reset меняет размеры матрицы на заданные и обнуляет все её элементы
- константный метод At, который принимает номер строки и номер столбца (именно в этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает значение в соответствущей ячейке матрицы
- неконстантный метод At с такими же параметрами, но возвращающий ссылку на значение в соответствущей ячейке матрицы
константные методы GetNumRows и GetNumColumns, которые возвращают количество строк и столбцов матрицы соответственно

Coursera.org Яндекс "Жёлтый пояс по С++"
