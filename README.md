## Облегченная версия Экселя
### Описание
Программа для расчета ячеек в таблице (.csv) <br/>
Важно!<br/>
1. Предполагается, что если в ячейке есть расчеты ,то они без пробелов ("=A1 +2+3" - ошибочно, а "=A1+2+3" - правильно).<br/>
2. Если ячейка не используется, то она не меняется и не проверяется на то, является числом или нет.
3. Ячейки считаются слева направо и сверху вниз, поэтому ячейки, которые посчитались раньше можно использовать в ячейках, которые считаются позже
4. Ячейка считается расчётной ячейкой, если первый символ - "="
5. В текущей версии работает корректно для всех операций для A op B (*,/)

### Сборка
1. Используется CMAKE.
2. Для сборки необходимо иметь в PATH бинарники cygwin (C:\cygwin64\bin), так как для сборки используются .DLL и др. 
3. Используется Cygwin 3.4.3.
4. Версия С++ - 17

### Пример использования
Пусть test4.csv:
```
,A,B,Cell
1,  1, 0,1
2, 2,=A1+Cell2,0
30, 0,=B1+A1+A1+A1+Cell30+Cell30,5
```
Тогда
```
simplified_excel.exe tests\test4.csv
```
будет вывод:
```
,A,B,Cell
1,  1, 0,1
2, 2,1.000000,0
30, 0,13.000000,5
```
