# Data structures project 1

---

Implemented 5 sorting algorithms: **Radixsort**(base 10 and base 256), **Shellsort**, **Mergesort**, **Quicksort** and **Countsort**.

Compared them with C++ sorting algorithm (**Introsort**).

Made in python graphics which shows their complexity and how the maximum value and the vector size affects time efficiency.

---

A series of 5 photos will follow to show how the maximum value plays a role in time efficiency in sorting algorithms.

![](stats/Sortari0.png)
![](stats/Sortari3.png)
![](stats/Sortari5.png)
![](stats/Sortari6.png)
![](stats/Sortari7.png)

Until 10^8 maximum value, **Countsort** displays a good efficiency. Afterwards, **Radixsort** in base 256 is the most efficient.

---

## Countsort 
(O(N+K), N - number of elements, K - range of the elements)

Good sorting algorithm if the range of the elements is small(10^8).

![Countsort](stats/countsort.png "Countsort")

---

## Radixsort 

(O(ND), N - number of elements, D - number of digits in the largest number)

Best sorting algorithm for natural numbers if it is used in base 256(Following example!)

![Radixsort](stats/radixsort.png "Radixsort")

---

## Radixsort (base 256)

(O(N log<sub>256</sub> N), N - number of elements)

![Radixsort256](stats/radixsort256.png "Radixsort256")

---

## Shellsort

(O(N log N), N - number of elements)

![Shellsort](stats/shellsort.png "Shellsort")

---

## Mergesort

(O(N log N), N - number of elements)

![Mergesort](stats/mergesort.png "Mergesort")

## Quicksort

(O(N log N), N - number of elements)

![Quicksort](stats/quicksort.png "Quicksort")

---

## End

In the end, I want to emphasise how maximum value and array sizes affect time efficiency by showcasing an exception(**all values of the array are equal to 1**)

![](https://github.com/GFA03/sd-sortari/blob/main/stats%20max%20value%20%3D%201/Sortari.png)
