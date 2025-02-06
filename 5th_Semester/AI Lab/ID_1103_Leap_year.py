# 2. Find if a year is leap year or not using python
# Ans: ID-1103

year = int(input("Enter Year: "))
if((year%4==0 and year%100!=0) or year%400==0):
  print("Leap Year")
else:
  print("Not Leap Year")