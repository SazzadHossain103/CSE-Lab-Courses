# 1. make a calculator using python
# Ans: ID-1103

# print("Enter 2 numbers: ")
# a = int(input())
# b = int(input())
# operator = input("Enter calculate operator: ")
# if(operator=="+"): 
#   print(a+b)
# elif(operator=="-"): 
#   print(a-b)
# elif(operator=="*"): 
#   print(a*b)
# elif(operator=="/"): 
#   print(round((a/b),2))
# elif(operator=="%"): 
#   print(a%b)

number1 = float(input("enter 1st number: "))
number2 = float(input("enter 2nd number: "))
op =input("Enter operator: ")
if op =='+':
    result = number1 + number2
elif op=='-':
    result = number1 - number2
elif op=='*':
    result = number1 * number2
elif op=='/':
    if number2 !=0:
      result = number1 / number2
    else:
      result = "MATH ERROR"
else:
   result = "Invalid!"
print("Result: ", result)