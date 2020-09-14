#### ICS期中考试

##### 2.为什么要用IR

##### 3.x40000001 不能用IEEE表示

​	fraction part ->23bit

##### 4.A = x30，B = x12，C -> 6bit,溢出？

##### 5.证明逻辑完备性 -> 证明or and not都能用f1，f2表示

| A    | B    | f1   | f2   |
| ---- | ---- | ---- | ---- |
| 0    | 0    | 1    | 0    |
| 0    | 1    | 1    | 0    |
| 1    | 0    | 0    | 1    |
| 1    | 1    | 0    | 0    |

f1(A,B) = notA

f2(A,B) = A and (notB)

not(A) = f1(A,A)

and(A,B) = A and (not (not B)) = f2(A,f1(B,B))

or(A,B) = ... = f1(f2(f1(A,A),B),f2(f1(A,A),B))

##### 6.（他不让画使能）

<img src="C:\Users\gaochuqing\Documents\Tencent Files\1141892453\FileRecv\MobileFile\IMG_20191113_142403.jpg" style="zoom: 50%;" />

##### 7.

<img src="C:\Users\gaochuqing\Documents\Tencent Files\1141892453\FileRecv\MobileFile\qq_pic_merged_1573626948169.jpg" style="zoom:33%;" />



*CMOS管上下具有对称性，上面是并联，下面就是串联，对应的元素也相同，但是这样只是其中一种解法*

##### 8.不管正负做乘法

