HarrixMathLibrary
=================

Версия 3.62

Сборник различных математических функций и шаблонов с открытым кодом на языке C++. Упор делается на алгоритмы искусственного интеллекта. Используется только C++.

https://github.com/Harrix/HarrixMathLibrary

Библиотека распространяется по лицензии [Apache License, Version 2.0](../master/LICENSE.txt).

Для справки по установке, использованию и всем функциям перейдите в папку [**_library**](../master/_library) и откройте файл [**HarrixMathLibrary_Help.pdf**](../master/_library/HarrixMathLibrary_Help.pdf). Там же находятся файлы последней версии библиотеки.

Установка
---------

Прочитать подробно об установке можно тут http://blog.harrix.org/?p=1252.
Точнее о том как найти документацию в виде файла [**HarrixMathLibrary_Help.pdf**](../master/_library/HarrixMathLibrary_Help.pdf) и как настроить программы для работы с библиотекой).

Структура папок на GitHub
-------------------------

В проекте https://github.com/Harrix/HarrixMathLibrary имеются следущие папки и файлы:

 * [**_library**](../master/_library) - непосредственно сама библиотека. В папке содержится последний билд библиотеки.
 * [**demo**](../master/demo) - папка с программой [DemoHarrixMathLibrary.exe](../master/demo/DemoHarrixMathLibrary.exe), демонстрирующей работу функций библиотеки.
 * [**make**](../master/make) - папка с программой [MakeHarrixMathLibrary.exe](../master/make/MakeHarrixMathLibrary.exe), которая формирует из исходников в папке source_library библиотеку и справку к ней.
 * [**source_demo**](../master/source_demo) - папка с исходным текстом программы [DemoHarrixMathLibrary.exe](../master/demo/DemoHarrixMathLibrary.exe).
 * [**source_library**](../master/source_library) - папка с исходным текстом библиотеки, который потом собирается программой [MakeHarrixMathLibrary.exe](../master/make/MakeHarrixMathLibrary.exe) из папки [make](../master/make).
 * [**source_make**](../master/source_make) - папка с исходным текстом [MakeHarrixMathLibrary.exe](../master/make/MakeHarrixMathLibrary.exe) и справки по ней.
 * [**LICENSE.txt**](../master/LICENSE.txt), [**NOTICE.txt**](../master/NOTICE.txt)**** - файлы лицензии Apache License, Version 2.0.
 * [**README.md**](../master/README.md) - непосредственно этот файл.
 * [**images**](../master/images) - в папке находятся служебные рисунки для отображения в этом файле.
 
Сведения для редактирования файлов
----------------------------------

Для полноценной работы редактированию LaTeX документами вам потребуются программа для компиляции \*.tex документов в \*.pdf. Автор использует для этого связку [MiKTex](http://www.miktex.org/) и [TeXstudio](http://texstudio.sourceforge.net/). 

В варианте, который использует автор, в \*.tex файлах справок для отображения русских букв используется модуль pscyr. Об его установке можно прочитать (и скачать) в статье http://blog.harrix.org/?p=444.

Подробное описание установки и настройки связки MiKTeX + TeXstudio + pscyr можно прочитать в статье http://blog.harrix.org/?p=849.

Скриншот демонстрационной программы
------------------------------------

![alt text](../master/images/demo.png "Пример работы программы демонстрации")

Использованные технологии
-------------------------

- [LaTeX](http://ru.wikipedia.org/wiki/LaTeX), [Qt](http://qt-project.org/), [MiKTeX](http://miktex.org/), [BiBTex](http://ru.wikipedia.org/wiki/BibTeX), [TeXstudio](http://texstudio.sourceforge.net/), [PSCyr](http://blog.harrix.org/?p=444), [pgfplots](http://pgfplots.sourceforge.net/), [JSXGraph](https://github.com/jsxgraph/jsxgraph), [Html](http://ru.wikipedia.org/wiki/HTML), [AJAX](http://ru.wikipedia.org/wiki/AJAX), [jQuery](http://jquery.com/), [QWebView](http://qt-project.org/doc/qt-5/qwebview.html).
- [HarrixMathLibrary](https://github.com/Harrix/HarrixMathLibrary), [HarrixQtLibrary](https://github.com/Harrix/HarrixQtLibrary), [HarrixLaTeXDocumentTemplate](https://github.com/Harrix/HarrixLaTeXDocumentTemplate).
 
История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](../master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу sergienkoanton@mail.ru или  http://vk.com/harrix.

Сайт автора, где публикуются последние новости: http://blog.harrix.org, а проекты располагаются по адресу: http://harrix.org.