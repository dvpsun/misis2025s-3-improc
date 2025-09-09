[//]: # (https://en.wikipedia.org/wiki/SRGB)

References
----------
-   :cite:`InternationalElectrotechnicalCommission1999a` : International
    Electrotechnical Commission. (1999). IEC 61966-2-1:1999 - Multimedia
    systems and equipment - Colour measurement and management - Part 2-1:
    Colour management - Default RGB colour space - sRGB (p. 51).
    https://webstore.iec.ch/publication/6169
-   :cite:`InternationalTelecommunicationUnion2015i` : International
    Telecommunication Union. (2015). Recommendation ITU-R BT.709-6 - Parameter
    values for the HDTV standards for production and international programme
    exchange BT Series Broadcasting service (pp. 1-32).
    https://www.itu.int/dms_pubrec/itu-r/rec/bt/\
R-REC-BT.709-6-201506-I!!PDF-E.pdf
"""

$$equation$$

$$
R= \begin{cases}R^{\prime} / 12.92, & R^{\prime} \leq 0.04045 \\ \left(\frac{R^{\prime}+0.055}{1.055}\right)^{2.4}, & R^{\prime}>0.04045\end{cases}
$$


The inverse function as defined by IEC2003 is:[10]
$$
R^{\prime}= \begin{cases}12.92 R, & R \leq 0.0031308 \\ (1.055) R^{1 / 2.4}-0.055, & R>0.0031308\end{cases}
$$



предложить и согласвать интерфейс
- обсудить, что может пойти не так
- как обрабатываются ошибки
- плюсы и минусы

написать наивную реализацию для 1 канального изображения

сделать комплект тестовых данных и тестов

написать быструю реализацию для 1 канального изображения

написать быструю реализацию для 3 канального изображения