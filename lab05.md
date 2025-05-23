## лабораторная 5

* напишите тестовое консольное приложение task05, которое принимает в качестве параметров командной строки два пути по которым сохраняются тестовое изображение и визуализация результатов обработки тестового изображение 
* тестовое изображение (серое одноканальное 8bpp) состоит из квадратов с кругом в центре каждого из квадратов 
* границы между всеми квадратами и кругами видны, яркость квадрата и круга выбираются из множества $(0, 127, 255)$ так, чтобы все сочетания значений были представлены 
* геометрические размеры:
  * 127 - сторона одного квадрата
  * 40 - радиус круга в центре квадарата
  * $127 \cdot 3$ - ширина тестового изображения 
  * $127 \cdot 2$ - высота тестового изображения 

* $I_1$ - результаты фильтрации тестового изображения линейным фильтром с ядром $M_1$
* $I_2$ - результаты фильтрации тестового изображения линейным фильтром с ядром $M_2$
* $I_3=\sqrt{I_1^2+I_2^2}$
* $V_i$ - визуализация для изображения $I_i, i \in (1,2,3)$
* $V_4$ - RGB-изображение, в котором $V_1$ - R-канал, $V_2$ - G-канал, $V_3$ - B-канал    
* визуализация результатов обработки представляются коллажом вида
``` math
\begin{matrix} V_1 & V_2 \\ V_3 & V_4 \end{matrix} 
```
