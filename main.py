from sympy import symbols, solve

x, y, ax, ay, ar, bx, by, br, cx, cy, cr = symbols('x y ax ay ar bx by br cx cy cr')

# A(0,6)
ax = 0
ay = 6
ar = 5

# B(8,14)
bx = 8
by = 14
br = 13

# C(9,-6)
cx = 9
cy = -6
cr = 10

eq1 = (((x - ax)**2) + ((y - ay)**2)) - ar**2
eq2 = (((x - bx)**2) + ((y - by)**2)) - br**2
eq3 = (((x - cx)**2) + ((y - cy)**2)) - cr**2

# Solve the system
solutions = solve([eq1, eq2, eq3], (x, y), dict=True)
print(solutions)
