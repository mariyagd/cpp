### Tests all lines in input files are invalid

- before epoch time
- day in future
- year, month, day or rate is null
- year, month, day or rate is negative
- invalid month (more than 12)
- invalid days (more than 32)
- test 29 days in February when year is not a leap year
- test 31 days in months that have 30 days
- test invalid inputs
- test invalid rate

```c++
date | value
1969-12-31 | 2
1970-01-01 | 3

2025-01-03 | 1

2025-00-03 | 1
2025-05-00 | 1
0000-05-10 | 1
2015-05-10 | 1

2011--01-09 | 1
2011-01--09 | 1
-1999-09-12 | 1
1999-09-12 | -1

2011-25-03 | 1.2
2011-06-32 | 1.2

2001-02-29 | 21
2019-02-29 | 21
2018-02-29 | 21

2014-06-31 | 21
2013-04-31 | 21
2005-09-31 | 21

201a2-01-11 | -1
2001-42-42
2001-42-42  1
1970-01-02  |  3
| 2012-01-11 | 1|
2012-01-11 || 1
2000-01-01 | | 100
2012-09-30 | 252.10.56

2023-12-9 | 225a1
2015-05-09 | 22-51
2015-05-09 | -235
2015-05-09 | 1001
2015-05-09 | 1000.1
2015-05-09 | ++1000
```

### Tests all lines in input files are valid

- Test after epoch time
- Test months with 31 days
- Test days in february on leap and not leap year
- Test positive value with signe '+'

```c++
date | value
1970-01-02 | 3
2012-07-31 | 21
2020-02-29 | 21
2023-02-29 | 21
2016-02-29 | 21
2004-05-09 | +221
```