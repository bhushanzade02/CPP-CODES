Ax = []
Ay = []

n = int(input("enter the value of n"))

for i in range(n):
    values = input().split()
    a = float(values[0])
    b = float(values[1])
    Ax.append(a)  
    Ay.append(b)  

x = int(input("enter the value for you want to calculate"))

for i in range(n):
    print(Ax)

for i in range(n):
    print("Ay",Ay)
y= 1

for i in range(n):
    nr = dr = 1
    for j in range(n):
        if i != j :
            nr *= x - Ax[j]
            dr *= Ax[i] - Ax[j]
    y += (nr/dr) * Ay[i]

print(f"when x = {x} then y =  {y}")



