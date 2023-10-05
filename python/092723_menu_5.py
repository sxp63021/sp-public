#!/usr/bin/python
 
def math_menu():
    while True:
        print ("\n" * 200)
        print ("What type is your question?")
        print ("\n" * 3)
        print ("[1]:Bisquared-equasion")
        print ("[2]:Exit")
        print ("\n")
        menu = int(input(": "))
        if menu == 1:
            bisquared()
        elif menu == 2:
            break
 
while True:
    print ("\n" * 200)
    print ("Welcome,what would you like to do?type the number")
    print ("\n")
    print ("[1]:Math solver")
    print ("[2]:exit")
    print ("\n")
    menu = int(input(": "))
    if menu == 1:
        math_menu()
    elif menu == 2:
        break
